/*************************************************************************
    > File Name: grade.cc
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年12月01日 星期五 15时59分09秒
 ************************************************************************/
#include <stdexcept>
#include "grade/grade.h"
#include "median/median.h"

double grade( double mid, double fin, const std::vector<double>& hw ) {
	if( !hw.size() )
		throw std::domain_error("Empty hw!");
	double med = median(hw);

	return grade( mid, fin, med );
}

double grade( double mid, double fin, double med ) {
	return 0.2*mid + 0.4*fin + 0.4*med;
}

bool fgrade( const StudentInfo& s ) {
	return grade( s.mid, s.fin, s.hw ) < 60;
}
