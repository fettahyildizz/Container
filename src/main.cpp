#include "Vector.hpp"
#include <vector>
int main() {
	containers::vector<int> asd(10, 10);
	for (auto i : asd) {
		std::cout << i << " ";
	}
	std::cout << "size: " << asd.len() << '\n';
	std::cout << '\n';
	asd.push_back(44);
	//containers::vector<int> *asd = new containers::vector<int>(10);
	for (auto i : asd) {
		std::cout << i << " ";
	}
	std::cout << "size: " << asd.len() << '\n';

	return 0;
}