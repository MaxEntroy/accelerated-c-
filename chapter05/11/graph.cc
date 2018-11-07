/*************************************************************************
    > File Name: graph.cc
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年12月01日 星期五 19时20分13秒
 ************************************************************************/
#include "graph.h"
#include <iostream>

std::vector<std::string> framing( const std::vector<std::string>& s ) {
	const int sz = s.size();
	const int pad = 2;
	std::vector<std::string> ret;

	int maxlen = -1;
	for( int i = 0; i < sz; ++i ) {
		int line_sz = s[i].size();
		maxlen = (line_sz > maxlen)?line_sz:maxlen;
	}

	const int rows = sz + pad*2 + 2;
	const int cols = maxlen + pad*2 + 2;

	std::string stars(cols, '*');
	std::string space(cols-2, ' ');
	std::string pad_str = "*" + space + "*";

	ret.push_back(stars);
	for( int i = 0; i < pad; ++i ) ret.push_back(pad_str);
	
	for( int i = 0; i < sz; ++i ) {
		std::string pads( pad, ' ' );
		std::string right_space(maxlen - s[i].size(), ' ');
		std::string line = "*" + pads + s[i] + right_space + pads + "*";
		ret.push_back(line);
	}

	for( int i = 0; i < pad; ++i ) ret.push_back(pad_str);
	ret.push_back(stars);

	return ret;
} 

void show_frame( const std::vector<std::string>& frame ) {
	int sz = frame.size();
	for( int i = 0; i < sz; ++i ) {
		std::cout << frame[i] << std::endl;
	}
	return;
}

std::vector<std::string> vcat( const std::vector<std::string>& a, const std::vector<std::string>& b ) {
	std::vector<std::string> ret(a);
	int sz_b = b.size();
	for( int i = 0; i < sz_b; ++i ) ret.push_back(b[i]);
	return ret;
}

std::vector<std::string> hcat( const std::vector<std::string>& a, const std::vector<std::string>& b ) {
	std::vector<std::string> ret;
	int sz_a = a.size();
	int sz_b = b.size();

	int maxlen = -1;
	for( int i = 0; i < sz_a; ++i ) {
		int sz_name = a[i].size();
		maxlen = (sz_name > maxlen)?sz_name:maxlen;
	}

	int i = 0;
	while( i < sz_a && i < sz_b ) {
		std::string line = a[i];
		std::string space( maxlen - a[i].size() + 1, ' ' );
		line = line + space + b[i];
		
		ret.push_back(line);
		++i;
	}
	while( i < sz_a ) {
		ret.push_back( a[i]) ;
		++i;
	}
	while( i < sz_b ) {
		std::string space(maxlen + 1, ' ');
		std::string line = space + b[i];
		
		ret.push_back( line );
		++i;
	}
	return ret;
}
