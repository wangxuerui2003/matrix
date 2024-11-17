#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <utility>
#include <iostream>
#include <vector>
#include <initializer_list>

template <typename K>
class Vector;

template<typename K>
class Matrix {
	public:
		Matrix(const std::initializer_list<std::initializer_list<K> >& values);

		// Matrix(const Matrix<K>& copy);
		// Matrix& operator=(const Matrix<K>& copy);
		virtual ~Matrix();

		// member functions
		std::pair<size_t, size_t> shape(void) const;
		bool isSquare(void) const;
		Vector<K> reshapeToVector(void) const;

		// getters and setters
		const std::vector<std::vector<K> >& getData(void) const;

		// exceptions
		class InvalidShapeException : public std::exception {
			const char *what() const noexcept;
		};

	private:
		std::vector<std::vector<K> > _data;
		size_t _rows;
		size_t _cols;
};

template <typename K>
std::ostream& operator<<(std::ostream& os, const Matrix<K>& m) {
	const std::vector<std::vector<K> >& data = m.getData();

	for (const std::vector<K>& row : data) {
		os << "[";
		for (const K& v : row) {
			os << v << ", ";
		}
		os << "]\n";
	}
	os << std::endl;

	return os;
}

#include "Matrix.tpp"

#include "Vector.hpp"

#endif