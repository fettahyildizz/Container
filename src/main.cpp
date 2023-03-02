#include "Vector.hpp"
#include <chrono>
#include <vector>
// using namespace std;
using namespace std::chrono;

int main() {
	// containers::vector<int> vec(10,5);
	// int arr[] = { 10, 20, 30, 40, 60 };
	// int n = sizeof(arr) / sizeof(arr[0]);
	// containers::vector<int> vec2(arr, arr + n);
	// cout << "arr "<<(arr[0]) << '\n';
	// cout << "arr + n"<<(&arr+n) << '\n';

	// containers::vector<int> vec3(vec);
	// cout << "start:  ";
	auto start = high_resolution_clock::now();
	containers::vector<int> vec{ 1,2, 3};
	vec.emplace(vec.begin(), 100);
	cout << "vec: " << '\n';
	for (auto i : vec) {
		std::cout << i << " ";
	}
	/*for (int i = 0; i < 10000; i++) {
		vec.emplace(vec.begin(), 100);
	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << " container::vector emplace10000 timesDuration (microseconds)" << duration.count() << endl;
	
	
	auto start2 = high_resolution_clock::now();
	std::vector<int> vec2{ 1 };
	for (int i = 0; i < 10000; i++) {
		vec2.emplace(vec2.begin(), 100);
	}

	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop2 - start2);

	cout << " std::vector pushback 1.000.000 timesDuration (microseconds)" << duration2.count() << endl;
	*/
	//std::cout << "vec:  ";
	//for (auto i : vec) {
	//	std::cout << i << " ";
	//}




	return 0;
}