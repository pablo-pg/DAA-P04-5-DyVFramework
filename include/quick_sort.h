/**
 * @file quick_sort.h
 * @author Pablo Pérez González (alu0101318318)
 * @brief 
 * @version 0.1
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

#include <vector>
#include "./algorithm.h"

template<class T>
class QuickSort : public Algorithm<std::vector<T>, std::vector<T>> {
 public:
  using Algorithm<std::vector<T>, std::vector<T>>::Algorithm;
  QuickSort() : Algorithm<std::vector<T>, std::vector<T>>("2", "2", "1") {}
  bool Small(std::vector<T> p) const;
  std::vector<T> SolveSmall(std::vector<T> p);
  std::vector<std::vector<T>> Divide(std::vector<T> p);
  std::vector<T> Combine(std::vector<std::vector<T>> s);
};

#include "../src/quick_sort.cc"

#endif  // QUICK_SORT_H_
