/*************************************************************************
    > File Name: median.cc
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2018年03月17日 星期六 23时52分07秒
 ************************************************************************/
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include "median/median.h"

namespace stugrade {

double median( std::vector<double> hw ) {
	int sz = hw.size();
	if( !sz ) throw std::domain_error("Empty hw!");

	std::sort( hw.begin(), hw.end() );

	return (sz & 1)?hw[sz/2]:1.0/2*( hw[sz/2] + hw[sz/2-1] );
}

double average( const std::vector<double>& hw ) {
	int sz = hw.size();
	if( !sz ) throw std::domain_error("Empty hw!");
	return std::accumulate( hw.begin(), hw.end(), 0.0 )/sz;
}

double optimistic_median( std::vector<double> hw ) {
	int sz = hw.size();
	if( !sz ) throw std::domain_error("Empty hw!");
	
	std::vector<double> nonzero_hw;
	std::remove_copy( hw.begin(), hw.end(), std::back_inserter( nonzero_hw ), 0);

	std::sort( nonzero_hw.begin(), nonzero_hw.end() );

	sz = nonzero_hw.size();
	return (sz & 2)?nonzero_hw[sz/2]:1.0/2*( nonzero_hw[sz/2] + nonzero_hw[sz/2-1] );
}

};//stugrade

