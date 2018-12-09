#ifndef ACCELERATED_CPP_CHAPTER06_14_INC_MYSTRING_H_
#define ACCELERATED_CPP_CHAPTER06_14_INC_MYSTRING_H_
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& sentence);
bool space(char ch);
bool not_space(char ch);

bool is_palindrome(const std::string& pat);

#endif
