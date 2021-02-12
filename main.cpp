#include <bitset>
#include <iostream>
#include "sieve.h"

int main (void)
{
  constexpr unsigned long long B = 10000;
  constexpr unsigned long long N_ODDS = (B+1) / 2; // int div truncates to zero

  std::bitset<N_ODDS> prime_bset;

  const std::size_t COUNT = eratosthenes(B, prime_bset);

  // add one to bitset.count() for the number 2
  std::cout
    << "Smoothness Bound: " << B << "\n"
    << "Number of primes: " << COUNT + 1 << std::endl;

  return 0;
}