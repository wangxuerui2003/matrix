#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <utility>
#include <iostream>
#include <vector>
#include <initializer_list>

template <typename K>
class Matrix;

template<typename K>
class Vector {
	public:
		Vector(const std::initializer_list<K>& values);
		Vector(const std::vector<K>& values);

		Vector(const Matrix<K>& copy);
		Vector& operator=(const Vector<K>& copy);
		virtual ~Vector() {}

		// member functions
		size_t size(void) const {
			return _size;
		}

		Matrix<K> reshapeToMatrix(void) const;

	private:
		std::vector<K> _data;
		size_t _size;
};

template <typename K>
std::ostream& operator<<(std::ostream& os, const Vector<K>& vec) {
	for (const K& v : vec) {
		os << "[" << v << "]\n";
	}
	os << std::endl;
	return os;
}

#include "Vector.tpp"

#include "Matrix.hpp"

#endif