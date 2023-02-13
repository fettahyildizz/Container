#include "Vector.hpp"
#include <vector>
int main() {
  containers::vector<double> asd(10, 10.0);
  for (auto i : asd) {
    std::cout << i << " ";
  }
  asd.push_back(5.5);
  for (auto i : asd) {
    std::cout << i << " ";
  }
  std::cout << "size: " << asd.len() << '\n';

  return 0;
}