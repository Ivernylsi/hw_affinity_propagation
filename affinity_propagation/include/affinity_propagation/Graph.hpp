#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <string>
#include <vector>

struct Node {
  Node(int in, int out, float s) : in(in), out(out), s(s) {}
  int in;
  int out;
  float s = 0.0; // similiarity
  float r = 0.0; // responsobility
  float a = 0.0; // avaliability
  friend std::ostream &operator<<(std::ostream &out, const Node &c) {
    out << c.in << " " << c.out << " " << c.s << " " << c.r << " " << c.a
        << std::endl;
    return out;
  }
};

using Nodes = std::vector<Node>;
using Indexes = std::vector<std::vector<int>>;
struct Graph {
  Nodes nodes;
  Indexes in_idx;
  Indexes out_idx;
  Graph(const std::string &fname, const int size);

  Node getDiagonal(const int Idx) { return nodes[start_diagonal + Idx]; }
  int getSize() const { return size; }

private:
  const int size;
  int start_diagonal;
};

#endif // GRAPH_HPP
