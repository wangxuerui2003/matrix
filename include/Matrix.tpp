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

// constructor from data
template<typename K>
Matrix<K>::Matrix(const std::vector<K>& data, size_t rows, size_t cols) {
	if (data.size() != rows * cols) {
		throw MatrixException("Invalid data size compared to rows and cols");
	}

	this->_data = data;
	this->_rows = rows;
	this->_cols = cols;
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
K& Matrix<K>::operator()(size_t r, size_t c) {
	if (r >= _rows || c >= _cols) {
        throw std::out_of_range("Index out of bounds");
    }
    return _data[r * _cols + c];
}

template <typename K>
const K& Matrix<K>::operator()(size_t r, size_t c) const {
	if (r >= _rows || c >= _cols) {
        throw std::out_of_range("Index out of bounds");
    }
    return _data[r * _cols + c];
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
			result[i] = std::fmaf(this->_data[i * _cols + j], vec[j], result[i]);
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
				result(i, k) = std::fmaf(this->_data[i * _cols + j], mat(j, k), result(i, k));
			}
		}
	}

	return result;
}

template <typename K>
K Matrix<K>::trace(void) const {
	if (_rows != _cols) {
		throw MatrixException("Trace only exists on square matrix.");
	}

	K t = 0;
	for (size_t i = 0; i < _rows; ++i) {
		t += _data[i * _cols + i];
	}

	return t;
}

template <typename K>
Matrix<K> Matrix<K>::transpose(void) const {
	Matrix<K> result(_cols, _rows, 0);

	for (size_t i = 0; i < _rows; ++i) {
		for (size_t j = 0; j < _cols; ++j) {
			result(j, i) = _data[i * _cols + j];
		}
	}

	return result;
}

template <typename K>
static void swapRows(std::vector<K>& data, size_t rows, size_t cols, size_t row1, size_t row2) {
	if (row1 > rows || row2 > rows) {
		return;
	}
	size_t start1 = row1 * cols;
	size_t start2 = row2 * cols;
	std::swap_ranges(data.begin() + start1, data.begin() + start1 + cols, data.begin() + start2);
}

template <typename K>
static void scaleRow(std::vector<K>& data, size_t rows, size_t cols, size_t row, float a) {
	if (row > rows) {
		return;
	}
	size_t start = row * cols;
	size_t end = row * cols + cols;
	for (size_t i = start; i < end; ++i) {
		data[i] *= a;
	}
}

template <typename K>
static void addRowScl(std::vector<K>& data, size_t rows, size_t cols, size_t dest, size_t src, float scl) {
	if (dest > rows || src > rows) {
		return;
	}

	size_t destStart = dest * cols;
	size_t srcStart = src * cols;
	for (size_t i = 0; i < cols; ++i) {
		data[destStart + i] += data[srcStart + i] * scl;
	}
}

/**
 * For each row r:
 * 		1. Find the pivot in the current column:
 * 			- Search rows from r to n − 1 to find the largest non-zero value in the column (for numerical stability).
 * 			- Swap the row with the current row if necessary.
 * 		2. Scale the row to make the pivot element 1 (optional).
 * 		3. Eliminate all rows below the pivot by subtracting multiples of the pivot row.
 * 		4. Move to the next row and column.
 */
template <typename K>
Matrix<K> Matrix<K>::row_echelon(void) {
	std::vector<K> copyData = _data;
	size_t c = 0;
	size_t r = 0;
	while (r < _rows && c < _cols) {
		// find the largest pivot in the current column to increase numerical stability
		size_t largestPivotIndex = r * _cols + c;
		for (size_t i = r + 1; i < _rows; ++i) {
			size_t p = i * _cols + c;
			if (std::abs(copyData[p]) > std::abs(copyData[largestPivotIndex])) {
				largestPivotIndex = p;
			}
		}
		if (copyData[largestPivotIndex] == 0) {
			// current column all zeros, move to next column in the same row
			c++;
			continue;
		}

		size_t largestPivotRow = (largestPivotIndex - c) / _cols;
		if (largestPivotRow != r) {
			// swap the row with the largest pivot to the current row
			swapRows<K>(copyData, _rows, _cols, r, largestPivotRow);
		}
		if (copyData[r * _cols + c] != 1) {
			scaleRow<K>(copyData, _rows, _cols, r, 1 / copyData[r * _cols + c]);
		}

		// eliminate elements below the pivot
		for (size_t i = 0; i < _rows; ++i) {
			if (i == r) {
				continue;
			}
			if (copyData[i * _cols + c] != 0) {
				addRowScl<K>(copyData, _rows, _cols, i, r, -(copyData[i * _cols + c]));
			}
		}

		// go to next row and column
		c++;
		r++;
	}

	for (size_t i = 0; i < copyData.size(); ++i) {
		if (copyData[i] == -0.0f) {
			copyData[i] = 0.0f;
		}
	}

	return Matrix<K>(copyData, _rows, _cols);
}

template <typename K>
static K detRecursive(std::vector<K>& data, size_t dim) {
	if (dim == 1) {
		return data[0];
	} else if (dim == 2) {
		return (data[0] * data[3]) - (data[1] * data[2]);
	}

	K det = 0;
	int sign = 1;
	for (size_t i = 0; i < dim; ++i) {
		std::vector<K> forRecurse;
		for (size_t j = 1; j < dim; ++j) {
			for (size_t k = 0; k < dim; ++k) {
				if (k == i) {
					continue;
				}
				forRecurse.push_back(data[j * dim + k]);
			}
		}
		det += sign * detRecursive(forRecurse, dim - 1) * data[0 * dim + i];
		sign *= -1;
	}

	return det;
}

template <typename K>
K Matrix<K>::determinant(void) {
	if (_rows != _cols) {
		throw MatrixException("Determinant undefined for non-square matrix.");
	}
	return detRecursive(_data, _rows);
}

/**
 * row reduction method
 * 
 * construct the augmented matrix [A | I]
 * and then use gaussian elimination to make the matrix into [I | A^-1]
 */
template <typename K>
Matrix<K> Matrix<K>::inverse(void) {
	if (_rows != _cols) {
		throw MatrixException("Determinant undefined for non-square matrix.");
	}

	if (this->determinant() == 0) {
		throw MatrixException("The matrix is not invertible.");
	}

	// construct the augmented matrix
	std::vector<K> A = _data;
	A.reserve(_rows * _cols * 2);
	for (size_t i = 0; i < _rows; ++i) {
		for (size_t j = 0; j < _cols; ++j) {
			if (i == j) {
				A.insert(A.begin() + i * _cols * 2 + _cols + j, 1);
			} else {
				A.insert(A.begin() + i * _cols * 2 + _cols + j, 0);
			}
		}
	}

	// get the rref for the augmented matrix
	Matrix<K> rref = Matrix<K>(A, _rows, _cols * 2).row_echelon();
	const std::vector<K>& rrefData = rref.getData();

	// extract the right part (inverse matrix) from the augmented matrix
	std::vector<K> inverseMatrix;
	inverseMatrix.reserve(_rows * _cols);
	for (size_t i = 0; i < _rows; ++i) {
		for (size_t j = 0; j < _cols; ++j) {
			inverseMatrix.push_back(rrefData[i * _cols * 2 + _cols + j]);
		}
	}

	return Matrix<K>(inverseMatrix, _rows, _cols);
}

template <typename K>
size_t Matrix<K>::rank(void) {
	Matrix<K> rref = this->row_echelon();
	const std::vector<K>& rrefData = rref.getData();

	size_t rank = 0;
	for (size_t r = 0; r < _rows; ++r) {
		for (size_t c = 0; c < _cols; ++c) {
			if (rrefData[r * _cols + c] != 0) {
				rank++;
				break;
			}
		}
	}

	return rank;
}