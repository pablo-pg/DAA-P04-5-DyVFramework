/**
 * @file merge_sort.h
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

#include <vector>
#include "./algorithm.h"

template<class T>
class MergeSort : public Algorithm<std::vector<T>, std::vector<T>> {
  using Algorithm<std::vector<T>, std::vector<T>>::Algorithm;
  bool Small();
  std::vector<T> SolveSmall(std::vector<T> p, int size);
  std::vector<std::vector<T>> Divide(std::vector<T> p);
  std::vector<T> Combine(std::vector<std::vector<T>> s);
};

#endif  // MERGE_SORT_H_
