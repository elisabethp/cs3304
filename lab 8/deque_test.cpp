#include "deque.h"
#include <cassert>
#include <iostream>

int main () {

  deque<int> ex1;
  assert (ex1.empty());
  assert(ex1.size() == 0);
  assert(!ex1.full());
  
  std::cout << ex1 << std::endl;
  std::cout << "first set passed." << std::endl;
  
  ex1.push_front(6);
  ex1.push_front(8); 
  ex1.push_front(10);
  ex1.push_back(1);
  
  assert(ex1.front() == 10);
  assert(ex1.back() == 1);
  assert (!ex1.empty());
  assert(ex1.size() == 4);
  
  std::cout << ex1 << std::endl;
  std::cout << "second set passed." << std::endl;
  
  ex1.pop_front();
  ex1.pop_back();
  assert(ex1.front() == 8);
  assert(ex1.back() == 6);
  
  std::cout << ex1 << std::endl;
  std::cout << "third set passed." << std::endl;
  
  ex1.push_front(5);
  ex1.push_front(4);
  ex1.push_front(3);
  ex1.push_back(1);
  ex1.push_front(2);
  ex1.push_front(7);
  ex1.push_front(10);
  ex1.push_back(9);
  
  assert(ex1.full());
  
  std::cout << ex1 << std::endl;
  std::cout << "fourth set passed." << std::endl;
  
  deque<int> ex2;
  
  ex2.push_front(9);
  ex2.push_front(1);
  ex2.push_front(6);
  ex2.push_front(8);
  ex2.push_front(5);
  ex2.push_front(4);
  ex2.push_front(3);
  ex2.push_front(2);
  ex2.push_front(7);
  ex2.push_front(10);
  
  assert(ex1 == ex2);
  
  std::cout << ex1;
  
  std::cout << "all tests passed" << std::endl;
  return 0;
}