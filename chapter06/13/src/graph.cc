#include "inc/graph.h"
#include <iostream>
#include <algorithm>
#include <iterator>

void init_graph(std::vector<std::string>* ret) {
    std::string s1("This is an example");
    std::string s2("to illustrate framing.");

    (*ret).push_back(s1);
    (*ret).push_back(s2);
}

void frame_graph(const std::vector<std::string>& g, std::vector<std::string>* ret) {
    int sz = g.size();
    int maxlen = 0;
    for(int i = 0; i < sz; ++i) {
        int str_sz = g[i].size();
        maxlen = (str_sz > maxlen)?str_sz:maxlen;
    }

    const int white_space_num = 2; // 左右两侧空白符个数
    std::string stars(maxlen + 2*white_space_num + 2, '*');
    std::string left_white_space(white_space_num, ' ');
    (*ret).push_back(stars);

    for(int i = 0; i < sz; ++i) {
        std::string line("*");
        line += left_white_space;
        line += g[i];
        int str_sz = g[i].size();
        std::string right_white_space(maxlen - str_sz + white_space_num, ' ');
        line += right_white_space;
        line += "*";
        (*ret).push_back(line);
    }
    (*ret).push_back(stars);
}

void show_graph(const std::vector<std::string>& g) {
    int sz = g.size();
    for(int i = 0; i < sz; ++i) {
        std::cout << g[i] << std::endl;
    }
}
std::vector<std::string> vcat(const std::vector<std::string>& top,
                              const std::vector<std::string>& bottom) {
    std::vector<std::string> ret(top);
    int sz = bottom.size();
    for(int i = 0; i < sz; ++i) {
        ret.push_back(bottom[i]);
    }
    return ret;
}

std::vector<std::string> vcat1(const std::vector<std::string>& top,
                               const std::vector<std::string>& bottom) {
    std::vector<std::string> ret(top);
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    return ret;
}

std::vector<std::string> vcat2(const std::vector<std::string>& top,
                               const std::vector<std::string>& bottom) {
    std::vector<std::string> ret(top);
    std::copy(bottom.begin(), bottom.end(), std::back_inserter(ret));
    return ret;
}
