#include <iostream>
#include <map>
#include <string>

int main(void) {
    std::map<std::string, int> counter;
    std::string word;
    while(std::cin >> word) {
        ++counter[word];
    }

    typedef std::map<std::string, int>::const_iterator const_iter;
    const_iter b = counter.begin();
    const_iter e = counter.end();

    while(b != e) {
        std::cout << b->first << ":" << b->second << std::endl;
        ++b;
    }

    return 0;
}
