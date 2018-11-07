/*************************************************************************
    > File Name: split.cc
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年12月01日 星期五 19时04分06秒
 ************************************************************************/
#include <string>
#include <iostream>
#include <vector>

std::vector<std::string> split( const std::string& line );

int main( void ) {
	std::string line;
	while( std::getline(std::cin, line) ) {
		std::vector<std::string> ret = split(line);
		int sz = ret.size();
		for( int i = 0; i < sz; ++i ) {
			std::cout << ret[i] << std::endl;
		}
	}
	return 0;
}

std::vector<std::string> split( const std::string& line ) {
	int sz = line.size();
	int i = 0;
	int j = 0;
	std::vector<std::string> ret;

	while( i < sz ) {
		
		while( i < sz && line[i]==' ' ) ++i;

		j = i;
		while( j < sz && line[j] != ' ' ) ++j;

		if( i < j ) ret.push_back( line.substr(i, j-i) );

		i = j;
	}
	return ret;
}
