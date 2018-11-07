/************************************************************************
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年11月25日 星期六 16时55分02秒
 ************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include <ios>

void show_grade();

int main( void ) {
	show_grade();
	return 0;
}

void show_grade() {

	std::string name;
	std::cout << "Please enter your first name: ";
	std::cin >> name;

	double midterm_grades = 0.0;
	double final_grades = 0.0;
	std::cout << "Please enter your midterm and final exam grades: ";
	std::cin >> midterm_grades >> final_grades;

	double sum = 0;
	int cnt = 0;
	double grades = 0.0;
	std::cout << "Please enter all your homework grades, "
		"followed by end of file: ";
	while( std::cin >> grades ) {
		sum += grades;
		++cnt;
	}

	double ans = 0.2*midterm_grades + 0.4*final_grades + 0.4*sum/cnt;
	std::streamsize prec = std::cout.precision();
	std::cout << prec << std::endl;
	std::cout << "Hello, " << name << "!" << std::endl;
	std::cout << "Your total grades is " << std::setprecision(3) << ans << "!"
		<< std::setprecision(prec)<< std::endl;

	return;
}
