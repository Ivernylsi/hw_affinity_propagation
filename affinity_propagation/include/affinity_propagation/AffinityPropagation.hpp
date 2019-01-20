#ifndef AFFINITYPROPAGATION_HPP
#define AFFINITYPROPAGATION_HPP
#include "affinity_propagation/Graph.hpp"
#include <vector>

class AffinityPropagation {
public:
  AffinityPropagation(const float l = 0.7) : l(l) {}
  std::vector<int> clustering(Graph &s, bool show_clusters = true, const int T = 100);
private:
  float fillResponsobility(Graph &s);
  float fillAvaliability(Graph &s);
  std::vector<int> fillClusters(const Graph &g);
  const float l; // dumping factor
};

#endif // AFFINITYPROPAGATION_HPP
