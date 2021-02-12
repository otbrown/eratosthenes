#ifndef SIEVE_H
#define SIEVE_H

#include <vector>

template <typename T>
void fillVector(std::vector<T>&, const T);
#include "sieve.tpp"

std::size_t countTrue(const std::vector<bool>&);
const std::size_t bsetIndex(const std::size_t);
std::size_t eratosthenes(const unsigned long long, std::vector<bool>&);

#endif