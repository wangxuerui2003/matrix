#include "Vector.hpp"
#include "linalg.h"
#include "test.h"

int main(void) {
	TEST_TITLE("Test linear interpolation");
	try {
		// 0.0
		std::cout << lerp(0.0f, 1.0f, 0.0f) << std::endl;

		std::cout << std::endl;

		// 1.0
		std::cout << lerp(0.0f, 1.0f, 1.0f) << std::endl;

		std::cout << std::endl;

		// 0.5
		std::cout << lerp(0.0f, 1.0f, 0.5f) << std::endl;

		std::cout << std::endl;

		// 27.3
		std::cout << lerp(21.0f, 42.0f, 0.3f) << std::endl;

		std::cout << std::endl;

		// [2.6]
		// [1.3]
		std::cout << lerp(Vector({2.0f, 1.0f}), Vector({4.0f, 2.0f}), 0.3);

		std::cout << std::endl;

		// [[11., 5.5]
		// [16.5, 22.]]
		std::cout << lerp(Matrix({{2.0f, 1.0f}, {3.0f, 4.0f}}), Matrix({{20.0f, 10.0f}, {30.0f, 40.0f}}), 0.5);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}