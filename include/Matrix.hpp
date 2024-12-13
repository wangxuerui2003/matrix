#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <utility>
#include <iostream>
#include <vector>
#include <initializer_list>
#include <exception>

template <typename K>
class Vector;

// Transformation of space
template<typename K>
class Matrix {
	public:
		Matrix(const std::initializer_list<std::initializer_list<K> >& values);
		Matrix(const std::initializer_list<K>& values);
		Matrix(size_t rows, size_t cols, K value);

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

		Matrix<K> operator-(K k);
		Matrix<K> operator+(const Matrix<K>& other);
		Matrix<K> operator+(K k);
		Matrix<K> operator-(const Matrix<K>& other);
		Matrix<K> operator*(K k);
		Matrix<K> operator*(const Matrix<K>& other);
		Matrix<K> operator/(float t);
		Matrix<K> operator/(const Matrix<K>& other);

		// linear map, matrix multiplication
		Vector<K> mul_vec(Vector<K> vec) const;
		Matrix<K> mul_mat(Matrix<K> mat) const;

		// trace
		K trace(void) const;

	private:
		// For operator[][] on a matrix
		class RowProxy {
		private:
			float* rowStart;
			size_t rowLength;

		public:
			RowProxy(float* start, size_t length) : rowStart(start), rowLength(length) {}

			float& operator[](size_t col) {
				if (col >= rowLength) {
					throw std::out_of_range("Column index out of range");
				}
				return rowStart[col];
			}

			const float& operator[](size_t col) const {
				if (col >= rowLength) {
					throw std::out_of_range("Column index out of range");
				}
				return rowStart[col];
			}
		};

	public:
		RowProxy operator[](size_t row) {
			if (row >= _rows) {
				throw std::out_of_range("Row index out of range");
			}
			return RowProxy(&_data[row * _cols], _cols);
		}

		const RowProxy operator[](size_t row) const {
			if (row >= _rows) {
				throw std::out_of_range("Row index out of range");
			}
			return RowProxy(&_data[row * _cols], _cols);
		}

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