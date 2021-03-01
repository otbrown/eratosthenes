#include <iostream>
#include <vector>
#include "sieve.h"
#include "write_primes.h"

int main (void)
{
  constexpr unsigned long long B = 100;

  std::vector<bool> prime_bset;

  const std::size_t COUNT = eratosthenes(B, prime_bset);

  // add one to bitset.count() for the number 2
  std::cout
    << "Smoothness Bound: " << B << "\n"
    << "Number of primes: " << COUNT + 1 << std::endl;

  writePrimeHeader(prime_bset);

  return 0;
}