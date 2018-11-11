#include "inc/replace_index.h"

int main(void) {
    const std::string input_str("The quick brown fox");
    std::string output_str;
    replace_index(input_str, &output_str);
    return 0;
}
