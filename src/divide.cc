/**
 * @file divide.inl
 * @author Pablo Pérez González (alu0101318318)
 * @brief 
 * @version 0.1
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DIVIDE_CC_
#define DIVIDE_CC_

#include "../include/divide.h"

template <class Alg, class Prob, class Sol>
Divide<Alg, Prob, Sol>::Divide() {
  algorithm_ = new Alg;
}


template <class Alg, class Prob, class Sol>
Divide<Alg, Prob, Sol>::~Divide() {
  delete algorithm_;
}

template <class Alg, class Prob, class Sol>
Sol Divide<Alg, Prob, Sol>::Solve(Prob p, int size, int& calls) const {
  if (algorithm_->Small(p)) {
    return algorithm_->SolveSmall(p);
  }
  std::vector<Prob> divided = algorithm_->Divide(p);
  std::vector<Sol> sols;
  for (size_t i = 0; i < divided.size(); ++i) {
    ++calls;
    Sol s1 = Solve(divided[i], size / 2, calls);
    sols.push_back(s1);
  }
  Sol solution = algorithm_->Combine(sols);
  return solution;
}

template <class Alg, class Prob, class Sol>
std::string Divide<Alg, Prob, Sol>::Equation() const {
  std::stringstream eq;
  eq << "T(n) = " << algorithm_->getA() << "T(1/" << algorithm_->getB() + ")" <<
       " + " <<
       ((algorithm_->getC() == std::to_string(1)) ? "" :algorithm_->getC()) <<
       "n";
  return eq.str();
}


#endif  //< DIVIDE_CC_
