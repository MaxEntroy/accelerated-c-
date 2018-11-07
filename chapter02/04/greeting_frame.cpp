/*************************************************************************
    > File Name: greeting_frame.cpp
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年11月25日 星期六 16时34分57秒
 ************************************************************************/
#include <iostream>
#include <string>

void show_greeting_frame( const std::string& greeting, int pad );

int main( void ) {
	
	std::string name;
	std::cout << "Please enter your first name: ";
	std::cin >> name;
	
	std::string greeting = "Hello, " + name + "!";
	const int pad = 2;

	show_greeting_frame( greeting, pad );

	return 0;
}

void show_greeting_frame( const std::string& greeting, int pad ) {

	int rows = pad*2 + 3;
	int cols = greeting.size() + pad*2 + 2;

	for( int i = 0; i < rows; ++i ) {
		if( !i || i==rows-1 ){
			std::string line( cols, '*' );
			std::cout << line << std::endl;
		}
		else if( i == pad + 1 ) {
			std::string space(pad, ' ');
			std::string line = "*" + space + greeting + space + "*";
			std::cout << line << std::endl;
		}
		else{
			std::string space(cols-2, ' ');
			std::string line = "*" + space + "*";
			std::cout << line << std::endl;
		}
	}
	
	return;
}
