#ifndef WRITE_PRIMES_TPP
#define WRITE_PRIMES_TPP

#include <iostream>
#include <fstream>
#include <vector>
#include "write_primes.h"

void writePrimeHeader(const std::vector<bool>& BITSET) {
  constexpr std::size_t LINE_LENGTH = 75;
  std::ofstream file;

  file.open("prime_bitset.h");

  file
    << "#ifndef PRIME_BITSET_H\n"
    << "#define PRIME_BITSET_H\n"
    << "\n"
    << "#include <vector>\n"
    << "\n"
    << "const std::vector<bool> PRIME_BITSET {\n";

  std::size_t char_count = 0;
  for (auto bitIter = BITSET.begin(); bitIter < BITSET.end() - 1; ++bitIter) {
    file << *bitIter << ", ";
    char_count += 3;
    if (char_count > LINE_LENGTH) {
      file << "\n";
      char_count = 0;
    }
  }

  file 
    << *(BITSET.end() - 1) << "\n"
    << "};\n\n"
    << "#endif\n";

  file.close();

  return;
}

#endif