#ifndef ACCELERATED_CPP_CHAPTER06_13_INC_GRAPH_H_
#define ACCELERATED_CPP_CHAPTER06_13_INC_GRAPH_H_
#include <string>
#include <vector>

void init_graph(std::vector<std::string>* ret);

void frame_graph(const std::vector<std::string>& g, std::vector<std::string>* ret);

void show_graph(const std::vector<std::string>& g);

std::vector<std::string> vcat(const std::vector<std::string>& top,
                              const std::vector<std::string>& bottom);

std::vector<std::string> vcat1(const std::vector<std::string>& top,
                               const std::vector<std::string>& bottom);

std::vector<std::string> vcat2(const std::vector<std::string>& top,
                               const std::vector<std::string>& bottom);


#endif
