#include "Vector.hpp"
#include "linalg.h"
#include "test.h"

int main(void) {
	TEST_TITLE("Test inverse");
	try {
		{
			Matrix<float> u = {
				{1.0f, 0.0f, 0.0f},
				{0.0f, 1.0f, 0.0f},
				{0.0f, 0.0f, 1.0f},
			};

			// [1.0, 0.0, 0.0]
			// [0.0, 1.0, 0.0]
			// [0.0, 0.0, 1.0]
			std::cout << u.inverse() << std::endl;
		}

		{
			Matrix<float> u = {
				{2.0f, 0.0f, 0.0f},
				{0.0f, 2.0f, 0.0f},
				{0.0f, 0.0f, 2.0f},
			};

			// [0.5, 0.0, 0.0]
			// [0.0, 0.5, 0.0]
			// [0.0, 0.0, 0.5]
			std::cout << u.inverse() << std::endl;
		}

		{
			Matrix<float> u = {
				{8.0f, 5.0f, -2.0f},
				{4.0f, 7.0f, 20.0f},
				{7.0f, 6.0f, 1.0f},
			};

			// [0.649425287, 0.097701149, -0.655172414]
			// [-0.781609195, -0.126436782, 0.965517241]
			// [0.143678161, 0.074712644, -0.206896552]
			std::cout << u.inverse() << std::endl;
		}

		std::cout << std::endl;

		{
			Matrix<float> u = {
				{8.0f, 5.0f, -2.0f, 4.0f},
				{4.0f, 2.5f, 20.0f, 4.0f},
				{8.0f, 5.0f, 1.0f, 4.0f},
				{28.0f, -4.0f, 17.0f, 1.0f},
			};

			// [-0.224322, -0.0610465, 0.278101, 0.0290698]
			// [-2.17442, -0.302326, 2.48837, -0.0465116]
			// [-0.333333, 3.72529e-09, 0.333333, 0]
			// [3.25, 0.5, -3.5, 0]
			std::cout << u.inverse() << std::endl;
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
