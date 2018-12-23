#include "inc/student_info.h"
#include <algorithm>

bool cmp_student(const StudentInfo& lhs, const StudentInfo& rhs) {
    return lhs.name < rhs.name;
}

std::ifstream& read_student(std::ifstream& fin, StudentInfo& s) {
    fin >> s.name;
    if(fin) {
        fin >> s.midterm_score;
        fin >> s.final_score;
        s.homework_score.clear();

        double hw_score = 0.0;
        while(fin >> hw_score) {
            s.homework_score.push_back(hw_score);
        }
        fin.clear();
    }
    return fin;
}

double median(std::vector<double>& hw_vec) {
    if(hw_vec.empty()) {
        return 0.0;
    }else {
        int sz = hw_vec.size();
        int mid = sz/2;

        std::sort(hw_vec.begin(), hw_vec.end());

        return (sz & 1)?hw_vec[mid]:(hw_vec[mid] + hw_vec[mid - 1])/2;
    }
}

double grade(double mid, double fin, double hw ) {
    return 0.2 * mid + 0.4 * fin + 0.4 * hw;
}

double grade(StudentInfo& stu) {
    double hw = median(stu.homework_score);
    return grade(stu.midterm_score, stu.final_score, hw);
}
