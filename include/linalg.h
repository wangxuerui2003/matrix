#ifndef LINALG_H
#define LINALG_H

#include "Vector.hpp"
#include "Matrix.hpp"

// linear combination (ex01)
template <typename K>
Vector<K> linearCombination(std::vector<Vector<K> >& u, std::vector<K>& coefs);

// linear interpolation (ex02)
template <typename V>
V lerp(V u, V v, float t);

#include "linalg.tpp"

#endif