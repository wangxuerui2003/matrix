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
