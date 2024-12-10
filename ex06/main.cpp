#include "Vector.hpp"
#include "linalg.h"
#include "test.h"

int main(void) {
	TEST_TITLE("Test cross product");
	try {
		std::cout << std::showpoint;
		{
			Vector<float> u = {0.0f, 0.0f, 1.0f};
			Vector<float> v = {1.0f, 0.0f, 0.0f};
			
			// [0, 1, 0]
			std::cout << cross_product(u, v) << std::endl;
		}

		{
			Vector<float> u = {1.0f, 2.0f, 3.0f};
			Vector<float> v = {4.0f, 5.0f, 6.0f};
			
			// [-3, 6, -3]
			std::cout << cross_product(u, v) << std::endl;
		}

		{
			Vector<float> u = {4.0f, 2.0f, -3.0f};
			Vector<float> v = {-2.0f, -5.0f, 16.0f};
			
			// [17, -58, -16]
			std::cout << cross_product(u, v);
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
