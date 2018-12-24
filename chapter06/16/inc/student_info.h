#ifndef ACCELERATED_CPP_CHAPTER06_INC_STUDENTINFO_H_
#define ACCELERATED_CPP_CHAPTER06_INC_STUDENTINFO_H_
#include <fstream>
#include <string>
#include <vector>

struct StudentInfo {
    std::string name;
    double midterm_score;
    double final_score;
    std::vector<double> homework_score;

    StudentInfo() : midterm_score(0.0), final_score(0.0) {}
};

bool cmp_student(const StudentInfo& lhs, const StudentInfo& rhs);
std::ifstream& read_student(std::ifstream& fin, StudentInfo& s);

double median(std::vector<double>& hw_vec);

double grade(StudentInfo& stu);
double grade(double mid, double fin, double hw);

#endif
