// g++ -fprofile-arcs -ftest-coverage -g hello.cpp -o hello
// gcov hello.cpp
// gcov hello

#include <iostream>

int main(int argc, const char *argv[]) {
  if(argc == 1) {
    std::cout << "Hello, world!" << std::endl;
  } else {
    std::cout << "This can't be called!" << std::endl;
  }
  return 0;
}