#ifndef ACCELERATED_CPP_CHAPTER06_17_INC_STUDENTINFO_H_
#define ACCELERATED_CPP_CHAPTER06_17_INC_STUDENTINFO_H_

#include <fstream>
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
bool IsDidAllHomeWork(const StudentInfo& stu);
bool CompareStudentByName(const StudentInfo& lhs, const StudentInfo& rhs);

void SeperateDidFromDidnt(const std::vector<StudentInfo>& stu_vec,
                          std::vector<StudentInfo>& did,
                          std::vector<StudentInfo>& didnt);

void WriteAnalysis(const std::vector<StudentInfo>& did,
                   const std::vector<StudentInfo>& didnt,
                   const std::string& analysis_type,
                   double (*analysis)(const std::vector<StudentInfo>&));

double MedianAnalysis(const std::vector<StudentInfo>& stu_vec);
double AverageAnalysis(const std::vector<StudentInfo>& stu_vec);
double OptimisticMedianAnalysis(const std::vector<StudentInfo>& stu_vec);

double MedianHomeWorkGrade(const StudentInfo& stu);
double AverageHomeWorkGrade(const StudentInfo& stu);
double OptimisticHomeWorkGrade(const StudentInfo& stu);
double Grade(double mid, double fin, double med);

double median(std::vector<double>& v);
double average(const std::vector<double>& v);
double optimistic_median(const std::vector<double>& v);

#endif
