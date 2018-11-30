#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
#include "inc/replace_index.h"


void replace_index(const std::vector<std::string>& input_sentence, std::vector<std::string>* output_sentence) {
    assert(output_sentence);

    std::vector<element> res;

    // generate the loop collections
    int sz = input_sentence.size();
    for( int i = 0; i < sz; ++i ) {
        const std::string& sentence = input_sentence[i];

        std::string word;
        std::deque<std::string> words;
        std::stringstream ss(sentence);
        while( ss >> word ) {
            words.push_back(word);
            //std::cout << word << std::endl;
        }
        std::string start = words[0];

        do {
            element e;
            e.words = words;
            e.start_word = start;
            res.push_back(e);

            words.push_back(words[0]);
            words.pop_front();

        }while(words[0] != start);
    }

    // sort the loop collections
    std::sort(res.begin(), res.end());

    // print the loop collections
    int max_left_sz = 0;
    std::vector<std::vector<std::string>> tmp_sentence_collection;
    sz = res.size();
    for( int i = 0; i < sz; ++i ) {
        const std::deque<std::string>& ws = res[i].words;
        const std::string& start = res[i].start_word;
        //std::cout << ws[0] << " " << start << std::endl;

        std::string left;
        std::string right;
        bool left_first = true;
        bool right_first = true;
        bool dir_flag = false; // false means right part, true means left part
        const std::string space(" ");

        int ws_sz = ws.size();
        for(int i = 0; i < ws_sz; ++i) {
            if(ws[i] == start && i != 0) {
                dir_flag = true;
            }

            if(dir_flag) {
                if(left_first) {
                    left_first = false;
                    left += ws[i];
                }
                else {
                    left += (space + ws[i]);
                }
            }
            else {
                if(right_first) {
                    right_first = false;
                    right += ws[i];
                }
                else {
                    right += (space + ws[i]);
                }
            }
        }
        max_left_sz = ((int)(left.size()) > max_left_sz)?left.size():max_left_sz;
        std::vector<std::string> a_sentence;
        a_sentence.push_back(left);
        a_sentence.push_back(right);
        tmp_sentence_collection.push_back(a_sentence);
    }

    sz = tmp_sentence_collection.size();
    const std::string tab("\t\t");
    for(int i = 0; i < sz; ++i) {
        std::string left = tmp_sentence_collection[i][0];
        std::string right = tmp_sentence_collection[i][1];
        std::string space(max_left_sz - left.size(), ' ');
        std::string line = space + left + tab + right;
        (*output_sentence).push_back(line);
    }
}

std::string to_lower(const std::string& word) {
    std::string w = word;
    int sz = w.size();
    for(int i = 0 ; i < sz; ++i) {
        if('A' <= w[i] && w[i] <= 'Z' )
            w[i] = w[i] + 32;
        else
            w[i] = w[i];
    }
    return w;
}
