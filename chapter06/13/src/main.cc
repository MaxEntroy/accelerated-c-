#include "inc/graph.h"
#include <string>
#include <vector>

int main (void) {
    std::vector<std::string> top;
    std::vector<std::string> bottom;
    std::vector<std::string> top_ret;
    std::vector<std::string> bottom_ret;

    init_graph(&top);
    init_graph(&bottom);

    std::vector<std::string> ret = vcat2(top, bottom);
    std::vector<std::string> ret_frame;
    frame_graph(ret, &ret_frame);

    show_graph(ret_frame);

    return 0;
}

