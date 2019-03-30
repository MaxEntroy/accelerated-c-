#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include "inc/StudentInfo.h"
//#define DEBUG

static const std::string kStudentDatPath = "./dat/input.dat";

int main(void) {
    std::list<StudentInfo> stu_list;
    StudentInfo stu;

    std::ifstream fin;
    fin.open(kStudentDatPath.c_str());
    if(!fin.is_open()) {
        std::cerr << "Invalid kStudentDatPath!" << std::endl;
        return -1;
    }

    while( ReadStudent(fin, stu) ) {
        stu_list.push_back(stu);
    }

    stu_list.sort(CompareStudentByName);

    std::list<StudentInfo> stu_failed_list;
    SeperatePassAndFailed(stu_list, stu_failed_list);

    std::cout << "Student who passed the exam: " << std::endl;
    typedef std::list<StudentInfo>::const_iterator const_iter;
    const_iter b = stu_list.begin();
    const_iter e = stu_list.end();
    for(; b != e; ++b) {
        double grade = MedianHomeWorkGrade(*b);
        std::cout << b->name_ << " " << grade << std::endl;
    }

    std::cout << "Student who failed the exam: " << std::endl;
    b = stu_failed_list.begin();
    e = stu_failed_list.end();
    for(; b != e; ++b) {
        double grade = MedianHomeWorkGrade(*b);
        std::cout << b->name_ << " " << grade << std::endl;
    }

    return 0;
}
