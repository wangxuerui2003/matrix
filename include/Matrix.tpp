#include "Matrix.hpp"

// default constructor
template<typename K>
Matrix<K>::Matrix(const std::initializer_list<std::initializer_list<K> >& values) {
	if (values.size() == 0) {
		throw MatrixException();
	}

	size_t cols = 0;
	for (const std::initializer_list<K>& row : values) {
		if (cols != 0 && row.size() != cols) {
			throw MatrixException();
		}
		cols = row.size();
		_data.emplace_back(row);
	}

	this->_rows = values.size();
	this->_cols = cols;
}

// 1 row constructor
template<typename K>
Matrix<K>::Matrix(const std::initializer_list<K>& values) {
	if (values.size() == 0) {
		throw MatrixException();
	}

	this->_data.emplace_back(values);
	this->_rows = 1;
	this->_cols = values.size();
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
	// TODO
	return Vector<K>{1, 2, 3};
}

template <typename K>
std::ostream& operator<<(std::ostream& os, const Matrix<K>& m) {
	const std::vector<std::vector<K> >& data = m.getData();

	for (const std::vector<K>& row : data) {
		os << "[";
		for (size_t i = 0; i < row.size(); ++i) {
			os << row[i];
			if (i != row.size() - 1) {
				os << ", ";
			}
		}
		os << "]" << std::endl;
	}

	return os;
}

template<typename K>
Matrix<K>::MatrixException::MatrixException() : _message("Invalid matrix operation.") {}

template<typename K>
Matrix<K>::MatrixException::MatrixException(const std::string& msg) : _message(msg) {}

template<typename K>
const char *Matrix<K>::MatrixException::what() const noexcept {
	return _message.c_str();
}

template <typename K>
void Matrix<K>::add(const Matrix<K>& m) {
	std::pair<size_t, size_t> mShape = m.shape();
	if (mShape.first != _rows || mShape.second != _cols) {
		throw MatrixException("Both matrices should have the same shape when adding.");
	}

	const std::vector<std::vector<K> >& mData = m.getData();
	for (size_t i = 0; i < mData.size(); ++i) {
		for (size_t j = 0; j < _cols; ++j) {
			this->_data[i][j] += mData[i][j];
		}
	}
}

template <typename K>
void Matrix<K>::sub(const Matrix<K>& m) {
	std::pair<size_t, size_t> mShape = m.shape();
	if (mShape.first != _rows || mShape.second != _cols) {
		throw MatrixException("Both matrices should have the same shape when substracting.");
	}

	const std::vector<std::vector<K> >& mData = m.getData();
	for (size_t i = 0; i < mData.size(); ++i) {
		for (size_t j = 0; j < _cols; ++j) {
			this->_data[i][j] -= mData[i][j];
		}
	}
}

template <typename K>
void Matrix<K>::scl(const K& a) {
	for (size_t i = 0; i < _rows; ++i) {
		for (size_t j = 0; j < _cols; ++j) {
			_data[i][j] *= a;
		}
	}
}
