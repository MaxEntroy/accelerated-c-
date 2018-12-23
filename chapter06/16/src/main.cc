#include "inc/student_info.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

const std::string kStudentFilePath = "./dat/input.dat";

int main() {
    std::ifstream fin;
    fin.open(kStudentFilePath.c_str());
    if(!fin.is_open()) {
        std::cerr << "File open error.";
        return -1;
    }

    StudentInfo stu;
    std::vector<StudentInfo> stu_vec;

    while( read_student(fin, stu)) {
        stu_vec.push_back(stu);
    }

    std::sort(stu_vec.begin(), stu_vec.end(), cmp_student );

    int stu_num = stu_vec.size();
    for(int i = 0; i < stu_num; ++i) {
        double score = grade(stu_vec[i]);
        std::cout << stu_vec[i].name << ":" << score << std::endl;
    }

    fin.close();
    return 0;
}
