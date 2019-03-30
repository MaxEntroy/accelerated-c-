#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include "inc/StudentInfo.h"
//#define DEBUG

static const std::string kStudentDatPath = "./dat/input.dat";

int main(void) {
    std::vector<StudentInfo> stu_vec;
    StudentInfo stu;

    std::ifstream fin;
    fin.open(kStudentDatPath.c_str());
    if(!fin.is_open()) {
        std::cerr << "Invalid kStudentDatPath!" << std::endl;
        return -1;
    }

    while( ReadStudent(fin, stu) ) {
        stu_vec.push_back(stu);
    }

    std::sort(stu_vec.begin(), stu_vec.end(), CompareStudentByName);

    std::vector<StudentInfo> stu_failed_vec;
    SeperatePassAndFailed1(stu_vec, stu_failed_vec);

    std::cout << "Student who passed the exam: " << std::endl;
    int sz = stu_vec.size();
    for(int i = 0; i < sz; ++i) {
        double grade = MedianHomeWorkGrade(stu_vec[i]);
        std::cout << stu_vec[i].name_ << " " << grade << std::endl;
    }

    std::cout << "Student who failed the exam: " << std::endl;
    sz = stu_failed_vec.size();
    for(int i = 0; i < sz; ++i) {
        double grade = MedianHomeWorkGrade(stu_failed_vec[i]);
        std::cout << stu_failed_vec[i].name_ << " " << grade << std::endl;
    }

    return 0;
}
