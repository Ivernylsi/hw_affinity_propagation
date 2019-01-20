#include "affinity_propagation/AffinityPropagation.hpp"
#include <algorithm>
#include <iostream>
#include <tbb/tbb.h>

std::vector<int> AffinityPropagation::clustering(Graph &g, const int T) {
  for (int iteration = 0; iteration < T; ++iteration) {
    printf("Iteration № %d \n", iteration);
    fillResponsobility(g);
    printf("Fill responsobility\n");
    fillAvaliability(g);
    printf("Fille avaliability\n");
  }
  return fillClusters(g);
}

void AffinityPropagation::fillResponsobility(Graph &g) {
  tbb::parallel_for_each(g.nodes.begin(), g.nodes.end(), [&](auto &e) {
    float new_elem = -1e+10;
    for (auto in_idx : g.in_idx[e.in]) {
      auto out = g.nodes[in_idx];
      if (out.out != e.out)
        new_elem = std::max(new_elem, out.a + out.s);
    }

    if (new_elem == -1e+10)
      new_elem = 0;
    new_elem = e.s - new_elem;

    e.r = e.r * l + (1 - l) * new_elem;
  });
}

void AffinityPropagation::fillAvaliability(Graph &g) {
  tbb::parallel_for_each(g.nodes.begin(), g.nodes.end(), [&](auto &e) {
    float sum = 0.0f;
    for (auto out_idx : g.out_idx[e.out]) {
      auto &out = g.nodes[out_idx];

      if (out.in != e.out && out.in != e.in)
        sum += std::max(0.0f, out.r);
    }
    if (e.in == e.out)
      e.a = e.a * l + (1 - l) * sum;
    else {
      float rkk = g.getDiagonal(e.out).r;

      e.a = e.a * l + (1 - l) * std::min(0.0f, rkk + sum);
    }
  });
}

std::vector<int> AffinityPropagation::fillClusters(const Graph &g) {
  std::vector<int> c(g.getSize(), -1);
  tbb::parallel_for(int(0), int(g.getSize()), [&](int &i) {
    int arg_max = i;
    float max = -1e+10;
    for (int in_idx : g.in_idx[i]) {
      auto node = g.nodes[in_idx];
      if (max < node.r + node.a)
        max = node.r + node.a, arg_max = node.out;
    }
    c[i] = arg_max;
  });
  return c;
}
