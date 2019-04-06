#ifndef ACCELERATED_CPP_CHAPTER06_17_INC_STUDENTINFO_H_
#define ACCELERATED_CPP_CHAPTER06_17_INC_STUDENTINFO_H_

#include <fstream>
#include <list>
#include <string>
#include <vector>

struct StudentInfo {
    std::string name_;
    double midterm_grade_;
    double final_grade_;
    std::vector<double> hw_;

    StudentInfo() :midterm_grade_(0.0), final_grade_(0.0) {}
};

std::ifstream& ReadStudent(std::ifstream& fin, StudentInfo& stu);
void ShowStudent(const StudentInfo& stu);
bool IsFailed(const StudentInfo& stu);
bool IsPassed(const StudentInfo& stu);
bool CompareStudentByName(const StudentInfo& lhs, const StudentInfo& rhs);

void SeperatePassAndFailed(std::vector<StudentInfo>& stu_vec,
                           std::vector<StudentInfo>& stu_failed_vec);

void SeperatePassAndFailed(std::list<StudentInfo>& stu_list,
                           std::list<StudentInfo>& stu_failed_list);

// T(n) = n, S(n) = 1
void SeperatePassAndFailed1(std::vector<StudentInfo>& stu_vec,
                            std::vector<StudentInfo>& stu_failed_vec);

// T(n) = 2n, S(n) = 1
void SeperatePassAndFailed2(std::vector<StudentInfo>& stu_vec,
                            std::vector<StudentInfo>& stu_failed_vec);

// n < T(n) < 2*n
void SeperatePassAndFailed3(std::vector<StudentInfo>& stu_vec,
                            std::vector<StudentInfo>& stu_failed_vec);

int partation(std::vector<StudentInfo>& stu_vec);
void swap(StudentInfo& lhs, StudentInfo& rhs);

// n < T(n) < 2*n
void SeperatePassAndFailed4(std::vector<StudentInfo>& stu_vec,
                            std::vector<StudentInfo>& stu_failed_vec);

template<class Iter, class UnaryPredicate>
Iter partation1(Iter first, Iter last, UnaryPredicate pred);

void SeperatePassAndFailed5(std::vector<StudentInfo>& stu_vec,
                            std::vector<StudentInfo>& stu_failed_vec);

double MedianHomeWorkGrade(const StudentInfo& stu);
double Grade(double mid, double fin, double med);

double median(std::vector<double>& v);

#endif
