#include <vector>
#include <iostream>
#include "prime_bitset.h"
#include "PrimeChecker.h"

PrimeChecker::PrimeChecker() :
  BITSET(PRIME_BITSET), BOUND(2*(BITSET.size())),
  N_PRIMES(countPrimes(BOUND)), LAST_PRIME(lastPrime()) {};

PrimeChecker::PrimeChecker(const std::vector<bool>& EXT_BITSET) :
  BITSET(EXT_BITSET), BOUND(2*(BITSET.size())),
  N_PRIMES(countPrimes(BOUND)), LAST_PRIME(lastPrime()) {};

std::size_t PrimeChecker::bsetIndex(const unsigned long long N) const {
  std::size_t idx = (N-1) / 2;
  return idx;
}

unsigned long long PrimeChecker::bsetNum(const std::size_t IDX) const {
  return 2 * IDX + 1;
}

bool PrimeChecker::isPrime(const unsigned long long N) const {
  bool prime_flag = false;

  if (N > BOUND) {
    std::cerr << "Warning: number being tested for primality is " 
    << "larger than bitset bound. BOUND = " << BOUND << "." << std::endl;
  } else if (N == 2) {
    prime_flag = true;
  } else if (N % 2) {
    prime_flag = BITSET.at(bsetIndex(N));
  }

  return prime_flag;
}

std::size_t PrimeChecker::countPrimes(const unsigned long long B) const {
  std::size_t count = 0;

  for (std::size_t idx = 0; idx < bsetIndex(B); ++idx) 
    if(BITSET.at(idx)) ++count;

  return count;
}

unsigned long long PrimeChecker::nextPrime(const unsigned long long N) const {
  unsigned long long next_prime = LAST_PRIME;
  if (N >= LAST_PRIME) {
    std::cerr << "Warning: Reached last prime in set." << std::endl;
  } else {
    std::size_t idx = bsetIndex(N) + 1;
    while(!BITSET.at(idx)) {
      ++idx;
    }
    next_prime = bsetNum(idx);
  }
  return next_prime;
}

unsigned long long PrimeChecker::prevPrime(const unsigned long long N) const {
  unsigned long long prev_prime = 2;
  if (N <= 3) {
    std::cerr << "Warning: Reached first prime." << std::endl;
  } else if (N < 5) {
    prev_prime = 3;
  } else {
    std::size_t idx = bsetIndex(N) - 1;
    while (!BITSET.at(idx)) {
      --idx;
    }
    prev_prime = bsetNum(idx);
  }

  return prev_prime;
}

unsigned long long PrimeChecker::lastPrime() const {
  std::size_t idx = BITSET.size() - 1;
  while (!BITSET.at(idx)) {
    --idx;
  }
  return bsetNum(idx);
}