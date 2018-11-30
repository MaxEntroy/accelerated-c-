#include "inc/replace_index.h"
#include <vector>
#include <iostream>

int main(void) {
    const std::string input_str1("The quick brown fox");
    const std::string input_str2("jumped over the fence");

    std::vector<std::string> input_sentence;
    input_sentence.push_back(input_str1);
    input_sentence.push_back(input_str2);

    std::vector<std::string> output_sentence;

    replace_index(input_sentence, &output_sentence);

    int sz = output_sentence.size();
    for(int i = 0; i < sz; ++i) {
        std::cout << output_sentence[i]  << std::endl;
    }

    return 0;
}
