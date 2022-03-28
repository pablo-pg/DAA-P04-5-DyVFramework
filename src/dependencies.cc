/**
 * @file dependencies.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DEPENDENCIES_CC_
#define DEPENDENCIES_CC_

// #include "../include/dependencies.h"

// template<class T>
// std::vector<T> randomVector(int minSize, int maxSize) {
//   minSize = minSize == 0 ? 0 : minSize;
//   if (maxSize < minSize) {
//     int tempMaxSize = maxSize;
//     maxSize = minSize;
//     minSize = tempMaxSize;
//   }
//   srand(time(nullptr));
//   const int size = rand() % (maxSize - minSize + 1) + minSize;
//   std::vector<int> result;
//   result.resize(size);
//   auto f = []() -> T { return rand() % 10000; };
//   generate(result.begin(), result.end(), f);
//   return result;
// }




// template<class T>
// std::queue<table_t> ProductToTable(std::vector<T> elemets) {
//   std::queue<T> data;
//   for (auto x : elemets) {
//     data.push(x);
//   }
//   std::queue<table_t> result;
//   while (!data.empty()) {
//     T p = data.front();
//     auto size = std::to_string(std::get<0>(p));
//     auto mergeTime = std::to_string(std::get<1>(p));
//     auto quickTime = std::to_string(std::get<2>(p));
//     table_t element {size, mergeTime, quickTime};
//     data.pop();
//     result.push(element);
//   }
//   return result;
// }



// template<class T>
// void printTable(std::vector<T> elements) {
//   std::queue<table_t> data = ProductToTable(elements);
//   table_t headers{{"SIZE", "MERGE_TIME", "QUICK_TIME"}};
//   constexpr int size_wid = 15;
//   constexpr int mergeTime_wid = 20;
//   constexpr int quickTime_wid = 20;
//   auto print_line = [](table_t const& tbl) {
//     /// NO CAMBIAR. SON ARGUMENTOS QUE DECLARADOS EN EJEC, NO EN COMPILACIÓN.
//     auto const& [SIZE, MERGE_TIME, QUICK_TIME] = tbl;  //< NO SON FALLOS
//     std::cout.width(size_wid);
//     std::cout << ("| " + SIZE) << '|';
//     std::cout.width(mergeTime_wid);
//     std::cout << ("| " + MERGE_TIME) << '|';
//     std::cout.width(quickTime_wid);
//     std::cout << (' ' + QUICK_TIME) << '|';
//     std::cout << '\n';
//   };
//   constexpr int total_wid = size_wid + mergeTime_wid + quickTime_wid + column_size;
//   auto print_break = [] {
//     std::cout.width(total_wid);
//     std::cout.fill('-');
//     std::cout << "-" << '\n';
//     std::cout.fill(' ');
//   };
//   std::cout.setf(std::ios::left, std::ios::adjustfield);
//   print_break();
//   print_line(headers);
//   print_break();
//   while (!data.empty()) {
//     auto element = data.front();
//     data.pop();
//     print_line(element);
//     print_break();
//   }
// }

#endif  // DEPENDENCIES_CC_
