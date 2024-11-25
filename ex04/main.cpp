#include "Vector.hpp"
#include "linalg.h"
#include "test.h"

int main(void) {
	TEST_TITLE("Test norm");
	try {
		std::cout << std::showpoint;
		{
			Vector<float> u = {0.0f, 0.0f, 0.0f};
			std::cout << u.norm_1() << ' ';
			std::cout << u.norm() << ' ';
			std::cout << u.norm_inf() << std::endl;
		}

		{
			Vector<float> u = {1.0f, 2.0f, 3.0f};
			std::cout << u.norm_1() << ' ';
			std::cout << u.norm() << ' ';
			std::cout << u.norm_inf() << std::endl;
		}

		{
			Vector<float> u = {-1.0f, -2.0f};
			std::cout << u.norm_1() << ' ';
			std::cout << u.norm() << ' ';
			std::cout << u.norm_inf() << std::endl;
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
