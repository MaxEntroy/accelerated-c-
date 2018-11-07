/*************************************************************************
    > File Name: main.cpp
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年11月29日 星期三 09时19分26秒
 ************************************************************************/
#include <vector>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <ios>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Student/StudentInfo.h"
#include "grade/grade.h"

int main( int argc, char* argv[] ) {

	if( argc != 2 ) {
		std::cerr << "Usage: argv[1] is input path." << std::endl;
		return -1;
	}

	std::vector<StudentInfo> vec_stu;

	std::ifstream fin;
	fin.open( argv[1] );
	if( !fin.is_open() ) {
		std::cerr << "Can not open the file!" << std::endl;
		return -1;
	}

	int maxlen = -1;
	StudentInfo s;
	while( read_stu( fin, s ) ) {
		vec_stu.push_back(s);
		int name_sz = s.name.size();
		maxlen = (name_sz > maxlen)?name_sz:maxlen;
	}

	std::sort( vec_stu.begin(), vec_stu.end(), compare );

	try {
		std::streamsize prec = std::cout.precision();
		std::cout << std::setprecision(3);
		int sz = vec_stu.size();
		for( int i = 0; i < sz; ++i ) {
			double total = grade( vec_stu[i].mid, vec_stu[i].fin, vec_stu[i].hw );
			std::string space(maxlen - vec_stu[i].name.size() + 1, ' ');
			std::cout << vec_stu[i].name << space << total << std::endl;
		}
		std::cout << std::setprecision(prec);
	}
	catch( std::domain_error e ) {
		std::cerr << e.what();
		fin.close();
		return -1;
	}

	fin.close();
	return 0;
}
