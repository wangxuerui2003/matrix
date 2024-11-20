#include "Vector.hpp"

// default constructor with dim dimensions and all values v
template<typename K>
Vector<K>::Vector(size_t dim, K v) : _data(dim, v), _size(dim) {
	if (dim <= 0) {
		throw std::invalid_argument("Dimension should be greater than 0.");
	}
}


// initializer list constructor
template<typename K>
Vector<K>::Vector(const std::initializer_list<K>& values) : _data(values), _size(values.size()) {}

// copy constructor
template<typename K>
Vector<K>::Vector(const Vector<K>& copy) {
	*this = copy;
}

// copy assignment operator overload
template<typename K>
Vector<K>& Vector<K>::operator=(const Vector<K>& copy) {
	_size = copy.size();
	_data = copy.getData();
	return *this;
}

// destructor
template<typename K>
Vector<K>::~Vector() {}

template<typename K>
const std::vector<K>& Vector<K>::getData(void) const {
	return _data;
}

template<typename K>
void Vector<K>::setCoord(size_t dim, K value) {
	if (dim >= _data.size()) {
		throw std::out_of_range("Index out of range");
	}
	_data[dim] = value;
}


template<typename K>
size_t Vector<K>::size(void) const {
	return _size;
}

template<typename K>
Matrix<K> Vector<K>::reshapeToMatrix(void) const {
	// TODO
	return Matrix<K>{_data};
}

template <typename K>
std::ostream& operator<<(std::ostream& os, const Vector<K>& vec) {
	const std::vector<K>& data = vec.getData();
	for (size_t i = 0; i < data.size(); ++i) {
		os << '[' << data[i] << ']' << std::endl;
	}
	return os;
}

template<typename K>
Vector<K>::VectorException::VectorException() : _message("Invalid vector operation.") {}

template<typename K>
Vector<K>::VectorException::VectorException(const std::string& msg) : _message(msg) {}

template<typename K>
const char *Vector<K>::VectorException::what() const noexcept {
	return _message.c_str();
}

template <typename K>
void Vector<K>::add(const Vector<K>& v) {
	if (this->_size != v.size()) {
		throw VectorException("Both vector should have the same size when adding.");
	}

	const std::vector<K>& vData = v.getData();
	for (size_t i = 0; i < vData.size(); ++i) {
		this->_data[i] += vData[i];
	}
}

template <typename K>
void Vector<K>::sub(const Vector<K>& v) {
	if (this->_size != v.size()) {
		throw VectorException("Both vector should have the same size when substracting.");
	}

	const std::vector<K>& vData = v.getData();
	for (size_t i = 0; i < vData.size(); ++i) {
		this->_data[i] -= vData[i];
	}
}

template <typename K>
void Vector<K>::scl(const K& a) {
	for (size_t i = 0; i < this->_data.size(); ++i) {
		this->_data[i] *= a;
	}	
}

template <typename K>
Vector<K> linearCombination(std::vector<Vector<K> >& u, std::vector<K>& coefs) {
	if (u.size() != coefs.size() || u.size() == 0) {
		throw typename Vector<K>::VectorException("Linear combination number of vectors in u not equal to number of coefs.");
	}

	size_t dimensions = u[0].size();
	Vector<K> result(dimensions, 0);
	for (size_t dim = 0; dim < dimensions; ++dim) {
		K sum = 0;
		for (size_t index = 0; index < u.size(); ++index) {
			const std::vector<K>& data = u[index].getData();
			sum = std::fma(data[dim], coefs[index], sum);
		}
		result.setCoord(dim, sum);
	}

	return result;
}