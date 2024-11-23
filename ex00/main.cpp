#include "Vector.hpp"
#include "Matrix.hpp"
#include "test.h"
#include "linalg.h"
#include <iostream>

int main(void) {
	TEST_TITLE("test printing vector and its attributes");
	try {
		Vector<float> v{1, 2, 3, 4, 5};
		size_t size = v.size();
		std::cout << "size of vector: " << size << std::endl;
		std::cout << v;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	TEST_SPLIT();

	TEST_TITLE("test printing matrix and its attributes");
	try {
		Matrix<float> m = {
			{1, 2, 3, 4, 5},
			{3, 4, 5, 6, 7},
			{7, 6, 5.5f, 6.7f, 7},
		};
		std::pair shape = m.shape();
		std::cout << "size of matrix: " << shape.first << ", " << shape.second << std::endl;
		std::cout << m;
	} catch (Matrix<float>::MatrixException& e) {
		std::cerr << e.what() << std::endl;
	}

	TEST_SPLIT();

	TEST_TITLE("test vector add, sub, scl");
	try {
		// add test
		Vector<float> v1 = {1, 2, 3, 4, 5};
		Vector<float> v2 = {0, 5, 1, 2, 6};
		Vector<float> v3 = {1, 3, 5, 7, 9};
		v1.add(v2);
		std::cout << v1;
		std::cout << std::endl;
		v1.sub(v3);	
		std::cout << v1;
		std::cout << std::endl;
		v1.scl(5);	
		std::cout << v1;
		std::cout << std::endl;
	} catch (Vector<float>::VectorException& e) {
		std::cerr << e.what() << std::endl;
	}

	TEST_SPLIT();

	TEST_TITLE("test matrix add, sub, scl");
	try {
		// add test
		Matrix<float> m1 = {
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9}
		};
		Matrix<float> m2 {
			{2, 3, 4},
			{8, 9, 0},
			{42, 42, 42}
		};
		Matrix<float> m3 {
			{1, 1, 1},
			{2, 2, 2},
			{42, 42, 42}
		};
		m1.add(m2);
		std::cout << m1;
		std::cout << std::endl;
		m1.sub(m3);	
		std::cout << m1;
		std::cout << std::endl;
		m1.scl(5);	
		std::cout << m1;
		std::cout << std::endl;
	} catch (Matrix<float>::MatrixException& e) {
		std::cerr << e.what() << std::endl;
	}
}