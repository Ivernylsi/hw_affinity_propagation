#include <Eigen/Eigen>
#include <affinity_propagation/AffinityPropagation.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const std::string filename = "/home/little/ML/loc-gowalla_edges.txt";
const int user_count = 196591;

#if 0
int main() {
  const int size = user_count;

  std::cout << "Start reading data" << std::endl;
  Graph g(filename, size); 
  std::cout << "Finish reading data" << std::endl;

  AffinityPropagation ap(size);
  auto c = ap.clustering(g, 500); 

  for(auto cc: c) {
    std::cout << cc << " ";
  }

  std::cout << std::endl;
  return 0;
}
#else
int main() {
  const int size = 9;

  std::cout << "Start reading data" << std::endl;
  Graph g("test.txt", size); 
  std::cout << "Finish reading data" << std::endl;

  AffinityPropagation ap;
  auto c = ap.clustering(g, 1); 

  for(auto cc: c) {
    std::cout << cc << " ";
  }

  std::cout << std::endl;
  return 0;
}
#endif
