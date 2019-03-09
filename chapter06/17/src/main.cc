#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "inc/StudentInfo.h"

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

    int sz = stu_vec.size();
    for(int i = 0; i < sz; ++i) {
        double med_grade = MedianHomeWorkGrade(stu_vec[i]);
        double aver_grade = AverageHomeWorkGrade(stu_vec[i]);
        double optimistic_med_grade = OptimisticHomeWorkGrade(stu_vec[i]);
        std::cout << stu_vec[i].name_ << " "
            << med_grade << " "
            << aver_grade << " "
            << optimistic_med_grade
            << std::endl;
    }

    return 0;
}
