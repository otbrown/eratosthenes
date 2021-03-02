#ifndef PRIMECHECKER_H
#define PRIMECHECKER_H

#include <vector>

struct PrimeChecker {
  const std::vector<bool>& BITSET;
  const unsigned long long BOUND;
  const std::size_t N_PRIMES;
  const unsigned long long LAST_PRIME;

  PrimeChecker();
  PrimeChecker(const std::vector<bool>&);

  std::size_t bsetIndex(const unsigned long long) const;
  unsigned long long bsetNum(const std::size_t) const;
  bool isPrime(const unsigned long long) const;
  std::size_t countPrimes(const unsigned long long) const;
  unsigned long long nextPrime(const unsigned long long) const;
  unsigned long long prevPrime(const unsigned long long) const;
  unsigned long long lastPrime() const;
};

#endif