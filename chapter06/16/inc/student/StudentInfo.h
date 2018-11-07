/*************************************************************************
    > File Name: StudentInfo.h
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2018年03月16日 星期五 00时48分32秒
 ************************************************************************/
#ifndef STUDENTINFO_H_
#define STUDENTINFO_H_
#include <vector>
#include <string>
#include <istream>

namespace stugrade {
	
struct StudentInfo {

	std::string name;
	double mid;
	double fin;
	std::vector<double> hw;

	StudentInfo() : mid(0.0), fin(0.0) {}
};//StudentInfo

std::istream& read_stu( std::istream& is, StudentInfo& s );
std::istream& read_stu_hw( std::istream& is, std::vector<double>& hw );
bool compare( const StudentInfo&, const StudentInfo& );
bool did_all_hw( const StudentInfo& );


};//stugrade

#endif
