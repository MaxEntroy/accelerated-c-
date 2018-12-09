#include "inc/url.h"
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
#include <iostream>

std::vector<std::string> get_urls(const std::string& url_txt) {
    std::vector<std::string> ret;

    typedef std::string::const_iterator const_iter;
    const_iter b = url_txt.begin();
    const_iter e = url_txt.end();

    while(b != e) {
        b = url_begin(b, e);
        if(b != e) {
            const_iter after = url_end(b, e);
            ret.push_back(std::string(b, after));
            b = after;
        }
    }
    return ret;
}

std::string::const_iterator url_begin(const std::string::const_iterator& b,
                                      const std::string::const_iterator& e) {
    typedef std::string::const_iterator const_iter;
    static const std::string sep("://");
    int sep_sz = sep.size();

    const_iter beg = b;
    beg = search(beg, e, sep.begin(), sep.end());
    while(beg != e) {

        // left
        const_iter beg_bak = beg;
        while(beg != b && isalnum(beg[-1]) ) --beg;
        if(beg == beg_bak) {
            beg = beg + sep_sz;
            beg = search(beg, e, sep.begin(), sep.end());
            continue;
        }

        // right
        const_iter after = beg_bak+sep_sz;
        if(after != e && isalnum(*after))
            break;
        else{
            beg = after;
            beg = search(b, e, sep.begin(), sep.end());
        }
    }
    return beg;
}

std::string::const_iterator url_end(const std::string::const_iterator& b,
                                    const std::string::const_iterator& e) {
    return find_if(b, e, not_legal_url_char);
}


bool legal_url_char(char ch) {
    static const std::string url_chars("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_.~!*'();:@&=+$,/?#[]");
    return find(url_chars.begin(), url_chars.end(), ch) != url_chars.end();
}

bool not_legal_url_char(char ch) {
    return !legal_url_char(ch);
};


