/**
 * @file main.cc
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
  #include <windows.h>
  #error No se pudo compilar en Windows
#endif  // Si se compila en Windows

#if defined(__APPLE__) && defined(__MACH__)
  #error No se pudo compilar en iOS
#endif


#include <iostream>
#include "../include/miscellany.h"
#include "../include/divide.h"
#include "../include/generate_rand.h"


int main() {
  Divide<MergeSort<int>, std::vector<int>, std::vector<int>> Merge;
  std::vector<int> prob = randomVector<int>(4, 10);
  // for (auto a : prob) std::cout << a << " ";
  Merge.setProblem(prob);
  std::cout << Merge.Equation() << std::endl;
  std::cout << "Orig: ";
  for (auto x : prob) std::cout << x << " ";
  std::cout << std::endl;
  std::vector<int> result = Merge.Solve(prob, prob.size());
  std::cout << "Resu: ";
  for (auto x : result) std::cout << x << " ";
  std::cout << std::endl;
}
