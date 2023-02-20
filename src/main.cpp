#include "Vector.hpp"
// using namespace std;

int main() {
  // containers::vector<int> vec(10,5);
  // int arr[] = { 10, 20, 30, 40, 60 };
  // int n = sizeof(arr) / sizeof(arr[0]);
  // containers::vector<int> vec2(arr, arr + n);
  // cout << "arr "<<(arr[0]) << '\n';
  // cout << "arr + n"<<(&arr+n) << '\n';
  
  // containers::vector<int> vec3(vec);
  // cout << "start:  ";
  containers::vector<int> vec{1,2,3,4,5,6,7,8, 9};
  containers::vector<int> vec2(vec.begin(), vec.end());
  containers::vector<int> vec4 = vec + vec2;
  std::cout << "vec4:  ";
  for (auto i : vec4) {
    std::cout << i << " ";
  }
  std::cout << '\n';
  std::cout << "size: " << vec4.len() << '\n';
  


  return 0;
}