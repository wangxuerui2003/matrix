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
		virtual ~Vector();

		// member functions
		size_t size(void) const;
		Matrix<K> reshapeToMatrix(void) const;

		// getters and setters
		const std::vector<K>& getData(void) const;

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

	private:
		std::vector<K> _data;
		size_t _size;
};

template <typename K>
std::ostream& operator<<(std::ostream& os, const Vector<K>& vec);

#include "Vector.tpp"

#include "Matrix.hpp"

#endif