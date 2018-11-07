/*************************************************************************
    > File Name: main.cc
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年12月02日 星期六 17时32分55秒
 ************************************************************************/
#include "graph.h"
#include <string>
#include <vector>

int main( void ) {

	std::vector<std::string> s;
	s.push_back("this is first");
	s.push_back("example");
	s.push_back("to");
	s.push_back("illustrate");
	s.push_back("framing");

	std::vector<std::string> a;
	a.push_back("this is second");
	a.push_back("example");
	a.push_back("to");
	a.push_back("illustrate");
	a.push_back("framing");

	std::vector<std::string> newgraph = vcat(s,a);
	std::vector<std::string> frame = framing(newgraph);
	show_frame(frame);
	
	std::vector<std::string> newgraph1 = hcat(s,a);
	std::vector<std::string> frame1 = framing(newgraph1);
	show_frame(frame1);

	return 0;
}
