#ifndef ACCELERAED_CPP_CHAPTER05_12_1_INC_REPLACE_INDEX_H_
#define ACCELERAED_CPP_CHAPTER05_12_1_INC_REPLACE_INDEX_H_
#include <deque>
#include <string>
#include <vector>


void replace_index(const std::vector<std::string>& input_sentence, std::vector<std::string>* output_sentence);
std::string to_lower(const std::string& word);

struct element {
    std::deque<std::string> words;
    std::string start_word;

    bool operator<( const element& rhs ) const {
        std::string l_w = to_lower(words[0]);
        std::string r_w = to_lower(rhs.words[0]);
        if(l_w != r_w)
            return l_w < r_w;
        else {
            if(words.size() > 1 && rhs.words.size() > 1)
                return to_lower(words[1]) < to_lower(rhs.words[1]);
            else
                return l_w < r_w;
        }
    }
};

#endif
