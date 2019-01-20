#include "affinity_propagation/Graph.hpp"
#include <fstream>

Graph::Graph(const std::string &fname, const int size) : size(size) {
  in_idx.resize(size);
  out_idx.resize(size);

  std::ifstream f(fname);

  int i = 0;
  for (;; ++i) {
    int c, r;
    f >> r >> c;
    if (f.eof())
      break;

    nodes.emplace_back(r, c, 1.0f);
    in_idx[r].push_back(i);
    out_idx[c].push_back(i);
  }

  start_diagonal = i;

  for (int j = 0; j < size; ++j, ++i) {
    nodes.emplace_back(j, j, -1.0f);
    in_idx[j].push_back(i);
    out_idx[j].push_back(i);
  }
}
