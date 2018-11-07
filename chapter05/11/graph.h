/*************************************************************************
    > File Name: graph.h
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年12月01日 星期五 19时17分10秒
 ************************************************************************/
#ifndef GRAPH_H_
#define GRAPH_H_
#include <string>
#include <vector>

std::vector<std::string> framing( const std::vector<std::string>& );

void show_frame(const std::vector<std::string>&);

std::vector<std::string> vcat( const std::vector<std::string>&, const std::vector<std::string>& );

std::vector<std::string> hcat( const std::vector<std::string>&, const std::vector<std::string>& );

#endif
