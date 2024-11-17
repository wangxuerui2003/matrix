#include "Matrix.hpp"

// default constructor
template<typename K>
Matrix<K>::Matrix(const std::initializer_list<std::initializer_list<K> >& values) {
	if (values.size() == 0) {
		throw InvalidShapeException();
	}

	size_t cols = 0;
	for (const std::initializer_list<K>& row : values) {
		if (cols != 0 && row.size() != cols) {
			throw InvalidShapeException();
		}
		cols = values.size();
		_data.emplace_back(row);
	}
}

// destructor
template<typename K>
Matrix<K>::~Matrix() {}

template<typename K>
const std::vector<std::vector<K> >& Matrix<K>::getData(void) const {
	return _data;
}

template<typename K>
std::pair<size_t, size_t> Matrix<K>::shape(void) const {
	return { _rows, _cols };
}

template<typename K>
bool Matrix<K>::isSquare(void) const {
	return _rows == _cols;
}

template<typename K>
Vector<K> Matrix<K>::reshapeToVector(void) const {
	if (_cols != 1) {
		throw InvalidShapeException();
	}

	// flat data
	std::vector<K> flatData;
	std::vector<std::vector<K> >& data = getData();
	for (const std::vector<K>& row : data) {
		flatData.push_back(row[0]);
	}

	return Vector<K>{flatData};
}

template<typename K>
const char *Matrix<K>::InvalidShapeException::what() const noexcept {
	return "Invalid shape of input or matrix.";
}
