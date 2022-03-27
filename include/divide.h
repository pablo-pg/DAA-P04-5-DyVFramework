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
#define DIVIDE_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "./algorithm.h"
#include "./merge_sort.h"
#include "./quick_sort.h"

template <class Alg, class Prob, class Sol>
class Divide {
 public:
  Divide();
  ~Divide();
  void setProblem(Prob problem);
  Sol Solve(Prob prbolem, int size) const;
  std::string Equation() const;
 private:
  Prob problem_;
  Alg* algorithm_;
};

#include "../src/divide.cc"

#endif  // DIVIDE_H_
