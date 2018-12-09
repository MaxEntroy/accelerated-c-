#include "inc/mystring.h"
#include <algorithm>
#include <cctype>
#include <string>

std::vector<std::string> split(const std::string& sentence) {
    std::vector<std::string> ret;
    typedef std::string::const_iterator iter;
    iter b = sentence.begin();
    iter e = sentence.end();
    while(b != e) {
        b = find_if(b, e, not_space);
        if(b != e) {
            iter after = find_if(b, e, space);
            ret.push_back(std::string(b, after));
            b = after;
        }
    }
    return ret;
}

bool space(char ch) {
    return isspace(ch);
}
bool not_space(char ch) {
    return !space(ch);
}

bool is_palindrome(const std::string& pat) {
    return std::equal(pat.begin(), pat.end(), pat.rbegin());
}
