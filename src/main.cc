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
#else
  #include <unistd.h>
#endif  // Si se compila en Windows

#if defined(__APPLE__) && defined(__MACH__)
  #error No se pudo compilar en iOS
#endif


#include <iostream>
#include <chrono>
#include <tuple>
#include "../include/miscellany.h"
#include "../include/divide.h"
#include "../include/dependencies.h"

const int VECTORS_TO_COMPUTE = 5;

void debugExe();

int main() {
  std::string mode;
  bool debug = false;
  std::cout << "Mode 1: normal\nMode 2: debug\nChoose a mode: ";
  std::cin >> mode;
  if (mode == "2" || mode == "debug" || mode == "DEBUG") {
    debug = true;
  }
  if (debug) {
    debugExe();
    return 0;
  }
  Divide<MergeSort<int>, std::vector<int>, std::vector<int>> Merge;
  Divide<QuickSort<int>, std::vector<int>, std::vector<int>> Quick;
  std::vector<std::tuple<int, double, double, int, int>> times;     //< MODI ultimos ints
  for (int i = 0; i < VECTORS_TO_COMPUTE; ++i) {
    sleep(0.005);
    std::cout << "Calculando el vector " << i + 1 << std::endl;
    std::vector<int> prob = randomVector<int>(4);

    int mergeCalls = 0;   //< MODI
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> result = Merge.Solve(prob, prob.size(), mergeCalls);
    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << "Niveles del árbol para MergeSort: " << Merge.getTreeLevels() << std::endl;
    Merge.resetTreeLevels();

    auto durationMerge =
        std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    int quickCalls = 0;   //< MODI
    start = std::chrono::high_resolution_clock::now();
    result = Quick.Solve(prob, prob.size(), quickCalls);
    stop = std::chrono::high_resolution_clock::now();
    std::cout << "Niveles del árbol para QuickSort: " << Quick.getTreeLevels() << std::endl;
    Quick.resetTreeLevels();

    auto durationQuick =
        std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    double msMerge = static_cast<double>(durationMerge.count()) / 1.0e3;
    double msQuick = static_cast<double>(durationQuick.count()) / 1.0e3;
    times.push_back(std::make_tuple(prob.size(), msMerge, msQuick, mergeCalls, quickCalls));  //< MODI
  }
  printTable<std::tuple<int, double, double, int, int>>(times);    //< MODI
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
  std::vector<int> result;
  int calls = 0;
  if (chosen_alg == mergeSort) {
    Divide<MergeSort<int>, std::vector<int>, std::vector<int>> Solver;
    result = Solver.Solve(prob, prob.size(), calls);
    std::cout << "\n\nNiveles del árbol: " << Solver.getTreeLevels() << std::endl;
  } else {
    Divide<QuickSort<int>, std::vector<int>, std::vector<int>> Solver;
    result = Solver.Solve(prob, prob.size(), calls);
    std::cout << "Niveles del árbol: " << Solver.getTreeLevels() << std::endl;
  }
  std::cout << "Llamadas recursivas: " << calls << std::endl;
  std::cout << "\nSecuencia final: " << std::endl;
  for (auto x : result) std::cout << x << " ";
  std::cout << std::endl;
}
