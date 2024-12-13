#include "Matrix.hpp"

// default constructor
template<typename K>
Matrix<K>::Matrix(const std::initializer_list<std::initializer_list<K> >& values) {
	if (values.size() == 0) {
		throw MatrixException("Matrix can't have size 0.");
	}

	size_t cols = 0;
	for (const std::initializer_list<K>& row : values) {
		if (cols != 0 && row.size() != cols) {
			throw MatrixException("Matrix rows have different number of columns.");
		}
		cols = row.size();
		_data.insert(_data.end(), row.begin(), row.end());
	}

	this->_rows = values.size();
	this->_cols = cols;
}

// 1 row constructor
template<typename K>
Matrix<K>::Matrix(const std::initializer_list<K>& values) {
	if (values.size() == 0) {
		throw MatrixException("Matrix can't have size 0.");
	}

	this->_data.emplace_back(values);
	this->_rows = 1;
	this->_cols = values.size();
}

// matrix with size constructor
template <typename K>
Matrix<K>::Matrix(size_t rows, size_t cols, K value) {
	if (rows == 0 || cols == 0) {
		throw MatrixException("Matrix can't be 0 rows or 0 cols.");
	}
	this->_rows = rows;
	this->_cols = cols;
	this->_data.resize(rows * cols, value);
}

// copy constructor
template<typename K>
Matrix<K>::Matrix(const Matrix<K>& copy) {
	*this = copy;
}

// copy assignment operator overload
template<typename K>
Matrix<K>& Matrix<K>::operator=(const Matrix<K>& copy) {
	const std::pair<size_t, size_t> shape = copy.shape();
	_rows = shape.first;
	_cols = shape.second;
	_data = copy.getData();
	return *this;
}

// destructor
template<typename K>
Matrix<K>::~Matrix() {}

template<typename K>
const std::vector<K>& Matrix<K>::getData(void) const {
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
	const std::vector<K>& data = m.getData();
	const std::pair<size_t, size_t> shape = m.shape();
	size_t rows = shape.first;
	size_t cols = shape.second;

	for (size_t i = 0; i < rows; ++i) {
		os << "[";
		for (size_t j = 0; j < cols; ++j) {
			os << data[i * cols + j];
			if (j != cols - 1) {
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

	const std::vector<K>& mData = m.getData();
	for (size_t i = 0; i < mData.size(); ++i) {
		_data[i] += mData[i];
	}
}

template <typename K>
void Matrix<K>::sub(const Matrix<K>& m) {
	std::pair<size_t, size_t> mShape = m.shape();
	if (mShape.first != _rows || mShape.second != _cols) {
		throw MatrixException("Both matrices should have the same shape when substracting.");
	}

	const std::vector<K>& mData = m.getData();
	for (size_t i = 0; i < mData.size(); ++i) {
		_data[i] -= mData[i];
	}
}

template <typename K>
void Matrix<K>::scl(const K& a) {
	for (size_t i = 0; i < _data.size(); ++i) {
		_data[i] *= a;
	}
}

template <typename K>
Matrix<K> Matrix<K>::operator+(const Matrix<K>& other) {
	Matrix<K> result(*this);
	result.add(other);
	return result;
}

template <typename K>
Matrix<K> Matrix<K>::operator-(const Matrix<K>& other) {
	Matrix<K> result(*this);
	result.sub(other);
	return result;
}

template <typename K>
Matrix<K> Matrix<K>::operator*(K k) {
	Matrix<K> result(*this);
	result.scl(k);
	return result;
}

template <typename K>
Vector<K> Matrix<K>::mul_vec(Vector<K> vec) const {
	if (_cols != vec.size()) {
		throw MatrixException("You can only transform/map a vector with size equal to the number of columns of this matrix.");
	}

	Vector<K> result(_rows, 0);

	// O(nm)
	for (size_t i = 0; i < _rows; ++i) {
		for (size_t j = 0; j < _cols; ++j) {
			result[i] = std::fma(this->_data[i * _cols + j], vec[j], result[i]);
		}
	}

	return result;
}

template <typename K>
Matrix<K> Matrix<K>::mul_mat(Matrix<K> mat) const {
	std::pair<size_t, size_t> shape = mat.shape();
	size_t mat_rows = shape.first;
	size_t mat_cols = shape.second;

	if (_cols != mat_rows) {
		throw MatrixException("You can only multiply a matrix with a matrix having same number of rows as its columns");
	}

	Matrix<K> result(_rows, mat_cols, 0);

	// O(pmn)
	for (size_t k = 0; k < mat_cols; ++k) {
		for (size_t i = 0; i < _rows; ++i) {
			for (size_t j = 0; j < _cols; ++j) {
				result[i][k] = std::fma(this->_data[i * _cols + j], mat[j][k], result[i][k]);
			}
		}
	}

	return result;
}