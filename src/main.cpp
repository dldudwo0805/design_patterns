#include <iostream>
#include "creational_pattern/creational_common.hpp"

int main(int argc, char** argv) {
  
   builder::Director* director = new builder::Director();
  builder::ClientCode(*director);
  delete director;
  
  return 0;
}