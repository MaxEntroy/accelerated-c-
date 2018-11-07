/*************************************************************************
    > File Name: median.cpp
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年11月29日 星期三 09时15分50秒
 ************************************************************************/
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "median/median.h"

double median( std::vector<double> vec ) {
	if( !vec.size() )
		throw std::domain_error( "vec is empty!" );

	std::sort( vec.begin(), vec.end() );

	int sz = vec.size();
	return (sz & 1)?vec[sz/2]:1.0/2*( vec[sz/2] + vec[sz/2-1] );
}
