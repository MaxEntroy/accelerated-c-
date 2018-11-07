/*************************************************************************
    > File Name: main.cc
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2018年03月12日 星期一 01时00分05秒
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<std::string> vcat( const std::vector<std::string>& top, const std::vector<std::string>& bottom );
std::vector<std::string> vcat1( const std::vector<std::string>& top, const std::vector<std::string>& bottom );

int main() {

	std::vector<std::string> top;
	std::vector<std::string> bottom;

	std::string s1("hello");
	std::string s2("world");
	
	std::string s3("world");
	std::string s4("hello");

	top.push_back( s1 );
	top.push_back( s2 );

	bottom.push_back( s3 );
	bottom.push_back( s4 );

	std::vector<std::string> ret = vcat1( top, bottom );
	
	int sz = ret.size();
	for( int i = 0; i < sz; ++i ) {
		std::cout << ret[i] << std::endl;
	}

	std::string s = "hello";
	typedef std::string::iterator iter;
	iter b = s.begin();

	std::copy( b+3, b+5, b );
	std::cout << s << std::endl;

	return 0;
}

std::vector<std::string> vcat( const std::vector<std::string>& top, const std::vector<std::string>& bottom ) {
	std::vector<std::string> ret = top;
	ret.insert( ret.end(), bottom.begin(), bottom.end() );
	return ret;
}
std::vector<std::string> vcat1( const std::vector<std::string>& top, const std::vector<std::string>& bottom ) {
	std::vector<std::string> ret = top;
	std::copy( bottom.begin(), bottom.end(), std::back_inserter(ret) );
	return ret;
}

