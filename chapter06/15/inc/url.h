#ifndef ACCELERATED_CPP_CHAPTER06_INC_URL_H_
#define ACCELERATED_CPP_CHAPTER06_INC_URL_H_
#include <string>
#include <vector>

std::vector<std::string> get_urls(const std::string& url_txt);
std::string::const_iterator url_begin(const std::string::const_iterator& b,
                                      const std::string::const_iterator& e);
std::string::const_iterator url_end(const std::string::const_iterator& b,
                                    const std::string::const_iterator& e);
bool legal_url_char(char ch);
bool not_legal_url_char(char ch);

#endif
