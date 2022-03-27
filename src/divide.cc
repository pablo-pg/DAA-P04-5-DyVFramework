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
void Divide<Alg, Prob, Sol>::setProblem(Prob problem) {
  problem_ = problem;
}


template <class Alg, class Prob, class Sol>
Sol Divide<Alg, Prob, Sol>::Solve(Prob p, int size) const {
  if (algorithm_->Small(p)) {
    // std::cout << " a " << std::endl;
    return algorithm_->SolveSmall(p);
  }
  std::vector<Prob> divided = algorithm_->Divide(p);
  std::vector<Sol> sols;
  // for (int i = 0; )
  Sol s1 = Solve(divided[0], size / 2);
  sols.push_back(s1);
  Sol s2 = Solve(divided[1], size / 2);
  sols.push_back(s2);
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
