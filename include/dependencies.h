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
#include <array>
#include <iostream>
#include <queue>
#include <random>
#include <string>
#include <vector>


constexpr int column_size = 5;

/**
 * @brief Alias to the printable datatype
 * 
 */
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

/**
 * @brief Generates a queue of a std::array with the string values to print
 * 
 * @tparam T the type of the data. In this exercise will be tuple<int, double, double>
 * @param elemets A set of values to print
 * @return std::queue<table_t> Parsed data to printable type
 */
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
    auto mergeCalls = std::to_string(std::get<3>(p));    //< MODI
    auto quickCalls = std::to_string(std::get<4>(p));    //< MODI
    table_t element {size, mergeTime, quickTime, mergeCalls, quickCalls};    //< MODI
    data.pop();
    result.push(element);
  }
  return result;
}

/**
 * @brief Prints a table of the sizes and the time of each sort method
 * 
 * @tparam T the type of the data. In this exercise will be tuple<int, double, double>
 * @param elements The values to print
 */
template<class T>
void printTable(std::vector<T> elements) {
  std::queue<table_t> data = ProductToTable(elements);
  table_t headers{{"SIZE", "MERGE TIME(ms)", "QUICK TIME(ms)", "MERGE CALLS", "QUICK CALLS"}};
  constexpr int size_wid = 10;
  constexpr int mergeTime_wid = 20;
  constexpr int quickTime_wid = 20;
  constexpr int mergeCalls_wid = 15;
  constexpr int quickCalls_wid = 15;
  auto print_line = [](table_t const& tbl) {
    auto const& [SIZE, MERGE_TIME, QUICK_TIME, MERGE_CALLS, QUICK_CALLS] = tbl;
    std::cout.width(size_wid);
    std::cout << ("| " + SIZE) << '|';
    std::cout.width(mergeTime_wid);
    std::cout << ("| " + MERGE_TIME) << '|';
    std::cout.width(quickTime_wid);
    std::cout << (' ' + QUICK_TIME) << '|';
    std::cout.width(mergeCalls_wid);
    std::cout << (' ' + MERGE_CALLS) << '|';
    std::cout.width(quickCalls_wid);
    std::cout << (' ' + QUICK_CALLS) << '|';
    std::cout << '\n';
  };
  constexpr int total_wid = size_wid + mergeTime_wid + quickTime_wid +
      mergeCalls_wid + quickCalls_wid + column_size;
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
