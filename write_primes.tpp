#ifndef WRITE_PRIMES_TPP
#define WRITE_PRIMES_TPP

#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include "write_primes.h"

template <std::size_t N>
void writePrimeHeader(const std::bitset<N>& BITSET) {
  std::ofstream file;

  file.open("prime_bitset.h");

  file
    << "#ifndef PRIME_BITSET_H\n"
    << "#define PRIME_BITSET_H\n"
    << "\n"
    << "#include <bitset>\n"
    << "\n"
    << "const std::bitset<" << N << "> PRIME_BITSET(\n"
    << "\"" << BITSET << "\"\n"
    << ");\n\n"
    << "#endif\n";

  file.close();

  return;
}

#endif