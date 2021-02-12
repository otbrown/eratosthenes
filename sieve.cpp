#include "sieve.h"

const std::size_t bsetIndex(const std::size_t N) {
  std::size_t idx = 0;
  if (N%2) idx = (N-1) / 2;
  return idx;
}