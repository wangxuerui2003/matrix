#ifndef LINALG_H
#define LINALG_H

#include "Vector.hpp"
#include "Matrix.hpp"
#include <type_traits>

// linear combination (ex01)
template <typename K>
Vector<K> linearCombination(std::vector<Vector<K> >& u, std::vector<K>& coefs);

// linear interpolation (ex02)
template <typename V>
V lerp(V u, V v, float t);

// cosine (ex05)
template <typename K>
float angle_cos(Vector<K>& u, Vector<K>& v);

// cross product (ex06)
template <typename K>
Vector<K> cross_product(Vector<K>& u, Vector<K>& v);

// bonus: projection
Matrix<float> projection(float fov, float ratio, float near, float far);

#include "linalg.tpp"

#endif