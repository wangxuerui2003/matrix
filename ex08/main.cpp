#include "Vector.hpp"
#include "linalg.h"
#include "test.h"

int main(void) {
	TEST_TITLE("Test trace");
	try {
		std::cout << std::showpoint;
		{
			Matrix<float> u = {
				{1.0f, 0.0f},
				{0.0f, 1.0f}
			};
			
			// 2.0
			std::cout << u.trace() << std::endl;
		}

		std::cout << std::endl;

		{
			Matrix<float> u = {
				{2.0f, -5.0f, 0.0f},
				{4.0f, 3.0f, 7.0f},
				{-2.0f, 3.0f, 4.0f},
			};
			
			// 9.0
			std::cout << u.trace() << std::endl;
		}

		std::cout << std::endl;

		{
			Matrix<float> u = {
				{-2.0f, -8.0f, 4.0f},
				{1.0f, -23.0f, 4.0f},
				{0.0f, 6.0f, 4.0f},
			};
			
			// -21.0
			std::cout << u.trace() << std::endl;
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
