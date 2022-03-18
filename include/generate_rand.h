/**
 * @file generate_rand.h
 * @author Pablo Pérez González
 * @brief 
 * @version 0.1
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef GENERATE_RAND_H_
#define GENERATE_RAND_H_

#include <algorithm>
#include <random>
#include <vector>

/**
 * @brief Generates a random vector with a random size between to values
 * 
 * @param minSize Minimum size of the vector
 * @param maxSize Maximum size of the vector
 * @return std::vector<int> The random vector
 */
std::vector<int> randomVector(int minSize, int maxSize = 100000000000) {
  minSize = minSize == 0 ? 0 : minSize;
  if (maxSize < minSize) {
    int tempMaxSize = maxSize;
    maxSize = minSize;
    minSize = tempMaxSize;
  }
  srand(time(nullptr));
  const int size = rand() % (maxSize - minSize + 1) + minSize;
  std::vector<int> result;
  result.resize(size);
  auto f = []() -> int { return rand() % 10000; };
  generate(result.begin(), result.end(), f);
  return result;
}

#endif  // GENERATE_RAND_H_
