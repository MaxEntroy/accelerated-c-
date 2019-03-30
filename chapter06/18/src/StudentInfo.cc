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

bool IsFailed(const StudentInfo& stu) {
    return MedianHomeWorkGrade(stu) < 60;
}

bool CompareStudentByName(const StudentInfo& lhs, const StudentInfo& rhs) {
    return lhs.name_ < rhs.name_;
}

void SeperatePassAndFailed(std::vector<StudentInfo>& stu_vec,
                           std::vector<StudentInfo>& stu_failed_vec) {
    unsigned int i = 0;
    while(i < stu_vec.size() ) {
        if( IsFailed(stu_vec[i]) ) {
            stu_failed_vec.push_back(stu_vec[i]);
            stu_vec.erase(stu_vec.begin() + i);
        }else {
            ++i;
        }
    }
}

void SeperatePassAndFailed(std::list<StudentInfo>& stu_list,
                           std::list<StudentInfo>& stu_failed_list) {
    typedef std::list<StudentInfo>::iterator iter;
    iter b = stu_list.begin();
    iter e = stu_list.end();
    while(b != e) {
        if(IsFailed(*b)) {
            stu_failed_list.push_back(*b);
            b = stu_list.erase(b);
        }
        else{
            ++b;
        }
    }
}

double MedianHomeWorkGrade(const StudentInfo& stu) {
    std::vector<double> hw = stu.hw_;

    double med = median(hw);

    return Grade(stu.midterm_grade_, stu.final_grade_, med);
};

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
