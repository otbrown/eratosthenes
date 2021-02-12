#ifndef WRITE_PRIMES_H
#define WRITE_PRIMES_H

#include <bitset>

template <std::size_t N>
void writePrimeHeader(const std::bitset<N>&);
#include "write_primes.tpp"

#endif