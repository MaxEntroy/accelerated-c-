#include "inc/mystring.h"
#include <iostream>
#include <string>

int main(void) {
    const std::string sentence("this is a wonderful time");

    std::vector<std::string> ret = split(sentence);
    int sz = ret.size();
    for(int i = 0; i < sz; ++i) {
        std::cout << ret[i] << std::endl;
    }

    const std::string s1("abcdefg");
    const std::string s2("abba");

    if(is_palindrome(s1)) {
        std::cout << "s1 is palindrome." << std::endl;
    }else {
        std::cout << "s1 is not palindrome." << std::endl;
    }

    if(is_palindrome(s2)) {
        std::cout << "s2 is palindrome." << std::endl;
    }else {
        std::cout << "s2 is not palindrome." << std::endl;
    }

    return 0;
}
