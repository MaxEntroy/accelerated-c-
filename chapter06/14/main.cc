/*************************************************************************
    > File Name: main.cc
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2018年03月12日 星期一 13时12分09秒
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

std::vector<std::string> split( const std::string& line );
bool notspace( char ch ) { return !isspace(ch); }
int main( void ) {

	const std::string line = "hello world world hello";
	std::vector<std::string> ret = split( line );
	int sz = ret.size();
	for( int i = 0; i < sz; ++i ) {
		std::cout << ret[i] << std::endl;
	}
	return 0;
}

std::vector<std::string> split( const std::string& line ) {
	std::vector<std::string> ret;
	if( line.empty() ) return ret;
	
	typedef std::string::const_iterator iter;
	iter b = line.begin();
	iter e = line.end();
	
	while( b != e ) {
		
		b = find_if( b, e, notspace );
		
		if( b != e ) {
			iter after = find_if( b, e, isspace );
			ret.push_back( std::string(b, after) );
			b = after;
		}
	}

	return ret;
}

