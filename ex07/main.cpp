#include "Vector.hpp"
#include "linalg.h"
#include "test.h"

int main(void) {
	TEST_TITLE("Test linear map/transformation (multiply a vector to matrix / transform a vector with a matrix)");
	try {
		std::cout << std::showpoint;
		{
			Matrix<float> u = {
				{1.0f, 0.0f},
				{0.0f, 1.0f}
			};
			Vector<float> v = {4.0f, 2.0f};
			
			// [4.0, 2.0]
			std::cout << u.mul_vec(v) << std::endl;
		}

		{
			Matrix<float> u = {
				{2.0f, 0.0f},
				{0.0f, 2.0f}
			};
			Vector<float> v = {4.0f, 2.0f};
			
			// [8.0, 4.0]
			std::cout << u.mul_vec(v) << std::endl;
		}

		{
			Matrix<float> u = {
				{2.0f, -2.0f},
				{-2.0f, 2.0f}
			};
			Vector<float> v = {4.0f, 2.0f};
			
			// [4.0, -4.0]
			std::cout << u.mul_vec(v);
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	TEST_SPLIT();

	TEST_TITLE("Test matrix multiplication (product of 2 matrices / combining linear transformation)");
	try {
		std::cout << std::showpoint;
		{
			Matrix<float> u = {
				{1.0f, 0.0f},
				{0.0f, 1.0f}
			};
			Matrix<float> v = {
				{1.0f, 0.0f},
				{0.0f, 1.0f}
			};
			
			// [1.0, 0.0]
			// [0.0, 1.0]
			std::cout << u.mul_mat(v) << std::endl;
		}

		{
			Matrix<float> u = {
				{1.0f, 0.0f},
				{0.0f, 1.0f}
			};
			Matrix<float> v = {
				{2.0f, 1.0f},
				{4.0f, 2.0f}
			};
			
			// [2.0, 1.0]
			// [4.0, 2.0]
			std::cout << u.mul_mat(v) << std::endl;
		}

		{
			Matrix<float> u = {
				{3.0f, -5.0f},
				{6.0f, 8.0f}
			};
			Matrix<float> v = {
				{2.0f, 1.0f},
				{4.0f, 2.0f}
			};
			
			// [-14.0, -7.0]
			// [44.0, 22.0]
			std::cout << u.mul_mat(v);
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
