#include "Vector.hpp"
#include "linalg.h"
#include "test.h"
#include <iostream>

int main(void) {
	TEST_TITLE("Test linear combination");
	try {
		Vector<float> e1{1, 0, 0};
		Vector<float> e2{0, 1, 0};
		Vector<float> e3{0, 0, 1};

		Vector<float> v1{1, 2, 3};
		Vector<float> v2{0, 10, -100};

		std::vector<Vector<float> > u = {e1, e2, e3};
		std::vector<float> coefs = {10, -2, 0.5};
		std::cout << linearCombination<float>(u, coefs);

		std::cout << std::endl;

		u = {v1, v2};
		coefs = {10, -2};
		std::cout << linearCombination<float>(u, coefs);

		std::cout << std::endl;

		// exception
		u = {v1, v2};
		coefs = {10, -2, 0.5};
		std::cout << linearCombination<float>(u, coefs);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}