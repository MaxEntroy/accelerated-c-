/*************************************************************************
    > File Name: StudentInfo.h
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年12月01日 星期五 16时03分45秒
 ************************************************************************/
#ifndef STUDENTINFO_H_
#define STUDENTINFO_H_
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

std::istream& read_stu( std::istream& is, StudentInfo& s );
std::istream& read_stu_hw( std::istream& is, std::vector<double>& hw );
bool compare( const StudentInfo&, const StudentInfo& );

#endif
