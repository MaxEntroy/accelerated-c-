#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include "inc/StudentInfo.h"

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

bool CompareStudentByName(const StudentInfo& lhs, const StudentInfo& rhs) {
    return lhs.name_ < rhs.name_;
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
