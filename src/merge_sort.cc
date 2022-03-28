/**
 * @file merge_sort.cc
 * @author Pablo Pérez González (alu0101318318)
 * @brief 
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MERGE_SORT_CC_
#define MERGE_SORT_CC_

#include "../include/merge_sort.h"

template<class T>
bool MergeSort<T>::Small(std::vector<T> p) const {
  return p.size() == 1;
}

template<class T>
std::vector<T> MergeSort<T>::SolveSmall(std::vector<T> p) {
  return p;
}

template<class T>
std::vector<std::vector<T>> MergeSort<T>::Divide(std::vector<T> p) {
  std::vector<std::vector<T>> result;
  std::vector<T> left, right;
  for (size_t i = 0; i < p.size() / 2; ++i) {
    left.push_back(p[i]);
  }
  for (size_t i = p.size() / 2; i < p.size(); ++i) {
    right.push_back(p[i]);
  }
  result.push_back(left);
  result.push_back(right);
  // for (int i{0}; i < result.size(); ++i) {
  //   std::cout << "[NUEVO " << i << std::endl << " ";
  //   for (auto x : result[i]) std::cout << x << " ";
  //   std::cout << std::endl;
  // }
  return result;
}

template<class T>
std::vector<T> MergeSort<T>::Combine(std::vector<std::vector<T>> s) {
  size_t resultSize = 0;
  resultSize = s[0].size() + s[1].size();
  std::vector<T> result(resultSize);
  size_t i = 0;
  size_t j = 0;
  size_t k = 0;

  while (i < s[0].size() && j < s[1].size()) {
    if (s[0][i] <= s[1][j]) {
      result[k] = s[0][i];
      i++;
    } else {
      result[k] = s[1][j];
      j++;
    }
    k++;
  }

  while (i < s[0].size()) {
    result[k] = s[0][i];
    i++;
    k++;
  }

  while (j < s[1].size()) {
    result[k] = s[1][j];
    j++;
    k++;
  }
  return result;
}

#endif  // MERGE_SORT_CC_
