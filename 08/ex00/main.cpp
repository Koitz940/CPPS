#include <iostream>
#include <vector>
#include <iterator>

template <typename T>
int easyfind(T& container, int n) {
	for (int i = 0; container.begin() + i != container.end(); i++) {
		if (*(container.begin() + i) == n) {
			return i;
		}
	}
	return -1;
}

int main() {
	int pos;

	std::vector<int> vec(10, 0);
	for (int i = 0; i < 10; i++) {
		vec[i] = 2 * i;
	}
	
	pos = easyfind(vec, 10);
	if (pos != -1) {
		std::cout << "number 10 found in vec in position " << pos << "\n";
	} else {
		std::cout << "number 10 not found in vec\n";
	}

	pos = easyfind(vec, 5);
	if (pos != -1) {
		std::cout << "number 5 found in vec in position " << pos << "\n";
	} else {
		std::cout << "number 5 not found in vec\n";
	}

	pos = easyfind(vec, -2);
	if (pos != -1) {
		std::cout << "number -2 found in vec in position " << pos << "\n";
	} else {
		std::cout << "number -2 not found in vec\n";
	}

	pos = easyfind(vec, 0);
	if (pos != -1) {
		std::cout << "number 0 found in vec in position " << pos << "\n";
	} else {
		std::cout << "number 0 not found in vec\n";
	}

	pos = easyfind(vec, 20);
	if (pos != -1) {
		std::cout << "number 20 found in vec in position " << pos << "\n";
	} else {
		std::cout << "number 20 not found in vec\n";
	}

	pos = easyfind(vec, 22);
	if (pos != -1) {
		std::cout << "number 22 found in vec in position " << pos << "\n";
	} else {
		std::cout << "number 22 not found in vec\n";
	}
}