#include "Vector.hpp"
#include "linalg.h"
#include "test.h"
#include <iostream>
#include <iomanip>

int main(void) {
	TEST_TITLE("Test dot product");
	try {
		{
			Vector u = {0.0f, 0.0f};
			Vector v = {1.0f, 1.0f};
			std::cout << std::fixed << std::setprecision(1) << u.dot(v) << std::endl;
		}

		{
			Vector u = {1.0f, 1.0f};
			Vector v = {1.0f, 1.0f};
			std::cout << std::fixed << std::setprecision(1) << u.dot(v) << std::endl;
		}

		{
			Vector u = {-1.0f, 6.0f};
			Vector v = {3.0f, 2.0f};
			std::cout << std::fixed << std::setprecision(1) << u.dot(v) << std::endl;
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
