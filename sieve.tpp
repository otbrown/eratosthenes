#ifndef SIEVE_TPP
#define SIEVE_TPP

#include <algorithm>
#include <vector>

template <typename T>
void fillVector(std::vector<T>& vec, const T VAL) {
  std::fill(vec.begin(), vec.end(), VAL);
  return;
}

#endif