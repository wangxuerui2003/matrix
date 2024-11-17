#include "Vector.hpp"
#include "Matrix.hpp"
#include <iostream>

int main(void) {
	try {
		Matrix<float> m = {
			{1, 2, 3, 4, 5},
			{3, 4, 5, 6, 7},
			{7, 6, 5.5, 6.7, 7},
		};
		std::pair shape = m.shape();
		std::cout << "size of matrix: " << shape.first << ", " << shape.second << std::endl;
		std::cout << m;
	} catch (Matrix<float>::InvalidShapeException& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Vector<float> v{1, 2, 3, 4, 5};
		size_t size = v.size();
		std::cout << "size of vector: " << size << std::endl;
		std::cout << v;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}