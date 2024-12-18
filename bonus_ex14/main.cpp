#include "Vector.hpp"
#include "linalg.h"
#include "test.h"

int main(void) {
	TEST_TITLE("Test projection matrix");
	try {
		{
			std::cout << projection(M_PI_2, 1.0f, 1.0f, 100.0f) << std::endl;
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
