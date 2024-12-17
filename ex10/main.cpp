#include "Vector.hpp"
#include "linalg.h"
#include "test.h"

int main(void) {
	TEST_TITLE("Test row echelon form");
	try {
		std::cout << std::showpoint;
		{
			Matrix<float> u = {
				{1.0f, 0.0f, 0.0f},
				{0.0f, 1.0f, 0.0f},
				{0.0f, 0.0f, 1.0f},
			};

			std::cout << u.row_echelon() << std::endl;
		}

		{
			Matrix<float> u = {
				{1.0f, 2.0f},
				{3.0f, 4.0f}
			};

			std::cout << u.row_echelon() << std::endl;
		}

		{
			Matrix<float> u = {
				{1.0f, 2.0f},
				{2.0f, 4.0f}
			};

			std::cout << u.row_echelon() << std::endl;
		}

		{
			Matrix<float> u = {
				{8.0f, 5.0f, -2.0f, 4.0f, 28.0f},
				{4.0f, 2.5f, 20.0f, 4.0f, -4.0f},
				{8.0f, 5.0f, 1.0f, 4.0f, 17.0f},
			};

			std::cout << u.row_echelon() << std::endl;
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
