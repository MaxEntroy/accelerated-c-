/*************************************************************************
    > File Name: StudentInfo.cc
    > Author: kang
    > Mail: likang@tju.edu.cn
    > Created Time: 2018年03月16日 星期五 00时55分32秒
 ************************************************************************/
#include <algorithm>
#include "student/StudentInfo.h"

namespace stugrade {

std::istream& read_stu( std::istream& is, StudentInfo& s ) {
	if(is) {
		is >> s.name >> s.mid >> s.fin;
		read_stu_hw(is, s.hw);
	}
	return is;
}

std::istream& read_stu_hw( std::istream& is, std::vector<double>& hw ) {
	if( is ) {
		hw.clear();
		double x = 0.0;
		while( is >> x ) hw.push_back(x);
		is.clear();
	}
	return is;
}

bool compare( const StudentInfo& a, const StudentInfo& b ) {
	return a.name < b.name;
}

bool did_all_hw( const StudentInfo& s ) {
	return std::find( s.hw.begin(), s.hw.end(), 0 ) == s.hw.end();
}

};//stugrade
