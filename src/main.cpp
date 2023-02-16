#include "Vector.hpp"
#include <vector>
int main() {
  // containers::vector<int> vec(10,5);
  int arr[] = { 10, 20, 30, 40, 60 };
  // int n = sizeof(arr) / sizeof(arr[0]);
  // containers::vector<int> vec{1,2,3,4,5,6,7,8};
  // containers::vector<int> vec(arr, arr + n);
  containers::vector<int> vec(arr);
  cout << "END \n";
  for (auto i : vec) {
    std::cout << i << " ";
  }
  vec.push_back(9);
  for (auto i : vec) {
    std::cout << i << " ";
  }
  std::cout << "size: " << vec.len() << '\n';

  return 0;
}