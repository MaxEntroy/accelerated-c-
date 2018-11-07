/*************************************************************************
    > File Name: main.cc
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年12月01日 星期五 15时55分11秒
 ************************************************************************/
#include <iostream>
#include <list>
#include <fstream>
#include <ios>
#include <iomanip>
#include <stdexcept>
#include "student/StudentInfo.h"
#include "grade/grade.h"

void extract_fails( std::list<StudentInfo>& stu, std::list<StudentInfo>& fails );

typedef std::list<StudentInfo>::iterator iter;

int main( int argc, char* argv[1] ) {
	
	if( argc != 2 ) {
		std::cerr << "Usage: argv[1] is input path!" << std::endl;
		return -1;
	}

	std::ifstream fin;
	fin.open( argv[1] );
	if( !fin.is_open() ) {
		std::cerr << "Invalid input path!" << std::endl;
		return -1;
	}

	std::list<StudentInfo> list_stu;
	StudentInfo s;
	int maxlen = -1;
	while( read_stu( fin, s ) ) {
		list_stu.push_back(s);
		int name_sz = s.name.size();
		maxlen = (name_sz > maxlen)?name_sz:maxlen;
	}

	std::list<StudentInfo> list_fails;
	try {
		
		extract_fails( list_stu, list_fails );
		list_stu.sort(compare);
		list_fails.sort(compare);

		std::streamsize prec = std::cout.precision();
		std::cout << std::setprecision(3);
		
		std::cout << "Students who pass the exam are as follows: " << std::endl;
		iter b = list_stu.begin();
		iter e = list_stu.end();
		while( b != e) {
			std::string space( maxlen + 1 - b->name.size(), ' ' );
			double total = grade(b->mid, b->fin, b->hw);
			std::cout << b->name << space << total << std::endl;
			++b;
		}

		std::cout << "Students who do not pass the exam are as follows: " << std::endl;
		b = list_fails.begin();
		e = list_fails.end();
		while( b != e) {
			std::string space( maxlen + 1 - b->name.size(), ' ' );
			double total = grade(b->mid, b->fin, b->hw);
			std::cout << b->name << space << total << std::endl;
			++b;
		}

		std::cout << std::setprecision(prec);
	}
	catch( std::domain_error e ) {
		std::cerr << e.what() << std::endl;
		fin.close();
		return -1;
	}

	fin.close();
	return 0;
}

void extract_fails( std::list<StudentInfo>& stu, std::list<StudentInfo>& fails ) {
	if( !stu.size() )
		throw std::domain_error( "Empty stu" );
	
	iter b = stu.begin();
	while( b != stu.end()) {
		if( fgrade(*b) ) {
			fails.push_back(*b);
			b = stu.erase(b);
		}
		else
			++b;
	}

	return;
}
