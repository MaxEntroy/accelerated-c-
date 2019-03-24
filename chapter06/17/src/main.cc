#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include "inc/StudentInfo.h"
//#define DEBUG

static const std::string kStudentDatPath = "./dat/input.dat";

int main(void) {
    std::vector<StudentInfo> stu_vec;
    StudentInfo stu;

    std::ifstream fin;
    fin.open(kStudentDatPath.c_str());
    if(!fin.is_open()) {
        std::cerr << "Invalid kStudentDatPath!" << std::endl;
        return -1;
    }

    while( ReadStudent(fin, stu) ) {
        stu_vec.push_back(stu);
    }

    std::vector<StudentInfo> did;
    std::vector<StudentInfo> didnt;
    SeperateDidFromDidnt(stu_vec, did, didnt);

#ifdef DEBUG
    std::cout << "did: " << std::endl;
    int sz = did.size();
    for(int i = 0; i < sz; ++i) {
        ShowStudent(did[i]);
    }

    std::cout << "didnt: " << std::endl;
    sz = didnt.size();
    for(int i = 0; i < sz; ++i) {
        ShowStudent(didnt[i]);
    }
#endif

    std::sort(did.begin(), did.end(), CompareStudentByName);
    std::sort(didnt.begin(), didnt.end(), CompareStudentByName);

    WriteAnalysis(did, didnt, "Median analysis:", MedianAnalysis);
    WriteAnalysis(did, didnt, "Average analysis:", AverageAnalysis);
    WriteAnalysis(did, didnt, "Optimistic Median Analysis:", OptimisticMedianAnalysis);

    return 0;
}
