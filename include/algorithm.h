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

template<class Prob, class Sol>
class Algorithm {
 public:
  Algorithm(std::string a, std::string b, std::string c);
  virtual bool Small() = 0;
  virtual Sol SolveSmall(Prob p, int size) = 0;
  virtual std::vector<Sol> Divide(Prob p) = 0;
  virtual Sol Combine(std::vector<Sol> s) = 0;
  std::string getA() const;
  std::string getB() const;
  std::string getC();

 protected:
  std::string a_;
  std::string b_;
  std::string c_;
};

#endif  // ALGORITHM_H_
