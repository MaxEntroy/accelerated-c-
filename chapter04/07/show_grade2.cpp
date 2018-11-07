/*************************************************************************
    > File Name: show_grade2.cpp
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年11月27日 星期一 22时47分50秒
 ************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iomanip>

double get_median( std::vector<double> hw );
double get_grade( double midterm_grade, double final_grade, double median );
double get_grade( double midterm_grade, double final_grade, std::vector<double>& hw );

std::istream& read_hw( std::istream& is, std::vector<double>& hw );

int main( void ) {

	std::string name;
	std::cout << "Please input your name: ";
	std::cin >> name;

	double midterm_grade = 0.0;
	double final_grade = 0.0;

	std::cout << "Please input midterm grade: ";
	std::cin >> midterm_grade;
	std::cout << "Please input final grade: ";
	std::cin >> final_grade;

	std::cout << "Please input homework grade,"
		"followed by end of file: ";
	std::vector<double> hw;
	read_hw( std::cin, hw );

	try {
		double total_grade = get_grade( midterm_grade, final_grade, hw );
		std::streamsize prec = std::cout.precision();
		std::cout << "Hello, " << name << "!" << std::endl;
		std::cout << "Your final grade is " << std::setprecision(3) << total_grade 
			<< "!" << std::setprecision(prec) << std::endl;
	}
	catch(std::domain_error& e) {
		std::cout << e.what() << std::endl;
		return -1;
	}

	return 0;
}

double get_median( std::vector<double> hw ) {
	int sz = hw.size();
	if( !sz )
		throw std::domain_error( "hw is empty!" );
	
	std::sort( hw.begin(), hw.end() );
	double median = (sz&1)?hw[sz/2]:1.0/2*(hw[sz/2-1] + hw[sz/2]);

	return median;
}

double get_grade( double midterm_grade, double final_grade, double median ) {
	return 0.2 * midterm_grade + 0.4 * final_grade + 0.4 * median;
}

double get_grade( double midterm_grade, double final_grade, std::vector<double>& hw ) {
	int sz = hw.size();
	if(!sz)
		throw std::domain_error( "hw is empty1" );

	double median = get_median(hw);
	return get_grade( midterm_grade, final_grade, median );
}

std::istream& read_hw( std::istream& is, std::vector<double>& hw ) {
	if( is ) {
		hw.clear();
		double x = 0.0;
		while( is >> x ) {
			hw.push_back(x);
		}
		is.clear();
	}
	return is;
}
