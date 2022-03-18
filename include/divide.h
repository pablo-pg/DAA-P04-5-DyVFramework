/**
 * @file divide.h
 * @author Pablo Pérez González
 * @brief 
 * @version 0.1
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DIVIDE_H_
#define DIVIDE_H

#include <string>
#include <vector>

#include "./algorithm.h"
#include "./merge_sort.h"
#include "./quick_sort.h"

template <class T>
class Divide {
 public:
  Divide(std::vector<int> problem);
  void Solve() const;
  std::string Equation() conast;
 private:
  std::vector<int> problem_;
  T* algorithm_;
};

#include "../src/divide.inl"

#endif  // DIVIDE_H_
