#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <utility>
#include <iostream>
#include <vector>
#include <initializer_list>
#include <exception>
#include <algorithm>

template <typename K>
class Vector;

// Transformation of space
template<typename K>
class Matrix {
	public:
		Matrix(const std::initializer_list<std::initializer_list<K> >& values);
		Matrix(const std::initializer_list<K>& values);
		Matrix(size_t rows, size_t cols, K value);
		Matrix(const std::vector<K>& data, size_t rows, size_t cols);

		Matrix(const Matrix<K>& copy);
		Matrix& operator=(const Matrix<K>& copy);
		virtual ~Matrix();

		// member functions
		std::pair<size_t, size_t> shape(void) const;
		bool isSquare(void) const;
		Vector<K> reshapeToVector(void) const;

		// getters and setters
		const std::vector<K>& getData(void) const;

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

		// for accessing a certain element of the matrix, essentially just [][] on 2D array.
		K& operator()(size_t r, size_t c);
		const K& operator()(size_t r, size_t c) const;

		Matrix<K> operator+(const Matrix<K>& other);
		Matrix<K> operator-(const Matrix<K>& other);
		Matrix<K> operator*(K k);
		Matrix<K> operator*(const Matrix<K>& other);

		// linear map, matrix multiplication
		Vector<K> mul_vec(Vector<K> vec) const;
		Matrix<K> mul_mat(Matrix<K> mat) const;

		// trace
		K trace(void) const;

		// transpose
		Matrix<K> transpose(void) const;

		// row echelon form
		Matrix<K> row_echelon(void);
		
		// determinant
		K determinant(void);

		// inverse
		Matrix<K> inverse(void);

		// rank
		size_t rank(void);

	private:
		std::vector<K> _data;
		size_t _rows;
		size_t _cols;
};

template <typename K>
std::ostream& operator<<(std::ostream& os, const Matrix<K>& m);

#include "Matrix.tpp"

#include "Vector.hpp"

#endif