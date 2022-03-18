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

#include "../include/divide.h"

template <class T>
void Divide<T>::Solve(Problem p, int size) {
  if (algorithm->Small(p)) {
    return algorithm->SolveSmall(p);
  }
  Problem[] = algorithm->Divide(p);
  for (int i = 0; )
}