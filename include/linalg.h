#ifndef LINALG_H
#define LINALG_H

#include "Vector.hpp"
#include "Matrix.hpp"
#include <type_traits>

// linear combination (ex01)
template <typename K>
Vector<K> linearCombination(std::vector<Vector<K> >& u, std::vector<K>& coefs);

template <typename K>
float angle_cos(Vector<K>& u, Vector<K>& v);

// linear interpolation (ex02)
template <typename V>
V lerp(V u, V v, float t);

#include "linalg.tpp"

#endif