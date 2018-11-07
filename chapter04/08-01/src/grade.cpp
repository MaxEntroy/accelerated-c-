/*************************************************************************
    > File Name: grade.cpp
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年11月29日 星期三 10时42分35秒
 ************************************************************************/
#include "grade/grade.h"
#include "median/median.h"
#include <vector>
#include <stdexcept>

double grade( double mid, double fin, double med ) {
	return mid * 0.2 + fin * 0.4 + med * 0.4;
}

double grade( double mid, double fin, const std::vector<double>& hw ) {
	int sz = hw.size();
	if( !sz ) 
		throw std::domain_error( "Empty hw!" );
	
	double med = median(hw);
	return grade( mid, fin, med );
}
