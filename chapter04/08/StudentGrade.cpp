/*************************************************************************
    > File Name: StudentGrade.cpp
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年11月28日 星期二 20时40分23秒
 ************************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iomanip>

struct StudentInfo {
	std::string name;
	double midterm_grade;
	double final_grade;
	double total_grade;
	std::vector<double> hw;
	StudentInfo() : midterm_grade(0.0), final_grade(0.0), total_grade(0.0) { }
};

bool compare( const StudentInfo&, const StudentInfo& );

double get_grade( double, double, const std::vector<double>& );
double get_grade( double, double, double );
double get_median( std::vector<double> );

std::istream& read_stu( std::istream&, StudentInfo& );
std::istream& read_stu_hw( std::istream&, std::vector<double>& );

int main(void) { 
	
	const char* input_path = "grade.dat";
	std::ifstream fin;
	fin.open(input_path);
	if( !fin.is_open() ) {
		std::cerr << "fin.open()";
		return -1;
	}

	std::vector<StudentInfo> vec_stu;
	int max_len = -1;

	try{
		StudentInfo s;
		while(read_stu(fin, s)) {
			s.total_grade = get_grade( s.midterm_grade, s.final_grade, s.hw );
			vec_stu.push_back(s);
			int name_sz = s.name.size();
			max_len = (name_sz > max_len)?name_sz:max_len;
		}
	}
	catch( std::domain_error e ) {
		std::cout << e.what();
		fin.close();
	}

	std::sort( vec_stu.begin(), vec_stu.end(), compare );
	
	int sz = vec_stu.size();
	std::streamsize prec = std::cout.precision();
	std::cout << std::setprecision(3);
	for( int i = 0; i < sz; ++i ) {
		std::string spaces( max_len - vec_stu[i].name.size() + 1, ' ' );
		std::cout << vec_stu[i].name << spaces << vec_stu[i].total_grade << std::endl;
	}
	std::cout << std::setprecision(prec);

	fin.close();
	
	return 0; 
}

double get_grade( double midterm_grade, double final_grade, const std::vector<double>& hw ) {
	if( !hw.size() ) 
		throw std::domain_error( "hw is empty!" );
	double median = get_median( hw );
	return get_grade( midterm_grade, final_grade, median );
}
double get_grade( double mid, double fin, double med ) {
	return mid*0.2 + fin*0.4 + med*0.4;
}
double get_median( std::vector<double> hw) {
	if( !hw.size() ) 
		throw std::domain_error( "hw is empty!" );
	
	std::sort( hw.begin(), hw.end() );
	int sz = hw.size();
	return (sz&1)?hw[sz/2]:1.0/2*(hw[sz/2] + hw[sz/2-1]);
}

std::istream& read_stu( std::istream& is, StudentInfo& s ) {
	if(is) {
		is >> s.name >> s.midterm_grade >> s.final_grade;
		read_stu_hw( is, s.hw );
	}
	return is;
}
std::istream& read_stu_hw( std::istream& is, std::vector<double>& hw ) {
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
bool compare( const StudentInfo& a, const StudentInfo& b ) {
	return a.name < b.name;
}
