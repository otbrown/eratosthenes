#ifndef SIEVE_H
#define SIEVE_H

#include <bitset>
#include <cmath>

const std::size_t bsetIndex(const std::size_t);
template <std::size_t N>
std::size_t eratosthenes(const unsigned long long, std::bitset<N>&);
#include "sieve.tpp"

#endif