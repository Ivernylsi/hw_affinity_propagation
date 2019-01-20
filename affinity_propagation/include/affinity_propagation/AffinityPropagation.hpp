#ifndef AFFINITYPROPAGATION_HPP
#define AFFINITYPROPAGATION_HPP
#include "affinity_propagation/Graph.hpp"
#include <Eigen/Eigen>
#include <vector>

class AffinityPropagation {
public:
  AffinityPropagation(const float l = 0.9) : l(l) {}
  std::vector<int> clustering(Graph &s, const int T = 100);
private:
  void fillResponsobility(Graph &s);
  void fillAvaliability(Graph &s);
  std::vector<int> fillClusters(const Graph &g);
  const float l; // dumping factor
};

#endif // AFFINITYPROPAGATION_HPP
