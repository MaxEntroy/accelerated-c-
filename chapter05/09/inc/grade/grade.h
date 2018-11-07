/*************************************************************************
    > File Name: grade.h
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年12月01日 星期五 15时56分16秒
 ************************************************************************/
#ifndef GRADE_H_
#define GRADE_H_
#include <vector>
#include "student/StudentInfo.h"

double grade( double, double, const std::vector<double>& hw  );
double grade( double, double, double );
bool fgrade( const StudentInfo& s );

#endif
