/**
 * @file algorithm.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include <string>
#include <vector>

class Algorithm {
 public:
  virtual bool Small() = 0;
  virtual Solution SolveSmall(Problem p, int size) = 0;
  virtual Solution[] Divide(Problem) = 0;
  virtual Solution Combine(Solution[]) = 0;
  std::string getA() const;
  std::string getB() const;
  std::string getC();

 protected:
  std::string a_;
  std::string b_;
  std::string c_;
};

#endif  // ALGORITHM_H_
