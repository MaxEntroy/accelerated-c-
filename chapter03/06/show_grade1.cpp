/*************************************************************************
    > File Name: show_grade1.cpp
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年11月27日 星期一 20时18分21秒
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ios>
#include <iomanip>

void show_grades();

int main( void ) {
	show_grades();
	return 0;
}

void show_grades() {
	
	std::string name;
	std::cout << "Please input your name: ";
	std::cin >> name;

	double midterm_grade = 0.0;
	double final_grade = 0.0;
	std::cout << "Please input your midterm grade: ";
	std::cin >> midterm_grade;
	std::cout << "Please input your final grade: ";
	std::cin >> final_grade;

	std::vector<double> hw;
	double grade = 0.0;
	std::cout << "Please input all your homework grade,"
		"followed by end of file: ";
	while(std::cin >> grade) {
		hw.push_back(grade);
	}
	
	std::sort(hw.begin(), hw.end());
	int sz = hw.size();
	if(!sz) {
		std::cout << "You must enter your grades!" 
			"Please try again" << std::endl;
		return;
	}
	
	double median = (sz&1)?hw[sz/2]:1.0/2*(hw[sz/2-1] + hw[sz/2]);

	double ans = 0.2 * midterm_grade + 0.4 * final_grade + 0.4 * median;
	
	std::cout << "Hello, " << name << "!" << std::endl;
	std::streamsize prec = std::cout.precision();
	std::cout << "Your final grade is " << std::setprecision(3) << ans 
		<< "!" << std::setprecision(prec) << std::endl;

	return;
}
