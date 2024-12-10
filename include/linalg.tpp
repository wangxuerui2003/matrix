#include "Vector.hpp"
#include "Matrix.hpp"

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

template <typename V>
V lerp(V u, V v, float t) {
	if constexpr (std::is_arithmetic_v<V>) {
		return std::fma(v - u, t, u);
	}
	return u + (v - u) * t;
}

template <typename K>
float angle_cos(Vector<K>& u, Vector<K>& v) {
	return u.dot(v) / (u.norm() * v.norm());
}

template <typename K>
Vector<K> cross_product(Vector<K>& u, Vector<K>& v) {
	if (u.size() != 3 || v.size() != 3) {
		throw std::invalid_argument("Both vector u and v should be 3D.");
	}

	K p0 = std::fma(u[1], v[2], -(std::fma(u[2], v[1], 0)));
	K p1 = std::fma(u[2], v[0], -(std::fma(u[0], v[2], 0)));
	K p2 = std::fma(u[0], v[1], -(std::fma(u[1], v[0], 0)));
	return {p0, p1, p2};
}
