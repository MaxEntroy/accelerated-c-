/*************************************************************************
 > File Name: greeting.cpp
 > Author: kang
 > Mail:likang@tju.edu.cn 
 > Created Time: 2017年11月06日 星期一 22时29分03秒
 ************************************************************************/
#include <iostream>
#include <string>
int main(void) {
	std::string name;

	std::cout << "Please input your name: ";
	std::cin >> name;

	std::cout << "Hello, " << name << "!" << std::endl;

	return 0;
}
