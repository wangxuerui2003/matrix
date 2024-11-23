#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <utility>
#include <iostream>
#include <vector>
#include <initializer_list>
#include <cmath>

template <typename K>
class Matrix;

template<typename K>
class Vector {
	public:
		Vector(size_t dim, K v);
		Vector(const std::initializer_list<K>& values);
		Vector(const std::vector<K>& values);

		Vector(const Vector<K>& copy);
		Vector<K>& operator=(const Vector<K>& copy);
		virtual ~Vector();

		static Vector<K> from(const std::initializer_list<K>& values);

		// member functions
		size_t size(void) const;
		Matrix<K> reshapeToMatrix(void) const;

		// getters and setters
		const std::vector<K>& getData(void) const;
		void setCoord(size_t dim, K value);

		// exceptions
		class VectorException : public std::exception {
			public:
				VectorException();
				VectorException(const std::string& msg);
				const char *what() const noexcept;
			private:
				std::string _message;
		};

		// Linear Operations
		void add(const Vector<K>& v);
		void sub(const Vector<K>& v);
		void scl(const K& a);

		Vector<K> operator+(K k);
		Vector<K> operator+(const Vector<K>& other);
		Vector<K> operator-(K k);
		Vector<K> operator-(const Vector<K>& other);
		Vector<K> operator*(K k);
		Vector<K> operator*(const Vector<K>& other);
		Vector<K> operator/(K k);
		Vector<K> operator/(const Vector<K>& other);

	private:
		std::vector<K> _data;
		size_t _size;
};

// overload output operator to print out the vector
template <typename K>
std::ostream& operator<<(std::ostream& os, const Vector<K>& vec);

#include "Vector.tpp"

#include "Matrix.hpp"

#endif