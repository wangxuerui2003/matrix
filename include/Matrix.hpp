#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <utility>
#include <iostream>
#include <vector>
#include <initializer_list>
#include <exception>

template <typename K>
class Vector;

template<typename K>
class Matrix {
	public:
		Matrix(const std::initializer_list<std::initializer_list<K> >& values);
		Matrix(const std::initializer_list<K>& values);

		Matrix(const Matrix<K>& copy);
		Matrix& operator=(const Matrix<K>& copy);
		virtual ~Matrix();

		// member functions
		std::pair<size_t, size_t> shape(void) const;
		bool isSquare(void) const;
		Vector<K> reshapeToVector(void) const;

		// getters and setters
		const std::vector<std::vector<K> >& getData(void) const;

		// exceptions
		class MatrixException : public std::exception {
			public:
				MatrixException();
				MatrixException(const std::string& msg);
				const char *what() const noexcept;
			private:
				std::string _message;
		};

		// linear operations
		void add(const Matrix<K>& m);
		void sub(const Matrix<K>& m);
		void scl(const K& a);

	private:
		std::vector<std::vector<K> > _data;
		size_t _rows;
		size_t _cols;
};

template <typename K>
std::ostream& operator<<(std::ostream& os, const Matrix<K>& m);

#include "Matrix.tpp"

#include "Vector.hpp"

#endif