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
    int max_len_of_name = 0;
    for(int i = 0; i < stu_num; ++i) {
        int name_len = stu_vec[i].name.size();
        max_len_of_name = (name_len > max_len_of_name)?name_len:max_len_of_name;
    }
    const int internal = 2;
    for(int i = 0; i < stu_num; ++i) {
        double score = grade(stu_vec[i]);
        std::string spaces(max_len_of_name - stu_vec[i].name.size() + internal, ' ');
        std::cout << stu_vec[i].name << spaces << score << std::endl;
    }

    fin.close();
    return 0;
}
