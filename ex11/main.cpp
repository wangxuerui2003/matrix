#include "Vector.hpp"
#include "linalg.h"
#include "test.h"

int main(void) {
	TEST_TITLE("Test determinant");
	try {
		std::cout << std::showpoint;
		{
			Matrix<float> u = {
				{1.0f, -1.0f},
				{-1.0f, 1.0f},
			};

			// 0.0
			std::cout << u.determinant() << std::endl;
		}

		std::cout << std::endl;

		{
			Matrix<float> u = {
				{2.0f, 0.0f, 0.0f},
				{0.0f, 2.0f, 0.0f},
				{0.0f, 0.0f, 2.0f},
			};

			// 8.0
			std::cout << u.determinant() << std::endl;
		}

		std::cout << std::endl;

		{
			Matrix<float> u = {
				{8.0f, 5.0f, -2.0f},
				{4.0f, 7.0f, 20.0f},
				{7.0f, 6.0f, 1.0f},
			};

			// -174.0
			std::cout << u.determinant() << std::endl;
		}

		std::cout << std::endl;

		{
			Matrix<float> u = {
				{8.0f, 5.0f, -2.0f, 4.0f},
				{4.0f, 2.5f, 20.0f, 4.0f},
				{8.0f, 5.0f, 1.0f, 4.0f},
				{28.0f, -4.0f, 17.0f, 1.0f},
			};

			// 1032.0
			std::cout << u.determinant() << std::endl;
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
