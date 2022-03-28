/**
 * @file dependencies.h
 * @author Pablo Pérez González
 * @brief 
 * @version 0.2
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DEPENDENCIES_H_
#define DEPENDENCIES_H_

#include <algorithm>
#include<array>
#include <iostream>
#include <queue>
#include <random>
#include <vector>

constexpr int column_size = 3;

using table_t = std::array<std::string, column_size>;

/**
 * @brief Generates a random vector with a random size between to values
 * 
 * @param minSize Minimum size of the vector
 * @param maxSize Maximum size of the vector
 * @return std::vector<int> The random vector
 */
template<class T>
std::vector<T> randomVector(int minSize, int maxSize = 1000000) {
  minSize = minSize == 0 ? 0 : minSize;
  if (maxSize < minSize) {
    int tempMaxSize = maxSize;
    maxSize = minSize;
    minSize = tempMaxSize;
  }
  srand(time(nullptr));
  const int size = rand() % (maxSize - minSize + 1) + minSize;
  std::vector<int> result;
  result.resize(size);
  auto f = []() -> T { return rand() % 10000; };
  generate(result.begin(), result.end(), f);
  return result;
}


template<class T>
std::queue<table_t> ProductToTable(std::vector<T> elemets) {
  std::queue<T> data;
  for (auto x : elemets) {
    data.push(x);
  }
  std::queue<table_t> result;
  while (!data.empty()) {
    T p = data.front();
    auto size = std::to_string(std::get<0>(p));
    auto mergeTime = std::to_string(std::get<1>(p));
    auto quickTime = std::to_string(std::get<2>(p));
    table_t element {size, mergeTime, quickTime};
    data.pop();
    result.push(element);
  }
  return result;
}


template<class T>
void printTable(std::vector<T> elements) {
  std::queue<table_t> data = ProductToTable(elements);
  table_t headers{{"SIZE", "MERGE_TIME", "QUICK_TIME"}};
  constexpr int size_wid = 15;
  constexpr int mergeTime_wid = 20;
  constexpr int quickTime_wid = 20;
  auto print_line = [](table_t const& tbl) {
    auto const& [SIZE, MERGE_TIME, QUICK_TIME] = tbl;
    std::cout.width(size_wid);
    std::cout << ("| " + SIZE) << '|';
    std::cout.width(mergeTime_wid);
    std::cout << ("| " + MERGE_TIME) << '|';
    std::cout.width(quickTime_wid);
    std::cout << (' ' + QUICK_TIME) << '|';
    std::cout << '\n';
  };
  constexpr int total_wid = size_wid + mergeTime_wid + quickTime_wid +
      column_size;
  auto print_break = [] {
    std::cout.width(total_wid);
    std::cout.fill('-');
    std::cout << "-" << '\n';
    std::cout.fill(' ');
  };
  std::cout.setf(std::ios::left, std::ios::adjustfield);
  print_break();
  print_line(headers);
  print_break();
  while (!data.empty()) {
    auto element = data.front();
    data.pop();
    print_line(element);
    print_break();
  }
}

#endif  // DEPENDENCIES_H_
