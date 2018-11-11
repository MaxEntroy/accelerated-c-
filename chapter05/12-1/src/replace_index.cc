#include <assert.h>
#include <iostream>
#include <sstream>
#include <deque>
#include "inc/replace_index.h"

void replace_index(const std::string& in_str, std::string* out_str) {
    assert(out_str);

    std::string word;
    std::deque<std::string> sentence;
    std::stringstream ss(in_str);
    while( ss >> word ) {
        sentence.push_back(word);
    }

}
