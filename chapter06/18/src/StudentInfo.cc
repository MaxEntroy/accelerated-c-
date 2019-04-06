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

bool IsPassed(const StudentInfo& stu) {
    return !IsFailed(stu);
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

void SeperatePassAndFailed1(std::vector<StudentInfo>& stu_vec,
                            std::vector<StudentInfo>& stu_failed_vec) {
    int failed_num = 0;
    int sz = stu_vec.size();
    for(int i = 0; i < sz; ++i) {
        if(IsFailed(stu_vec[i])) {
            stu_failed_vec.push_back(stu_vec[i]);
            ++failed_num;
        }else{
            stu_vec[i - failed_num] = stu_vec[i];
        }
    }
    stu_vec.erase(stu_vec.begin() + sz - failed_num, stu_vec.end());
}

void SeperatePassAndFailed2(std::vector<StudentInfo>& stu_vec,
                            std::vector<StudentInfo>& stu_failed_vec) {
    int sz = stu_vec.size();
    for(int i = 0; i < sz; ++i) {
        if(IsFailed(stu_vec[i])) {
            stu_failed_vec.push_back(stu_vec[i]);
        }
    }

    stu_vec.erase(std::remove_if(stu_vec.begin(), stu_vec.end(), IsFailed) ,stu_vec.end());
}

void SeperatePassAndFailed3(std::vector<StudentInfo>& stu_vec,
                            std::vector<StudentInfo>& stu_failed_vec) {
    int pivot = partation(stu_vec);
    stu_failed_vec = std::vector<StudentInfo>(stu_vec.begin() + pivot, stu_vec.end());
    stu_vec.erase(stu_vec.begin() + pivot, stu_vec.end());
}

int partation(std::vector<StudentInfo>& stu_vec) {
    int i = 0;
    int j = stu_vec.size() - 1;
    while(i < j) {
        while(i < j && !IsFailed(stu_vec[i])) ++i;
        if(i < j) {
            while(i < j && IsFailed(stu_vec[j])) --j;
            if(i < j) {
                swap(stu_vec[i], stu_vec[j]);
                ++i;
            }
        }
    }
    return i;
}

void swap(StudentInfo& lhs, StudentInfo& rhs) {
    StudentInfo tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

void SeperatePassAndFailed4(std::vector<StudentInfo>& stu_vec,
                            std::vector<StudentInfo>& stu_failed_vec) {
    std::vector<StudentInfo>::iterator i = partation1(stu_vec.begin(), stu_vec.end(), IsFailed);
    stu_failed_vec = std::vector<StudentInfo>(i, stu_vec.end());
    stu_vec.erase(i, stu_vec.end());
}

template<class Iter, class UnaryPredicate>
Iter partation1(Iter first, Iter last, UnaryPredicate pred) {
    Iter i = first;
    Iter j = last - 1;
    while(i < j) {
        while(i < j && !pred(*i)) ++i;
        if(i < j) {
            while(i < j && pred(*j)) --j;
            if(i < j) {
                swap(*i, *j);
                ++i;
            }
        }
    }
    return i;
}

void SeperatePassAndFailed5(std::vector<StudentInfo>& stu_vec,
                            std::vector<StudentInfo>& stu_failed_vec) {
    std::vector<StudentInfo>::iterator pivot = std::stable_partition(stu_vec.begin(),
                                                                     stu_vec.end(),
                                                                     IsPassed);
    stu_failed_vec = std::vector<StudentInfo>(pivot, stu_vec.end());
    stu_vec.erase(pivot, stu_vec.end());
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
