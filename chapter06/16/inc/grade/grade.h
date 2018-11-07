/*************************************************************************
    > File Name: grade.h
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2018年03月18日 星期日 00时08分12秒
 ************************************************************************/
#ifndef GRADE_H_
#define GRADE_H_
#include <vector>
#include "student/StudentInfo.h"

namespace stugrade {

double total_grade( double, double, double );

double median_grade( double, double, const std::vector<double>& );
double median_grade( const StudentInfo& s );

double average_grade( double, double, const std::vector<double>& );
double average_grade( const StudentInfo& s );

double optimistic_grade( double, double, const std::vector<double>& );
double optimistic_grade( const StudentInfo& s );

void analysis( std::istream& is, 
		             const std::string& category, 
					 void (*analysis)(const StudentInfo&),
					 const std::vector<StudentInfo>& vec );
void median_analysis( const std::vector<StudentInfo>& vec );
void average_analysis( const std::vector<StudentInfo>& vec );
void optimistic_median_analysis( const std::vector<StudentInfo>& vec );

};//stugrade

#endif
