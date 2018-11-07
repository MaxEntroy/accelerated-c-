/*************************************************************************
 > File Name: FrameGreeting.cpp
 > Author: kang
 > Mail:likang@tju.edu.cn 
 > Created Time: 2017年11月06日 星期一 22时32分26秒
 ************************************************************************/
#include <iostream>
#include <string>

int main( void ) {
	
	std::string name;
	std::cout << "Please input your name: ";
	std::cin >> name;

	std::string greeting("Hello, ");
	greeting = greeting + name + "!";

	std::string star( greeting.size() + 4, '*' );
	std::string space( greeting.size() + 2, ' ' );
	space = "*" + space + "*";
	
	greeting = "* " + greeting + " *";

	std::cout << star << std::endl;
	std::cout << space << std::endl;
	std::cout << greeting << std::endl;
	std::cout << space << std::endl;
	std::cout << star << std::endl;

	return 0;
}
