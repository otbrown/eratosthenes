#ifndef SIEVE_TPP
#define SIEVE_TPP

#include <bitset>
#include <cmath>

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

  #pragma omp parallel
  {
    std::bitset<N> thread_bset;
    thread_bset.set();
    thread_bset[0] = false;

    #pragma omp for
    for (std::size_t i = 3; i <= I_LIM; i += 2) {
      if (thread_bset[bsetIndex(i)]) {
        for (std::size_t j = i*i; j <= SMOOTH_BOUND; j += i)
          thread_bset[bsetIndex(j)] = false;
      }
    }

    #pragma omp critical
    {
      prime_bset &= thread_bset;
    }
  }

  return prime_bset.count();
}

#endif