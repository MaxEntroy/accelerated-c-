/*************************************************************************
    > File Name: StudentInfo.cc
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2017年12月01日 星期五 16时10分46秒
 ************************************************************************/
#include "student/StudentInfo.h"

std::istream& read_stu( std::istream& is, StudentInfo& s ) {
	if(is) {
		is >> s.name >> s.mid >> s.fin;
		read_stu_hw(is, s.hw);
	}
	return is;
}

std::istream& read_stu_hw( std::istream& is, std::vector<double>& hw ) {
	if(is) {
		hw.clear();
		double x = 0.0;
		while(is >> x) {
			hw.push_back(x);
		}
		is.clear();
	}
	return is;
}

bool compare( const StudentInfo& a, const StudentInfo& b ) {
	return a.name < b.name;
}
