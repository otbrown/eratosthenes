#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
#include "sieve.h"

std::size_t countTrue(const std::vector<bool>& BOOL_VEC) {
  std::size_t count = 0;
  for (const auto& b : BOOL_VEC) if(b) ++count;
  return count;
}

const std::size_t bsetIndex(const std::size_t N) {
  std::size_t idx = 0;
  if (N%2) idx = (N-1) / 2;
  return idx;
}

std::size_t eratosthenes(const unsigned long long SMOOTH_BOUND,
std::vector<bool>& prime_bset) {
  const unsigned long long N_ODDS = (SMOOTH_BOUND+1) / 2;

  // resize to number of odds
  prime_bset.resize(N_ODDS);
  // every number is a prime!
  fillVector(prime_bset, true);
  // 1 is not a prime
  prime_bset.at(bsetIndex(1)) = false;

  // start outer iteration at 3, runs to square root B
  const std::size_t I_LIM = static_cast<std::size_t>(
    std::floor(std::sqrt(SMOOTH_BOUND))
  );

  #pragma omp parallel
  {
    std::vector<bool> thread_bset(N_ODDS, true);
    thread_bset.at(0) = false;

    #pragma omp for
    for (std::size_t i = 3; i <= I_LIM; i += 2) {
      if (thread_bset.at(bsetIndex(i))) {
        for (std::size_t j = i*i; j <= SMOOTH_BOUND; j += i)
          thread_bset.at(bsetIndex(j)) = false;
      }
    }

    #pragma omp critical
    {
      // logical and prime_bset and thread_bset and overwrite prime_bset with
      // the result
      std::transform(prime_bset.begin(), prime_bset.end(), thread_bset.begin(),
        prime_bset.begin(), std::logical_and<bool>());
    }
  }

  return countTrue(prime_bset);
}