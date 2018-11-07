/*************************************************************************
    > File Name: median.h
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2018年03月17日 星期六 23时48分13秒
 ************************************************************************/
#ifndef MEDIAN_H_
#define MEDIAN_H_
#include <vector>

namespace stugrade {

double median( std::vector<double> );
double average( const std::vector<double>& );
double optimistic_median( std::vector<double> );

};//stugrade

#endif
