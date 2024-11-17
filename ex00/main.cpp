#include "Vector.hpp"
#include "Matrix.hpp"
#include <iostream>

int main(void) {
	Matrix<float> m = {
		{1, 2},
		{3, 4}
	};

	std::cout << m;
}