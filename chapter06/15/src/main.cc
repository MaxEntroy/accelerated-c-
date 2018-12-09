#include "inc/url.h"
#include <iostream>
#include <string>
#include <vector>

int main(void) {
    const std::string url_txt( "w://w<<<<<<:/<<<<<://<<<<http://www.baidu.com<<<<://weibo.com" );
    std::vector<std::string> urls = get_urls(url_txt);
    int sz = urls.size();
    for(int i = 0; i < sz; ++i) {
        std::cout << urls[i] << std::endl;
    }
    return 0;
}
