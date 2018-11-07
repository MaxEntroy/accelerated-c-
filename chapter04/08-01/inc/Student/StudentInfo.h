/*************************************************************************
    > File Name: StudentInfo.h
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年11月29日 星期三 10时46分03秒
 ************************************************************************/
#ifndef STUDENT_INFO_H_
#define STUDENT_INFO_H_
#include <string>
#include <vector>
#include <istream>

struct StudentInfo {
	std::string name;
	double mid;
	double fin;
	std::vector<double> hw;
	StudentInfo() : mid(0.0), fin(0.0) {}
};

bool compare( const StudentInfo&, const StudentInfo& );
std::istream& read_stu( std::istream&, StudentInfo& );
std::istream& read_stu_hw( std::istream&, std::vector<double>& );

#endif
