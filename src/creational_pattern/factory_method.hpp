#ifndef _FACTORY_METHOD_HPP
#define _FACTORY_METHOD_HPP
//https://refactoring.guru/design-patterns/factory-method
//Replace direct object construction call with calls to a special factory method.
//Make  product interface class and inherit to conrete class.
//And add creator interface class and inherit conrete class.
//At each concretor creator class, call product concrete class's constructor and return there pointer
#include "common.hpp"

class Product {
public:
  virtual ~Product() {}
  virtual std::string Operation() const = 0;
};

class ConcreateProduct1 : public Product {
public:
  std::string Operation() const override{ //check override command
    return "{Result of the ConreateProduct1}";
  }
};

class ConcreateProduct2 : public Product {
public:
  std::string Operation() const override {
    return "{Result of the ConreateProduct2}";
  }
};

class Creator {
public:
  virtual ~Creator() {};
  virtual Product* FactoryMethod() const = 0;

  std::string SomeOperation() const {
    Product* product = this->FactoryMethod();
    std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
    delete product;
    return result;
  }
};

class ConreateCreator1 : public Creator {
public:
  Product* FactoryMethod() const override {
    return new ConcreateProduct1();
  }
};

class ConreateCreator2 : public Creator {
public:
  Product* FactoryMethod() const override {
    return new ConcreateProduct2();
  }
};


#endif // !_FACTORY_METHOD_HPP

