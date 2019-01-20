#include <affinity_propagation/AffinityPropagation.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const std::string filename = "/home/little/ML/loc-gowalla_edges.txt";
const int user_count = 196591;

void writeResult(const std::string &fname, const std::vector<int> &v) {
  std::ofstream out(fname);
  for (size_t i = 0; i < v.size(); ++i)
    out << i << " " << v[i] << std::endl;
}

#if 1
int main() {
  const int size = user_count;

  std::cout << "Start reading data" << std::endl;
  Graph g(filename, size);
  std::cout << "Finish reading data" << std::endl;

  AffinityPropagation ap;
  auto c = ap.clustering(g, true, 200);

  writeResult("out.txt", c);
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
  auto c = ap.clustering(g, 100);

  for (auto cc : c) {
    std::cout << cc << " ";
  }

  writeResult("out.txt", c);

  std::cout << std::endl;
  return 0;
}
#endif
