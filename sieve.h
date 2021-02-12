#ifndef SIEVE_H
#define SIEVE_H

#include <bitset>
#include <cmath>

const std::size_t bsetIndex(const std::size_t);

template <std::size_t N>
std::size_t eratosthenes(const unsigned long long SMOOTH_BOUND,
std::bitset<N>& prime_bset) {
  // every number is a prime!
  prime_bset.set();
  // 1 is not a prime
  prime_bset[bsetIndex(1)] = false;

  // start outer iteration at 3, runs to square root B
  const std::size_t I_LIM = static_cast<std::size_t>(
    std::floor(std::sqrt(SMOOTH_BOUND))
  );
  for (std::size_t i = 3; i <= I_LIM; i += 2) {
    if (prime_bset[bsetIndex(i)]) {
      for (std::size_t j = i*i; j <= SMOOTH_BOUND; j += i)
        prime_bset[bsetIndex(j)] = false;
    }
  }

  return prime_bset.count();
}

#endif