#include "Vector.hpp"

// default constructor
template<typename K>
Vector<K>::Vector(const std::initializer_list<K>& values) : _data(values) {
	this->_size = values.size();
}

// destructor
template<typename K>
Vector<K>::~Vector() {}

template<typename K>
const std::vector<K>& Vector<K>::getData(void) const {
	return _data;
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