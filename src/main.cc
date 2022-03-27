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
#include <chrono>
#include "../include/miscellany.h"
#include "../include/divide.h"
#include "../include/generate_rand.h"

void debugExe();

int main() {
  std::string mode;
  bool debug = false;
  std::cout << "Modo 1: normal\nModo 2: debug\nElija un modo: ";
  std::cin >> mode;
  if (mode == "2" || mode == "debug" || mode == "DEBUG") {
    debug = true;
  }
  if (debug) {
    debugExe();
    return 0;
  }
  Divide<MergeSort<int>, std::vector<int>, std::vector<int>> Merge;
  // Divide<QuickSort<int>, std::vector<int>, std::vector<int>> Quick;
  std::vector<int> prob = randomVector<int>(4, 10);
  // for (auto a : prob) std::cout << a << " ";
  // std::cout << Merge.Equation() << std::endl;
  // std::cout << "Orig: ";
  // for (auto x : prob) std::cout << x << " ";
  // std::cout << std::endl;
  auto start = std::chrono::high_resolution_clock::now();
  std::vector<int> result = Merge.Solve(prob, prob.size());
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "Time taken by MergeSort: "
            << static_cast<double>(duration.count()) / 1.0e3 << "ms"
            << std::endl;
  // std::cout << "Resu: ";
  // for (auto x : result) std::cout << x << " ";
  // std::cout << std::endl;
  return 0;
}



void debugExe() {
  enum Algorithms {mergeSort, quickSort};
  std::cout << "Algoritmo 1: MergeSort\nAlgoritmo 2: QuickSort\n"
            << "Elija un algoritmo: ";
  std::string alg;
  std::cin >> alg;
  Algorithms chosen_alg;
  if (alg == "1" || alg == "merge sort" || alg == "mergesort" ||
      alg == "Mergesort" || alg == "MergeSort") {
    chosen_alg = mergeSort;
  } else {
    chosen_alg = quickSort;
  }
  std::string size;
  std::cout << "Tamaño del problema: ";
  std::cin >> size;
  int problemSize = std::stoi(size);
  std::vector<int> prob = randomVector<int>(problemSize, problemSize);
  std::cout << "Secuencia original: " << std::endl;
  for (auto x : prob) std::cout << x << " ";
  std::cout << "\nSecuencia final: " << std::endl;
  std::vector<int> result;
  if (chosen_alg == mergeSort) {
    Divide<MergeSort<int>, std::vector<int>, std::vector<int>> Solver;
    result = Solver.Solve(prob, prob.size());
  } else {
    // Divide<QuicSort<int>, std::vector<int>, std::vector<int>> Solver;
    // result = Solver.Solve(prob, prob.size());
  }
  for (auto x : result) std::cout << x << " ";
  std::cout << std::endl;
}
