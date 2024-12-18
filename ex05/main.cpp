#include "Vector.hpp"
#include "linalg.h"
#include "test.h"

int main(void) {
	TEST_TITLE("Test cosine");
	try {
		std::cout << std::showpoint;
		{
			Vector<float> u1 = {1.0f, 0.0f};
			Vector<float> u2 = {1.0f, 0.0f};

			float cos = angle_cos(u1, u2);
			// 1.0
			std::cout << cos << std::endl;
		}

		std::cout << std::endl;

		{
			Vector<float> u1 = {1.0f, 0.0f};
			Vector<float> u2 = {0.0f, 1.0f};

			float cos = angle_cos(u1, u2);
			// 0.0
			std::cout << cos << std::endl;
		}

		std::cout << std::endl;

		{
			Vector<float> u1 = {-1.0f, 1.0f};
			Vector<float> u2 = {1.0f, -1.0f};

			float cos = angle_cos(u1, u2);
			// -1.0
			std::cout << cos << std::endl;
		}

		std::cout << std::endl;

		{
			Vector<float> u1 = {2.0f, 1.0f};
			Vector<float> u2 = {4.0f, 2.0f};

			float cos = angle_cos(u1, u2);
			// 1.0
			std::cout << cos << std::endl;
		}

		std::cout << std::endl;

		{
			Vector<float> u1 = {1.0f, 2.0f, 3.0f};
			Vector<float> u2 = {4.0f, 5.0f, 6.0f};

			float cos = angle_cos(u1, u2);
			// 0.974631846
			std::cout << cos << std::endl;
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
