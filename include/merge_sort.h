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
 public:
  // using Algorithm<std::vector<T>, std::vector<T>>::a_;
  using Algorithm<std::vector<T>, std::vector<T>>::Algorithm;
  // MergeSort() {this->a_ = "2";}
  MergeSort() : Algorithm<std::vector<T>, std::vector<T>>("2","2","1") {}
  bool Small();
  std::vector<T> SolveSmall(std::vector<T> p, int size);
  std::vector<std::vector<T>> Divide(std::vector<T> p);
  std::vector<T> Combine(std::vector<std::vector<T>> s);
};

#include "../src/merge_sort.cc"

#endif  // MERGE_SORT_H_
