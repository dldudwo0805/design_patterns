#include <iostream>
#include "creational_pattern/singleton.hpp"
#include "creational_pattern/factory_method.hpp"
#include "creational_pattern/prototype.hpp"

int main(int argc, char** argv) {

  PrototypeFactory* factory = new PrototypeFactory();
  Prototype* prototype = factory->CreatePrototype(Type::PROTO_TYPE_1);
  prototype->Method(10);

  prototype = factory->CreatePrototype(Type::PROTO_TYPE_2);
  prototype->Method(20);

  return 0;
}