/*************************************************************************
    > File Name: grade.cc
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2018年03月18日 星期日 00时14分09秒
 ************************************************************************/
#include <stdexcept>
#include "median/median.h"
#include "grade/grade.h"

namespace stugrade {

double total_grade( double mid, double fin, double med) {
	return 0.2*mid + 0.4*fin + 0.4*med;
}



double median_grade( double mid, double fin, const std::vector<double>& hw ) {
	if( !hw.size() )
		throw std::domain_error( "Empty hw!" );

	double med = median(hw);
	double res = total_grade( mid, fin, med );

	return res;
}

double median_grade( const StudentInfo& s ) {
	return median_grade( s.mid, s.fin, s.hw );
}



double average_grade( double mid, double fin, const std::vector<double>& hw ) {
	if( !hw.size() )
		throw std::domain_error( "Empty hw!" );

	double aver = average(hw);
	double res = total_grade( mid, fin, aver );

	return res;
}

double average_grade( const StudentInfo& s ) {
	return average_grade( s.mid, s.fin, s.hw );
}



double optimistic_median_grade( double mid, double fin, const std::vector<double>& hw ) {
	if( !hw.size() )
		throw std::domain_error( "Empty hw!" );

	double op_med = optimistic_median(hw);
	double res = total_grade( mid, fin, op_med );

	return res;
}

double optimistic_median_grade( const StudentInfo& s ) {
	return optimistic_median_grade( s.mid, s.fin, s.hw );
}


};//stugrade
