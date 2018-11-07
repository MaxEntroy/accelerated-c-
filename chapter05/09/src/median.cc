/*************************************************************************
    > File Name: median.cc
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年12月01日 星期五 16时30分15秒
 ************************************************************************/
#include <algorithm>
#include <stdexcept>
#include "median/median.h"

double median( std::vector<double> hw ) {
	int sz = hw.size();
	if(!sz)
		throw std::domain_error("Empty hw!");

	std::sort( hw.begin(), hw.end() );

	return (sz & 1) ? hw[sz/2] : 1.0/2*( hw[sz/2] + hw[sz/2 - 1] );
}
