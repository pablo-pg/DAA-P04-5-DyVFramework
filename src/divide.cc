/**
 * @file divide.inl
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DIVIDE_CC_
#define DIVIDE_CC_

#include "./../include/divide.h"

template <class Alg, class Prob, class Sol>
Sol Divide<Alg, Prob, Sol>::Solve(Prob p, int size) const {
  if (algorithm_->Small(p)) {
    return algorithm_->SolveSmall(p);
  }
  std::vector<Prob> divided = algorithm_->Divide(p);
  std::vector<Sol> sols;
  // for (int i = 0; )
  Sol s1 = algorithm_->Solve(divided[0], size / 2);
  sols.push_back(s1);
  Sol s2 = algorithm_->Solve(divided[1], size / 2);
  sols.push_back(s2);
  Sol solution = algorithm_->Combine(sols);
  return solution;
}


#endif  //< DIVIDE_CC_
