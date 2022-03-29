/**
 * @file algorithm.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Interface of an Divide and Conquer algorithm
 * 
 * @tparam Prob The type of the problem values set
 * @tparam Sol The type of the solution values set
 */
template<class Prob, class Sol>
class Algorithm {
 public:
  /**
   * @brief Construct a new Algorithm object
   * 
   * @param a The number of times the algorithms calls itself
   * @param b How the size of the data changes while is dividing
   * @param c The complexity of divide and combine the data
   */
  Algorithm(std::string a, std::string b, std::string c) :
      a_(a), b_(b), c_(c), treeLevels_(0) {}

  /**
   * @brief Check if a problem is enough smaller depending the algorithm
   * 
   * @param p The set of values to check if is small
   * @return true Is small
   * @return false Other case
   */
  virtual bool Small(Prob p) const = 0;

  /**
   * @brief Compute the solution of the small set of values
   * 
   * @param p The set of values to solve
   * @return Sol The solution after solve the problem
   */
  virtual Sol SolveSmall(Prob p) = 0;

  /**
   * @brief Divide a not small problem into smaller problems
   * 
   * @param p The problem to divide
   * @return std::vector<Sol> A vector subproblems from the original problem
   */
  virtual std::vector<Sol> Divide(Prob p) = 0;

  /**
   * @brief Combine the partial solutions
   * 
   * @param s The partial solutions
   * @return Sol The final solution after combine the parts
   */
  virtual Sol Combine(std::vector<Sol> s) = 0;

  std::string getA() const {return a_;}
  std::string getB() const {return b_;}
  std::string getC() const {return c_;}
  int getTreeLevels() const {return treeLevels_;}   //< MODI
  void resetTreeLevels() {treeLevels_ = 0;}

 protected:
  std::string a_;
  std::string b_;
  std::string c_;
  int treeLevels_;    //< MODI
};

#endif  // ALGORITHM_H_
