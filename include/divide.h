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

/**
 * @brief Context class to execute an specific sort algorithm
 * 
 * @tparam Alg The algorithm to execute. Actually can be MergeSort or QuickSort
 * @tparam Prob The data type of the input values
 * @tparam Sol The data type of the output values
 */
template <class Alg, class Prob, class Sol>
class Divide {
 public:
  /**
   * @brief Construct a new Divide object
   * 
   */
  Divide();

  /**
   * @brief Destroy the Divide object
   * 
   */
  ~Divide();

  /**
   * @brief 
   * 
   * @param prbolem The values of the problem. Will be recursively divided
   * @param size The size of the problem, will recursively change
   * @return Sol The solution of the problem
   */
  Sol Solve(Prob prbolem, int size) const;

  /**
   * @brief Prints the T(n) equation of the algorithm
   * 
   * @return std::string The equation
   */
  std::string Equation() const;

 private:
  Alg* algorithm_;
};

#include "../src/divide.cc"

#endif  // DIVIDE_H_
