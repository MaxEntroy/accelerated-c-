/*************************************************************************
    > File Name: main.cc
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2018年03月17日 星期六 23时42分24秒
 ************************************************************************/
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include "student/StudentInfo.h"
#include "grade/grade.h"

using namespace stugrade;

int main( int argc, char* argv[] ) {
	
	if( argc < 2 ) {
		std::cerr << "Usage: \nargv[1]: input path!\n";
		return 1;
	}

	std::vector<StudentInfo> did, didnt;
	StudentInfo s;

	// open file
	std::ifstream fin;
	fin.open( argv[1] );
	if( !fin.is_open() ) {
		std::cerr << "[INFO]: open file failure!\n";
		return 1;
	}

	// read student grade
	while( read_stu( fin, s ) ) {
		/*
		double total = grade(s);
		std::streamsize prec = std::cout.precision();
		std::cout << s.name << "\t" << std::setprecision(3) << total << std::setprecision(prec) << std::endl;
		*/
		if( did_all_hw(s) ) 
			did.push_back(s);
		else
			didnt.push_back(s);
	}

	// grade analysis
	if( did.empty() ) {
		std::cout << "No one did all homework!" << std::endl;
	}
	else{
	}

	if( didnt.empty() ) {
		std::cout << "Everyone did all homework" << std::endl;
	}
	else{
	}

	// close file
	fin.close();
	return 0;
}
