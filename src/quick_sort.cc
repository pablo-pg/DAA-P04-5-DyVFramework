/**
 * @file quick_sort.cc
 * @author Pablo Pérez González (alu0101318318)
 * @brief 
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef QUICK_SORT_CC_
#define QUICK_SORT_CC_

#include "../include/quick_sort.h"

template<class T>
bool QuickSort<T>::Small(std::vector<T> p) const {
  return p.size() == 1;
}

template<class T>
std::vector<T> QuickSort<T>::SolveSmall(std::vector<T> p) {
  return p;
}

template<class T>
std::vector<std::vector<T>> QuickSort<T>::Divide(std::vector<T> p) {
  std::vector<std::vector<T>> divided;
  T first = p[0];
  T med = p[p.size() / 2];
  T last = p[p.size() - 1];
  T pivote = p[1];
  if (first < med) {
    if (last < first) {
      pivote = first;
    } else {
      pivote = last;
    }
  } else {
    if (last < med) {
      pivote = med;
    } else {
      pivote = last;
    }
  }
  // std::cout << "POSIBLES -" << first << " - " << med << " - " << last << std::endl;
  std::vector<T> minors;
  std::vector<T> biggers;
  for (T x : p) {
    if (x < pivote) {
      minors.push_back(x);
    } else if (x > pivote) {
      biggers.push_back(x);
    }
  }
  if (minors.size() != 0) divided.push_back(minors);
  divided.push_back(std::vector<T> {pivote});
  if (biggers.size() != 0) divided.push_back(biggers);
// std::cout << "\nPIVOTE ----" << pivote << std::endl;
// for (int i{0}; i < divided.size(); ++i) {
// std::cout << "[NUEVO " << i << std::endl << " ";
// for (auto x : divided[i]) std::cout << x << " ";
// std::cout << std::endl;
// }
  return divided;
}

template<class T>
std::vector<T> QuickSort<T>::Combine(std::vector<std::vector<T>> s) {
  std::vector<T> result;
  for (auto x : s) {
    for (auto y : x) {
      result.push_back(y);
    }
  }
  return result;
}

#endif  // QUICK_SORT_CC_
