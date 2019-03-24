#include "inc/StudentInfo.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>

std::ifstream& ReadStudent(std::ifstream& fin, StudentInfo& stu) {
    fin >> stu.name_;
    if(fin) {
        fin >> stu.midterm_grade_ >> stu.final_grade_;
        stu.hw_.clear();
        double grade;
        while( fin >> grade) {
            stu.hw_.push_back(grade);
        }
        fin.clear();
    }
    return fin;
}

void ShowStudent(const StudentInfo& stu) {
    std::cout << stu.name_ << " " << stu.midterm_grade_ << " " << stu.final_grade_;
    int sz = stu.hw_.size();
    for(int i = 0; i < sz; ++i) {
        std::cout << " " << stu.hw_[i];
    }
    std::cout << std::endl;
}

bool IsDidAllHomeWork(const StudentInfo& stu) {
    return std::find(stu.hw_.begin(), stu.hw_.end(), 0) == stu.hw_.end();
}

bool CompareStudentByName(const StudentInfo& lhs, const StudentInfo& rhs) {
    return lhs.name_ < rhs.name_;
}

void SeperateDidFromDidnt(const std::vector<StudentInfo>& stu_vec,
                          std::vector<StudentInfo>& did,
                          std::vector<StudentInfo>& didnt) {
    int sz = stu_vec.size();
    for(int i = 0; i < sz; ++i) {
        const StudentInfo& stu = stu_vec[i];
        if(IsDidAllHomeWork(stu)) {
            did.push_back(stu);
        }else {
            didnt.push_back(stu);
        }
    }
}

void WriteAnalysis(const std::vector<StudentInfo>& did,
                   const std::vector<StudentInfo>& didnt,
                   const std::string& analysis_type,
                   double (*analysis)(const std::vector<StudentInfo>&)) {
    const std::string sep(10, '-');
    std::cout << sep << analysis_type << sep << std::endl;

    std::cout << "did:" << std::endl;
    double med = analysis(did);
    std::cout << "median of grades is: " << med << std::endl;

    std::cout << "didnt" << std::endl;
    med = analysis(didnt);
    std::cout << "median of grades is: " << med << std::endl;

    std::cout << sep << sep << std::endl;
}

double MedianAnalysis(const std::vector<StudentInfo>& stu_vec) {
    std::vector<double> grades;
    std::transform(stu_vec.begin(), stu_vec.end(), std::back_inserter(grades), MedianHomeWorkGrade);
    return median(grades);
}
double AverageAnalysis(const std::vector<StudentInfo>& stu_vec) {
    std::vector<double> grades;
    std::transform(stu_vec.begin(), stu_vec.end(), std::back_inserter(grades), AverageHomeWorkGrade);
    return median(grades);
}
double OptimisticMedianAnalysis(const std::vector<StudentInfo>& stu_vec) {
    std::vector<double> grades;
    std::transform(stu_vec.begin(), stu_vec.end(), std::back_inserter(grades), OptimisticHomeWorkGrade);
    return median(grades);
}

double MedianHomeWorkGrade(const StudentInfo& stu) {
    std::vector<double> hw = stu.hw_;

    double med = median(hw);

    return Grade(stu.midterm_grade_, stu.final_grade_, med);
};

double AverageHomeWorkGrade(const StudentInfo& stu) {
    std::vector<double> hw = stu.hw_;

    double aver = average(hw);

    return Grade(stu.midterm_grade_, stu.final_grade_, aver);
}

double OptimisticHomeWorkGrade(const StudentInfo& stu) {
    std::vector<double> optimistic_hw = stu.hw_;

    double optimistic_med = optimistic_median(optimistic_hw);

    return Grade(stu.midterm_grade_, stu.final_grade_, optimistic_med);
}

double Grade(double mid, double fin, double med) {
    return 0.2 * mid + 0.4 * fin + 0.4 * med;
}

double median(std::vector<double>& v) {
    std::sort(v.begin(), v.end());
    int v_sz = v.size();
    int v_mid = v_sz / 2;

    double med = (v_sz & 1)?v[v_mid]:(v[v_mid] + v[v_mid - 1])/2;
    return med;
}

double average(const std::vector<double>& v) {
    double sum = std::accumulate(v.begin(), v.end(), 0.0);
    int v_sz = v.size();
    double aver = sum / v_sz;

    return aver;
}

double optimistic_median(const std::vector<double>& v) {
    std::vector<double> optimistic_v;
    std::remove_copy(v.begin(), v.end(), std::back_inserter(optimistic_v), 0);

    double optimistic_med = median(optimistic_v);
    return optimistic_med;
}
