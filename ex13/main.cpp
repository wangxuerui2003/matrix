#include "Vector.hpp"
#include "linalg.h"
#include "test.h"

int main(void) {
	TEST_TITLE("Test rank");
	try {
		{
			Matrix<float> u = {
				{1.0f, 0.0f, 0.0f},
				{0.0f, 1.0f, 0.0f},
				{0.0f, 0.0f, 1.0f},
			};

			// 3
			std::cout << u.rank() << std::endl;
		}

		std::cout << std::endl;

		{
			Matrix<float> u = {
				{1.0f, 2.0f, 0.0f, 0.0f},
				{2.0f, 4.0f, 0.0f, 0.0f},
				{-1.0f, 2.0f, 1.0f, 1.0f},
			};

			// 2
			std::cout << u.rank() << std::endl;
		}

		std::cout << std::endl;

		{
			Matrix<float> u = {
				{8.0f, 5.0f, -2.0f},
				{4.0f, 7.0f, 20.0f},
				{7.0f, 6.0f, 1.0f},
				{21.0f, 18.0f, 7.0f},
			};

			// 3
			std::cout << u.rank() << std::endl;
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
