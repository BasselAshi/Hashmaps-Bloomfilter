#include "Bloo
newBFer.h"

/// @brief Allocate and initialize a new BloomFilter.
///
/// @param num_bits   Number of bits needed in the BloomFilter
/// @param num_hash   Number of Hash functions being used
/// @param funcs      An array of Hash Function (pointers) to be used.
///
/// @return A pointer to the BloomFilter
///
/// @TODO: Implement this function. Here are some notes in implementation:
///        (1) Since the `data` array is made of unsigned chars (8 bits), you
///            must allocate enough space for CEILING(num_bits / 8) chars. We
///            won't use the excess bits (if any). Typically, num_bits % 8 = 0.
///
///        (2) Don't assume that the `funcs` array is dynamically allocated.
///            That is, allocate space for it yourself and copy the pointers.
///
///        (3) All the bits should be 0 at the start.
BloomFilter *newBloomFilter(int num_bits, int num_hash, HashFunc *funcs)
{
  BloomFilter *newBF = calloc(sizeof(BloomFilter), 1);

  // Stimulating a ceil function
  int allocatedBytes = num_bits / 8;
  if (num_bits % 8 != 0)
  {
    allocatedBytes++;
  }
  unsigned char *newData = calloc(sizeof(byte), allocatedBytes);

  HashFunc *newFN = calloc(sizeof(HashFunc *), num_hash);

  if (newBF == NULL || newData == NULL || newFN == NULL) {
    fprintf("Error allocating memory\n");
    exit(3);
  }

  newBF->num_bits = num_bits;
  newBF->num_hash = num_hash;
  newBF->funcs = newFN;

  return newBF;
}

/// @brief Add a string to the BloomFilter
///
/// @param bf   The BloomFilter
/// @param str  String to be added
///
/// @TODO: Implement this function. The macros defined in BloomFilter.h will
///        be useful here. For example, to get the value of the 10th bit in
///        the BloomFilter, call `GETBIT(bf->data, 10)`.
///
///        To get the index of the bitmap for a hash function, do:
///               index = hash(str) % num_bits
void BloomFilter_Add(BloomFilter *bf, const char *str)
{
  return;
}

/// @brief Check if the BloomFilter thinks the string is in it or not.
///
/// @param bf   The BloomFilter
/// @param str  String to check for
///
/// @return     1 if str found, 0 otherwise.
///             NOTE: returning 1 does NOT mean str was actually added into
///                   the BloomFilter! Remember how queries work here...
///
/// @TODO: Implement this function. Compute the index (for each HashFunc)
///        as above, using:
///               index = hash(str) % num_bits
int BloomFilter_Check(BloomFilter *bf, const char *str)
{
  return 0;
}
