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
			sum = std::fmaf(data[dim], coefs[index], sum);
		}
		result.setCoord(dim, sum);
	}

	return result;
}

template <typename V>
V lerp(V u, V v, float t) {
	if constexpr (std::is_arithmetic_v<V>) {
		return std::fmaf(v - u, t, u);
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

	K p0 = std::fmaf(u[1], v[2], -(std::fmaf(u[2], v[1], 0)));
	K p1 = std::fmaf(u[2], v[0], -(std::fmaf(u[0], v[2], 0)));
	K p2 = std::fmaf(u[0], v[1], -(std::fmaf(u[1], v[0], 0)));
	return {p0, p1, p2};
}

Matrix<float> projection(float fov, float ratio, float near, float far) {
	float scale = 1.0f / tanf32(fov / 2);
	float xproj = scale / ratio;
	float yproj = scale;
	float z_depth_scale = -far / (far - near);
	float z_depth_offset = (-near * far) / (far - near);
	float perspective_sign = -1;

	// row major order
	// return {
	// 	{xproj, 0, 0, 0},
	// 	{0, yproj, 0, 0},
	// 	{0, 0, z_depth_scale, z_depth_offset},
	// 	{0, 0, perspective_sign, 0}
	// };

	// column major order
	return {
		{xproj, 0, 0, 0},
		{0, yproj, 0, 0},
		{0, 0, z_depth_scale, perspective_sign},
		{0, 0, z_depth_offset, 0}
	};
}