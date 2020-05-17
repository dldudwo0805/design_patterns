#ifndef _ABSTRACT_FACTORY_HPP
#define _ABSTRACT_FACTORY_HPP
//https://refactoring.guru/design-patterns/abstract-factory
//Have to confuse the product A1-B1, A2-B2
//How to implement
//1. Map out a matrix of distinct product types vs variants of these products.
//2. Declare abstract product interfaces for all product types, then make all concrete product classes implements.
//3. Declare the abstract factory interface with a set of creation methods for all abstract products.
//4. Implement a set of concrete factory classes.

#include "common.hpp"
namespace abstract_factory
{
  class ProductA {
  protected:
    std::string name_;
  public:
    ProductA() {
      name_ = "ProductA";
    };
    virtual std::string GetName() const {
      return name_;
    }
  };

  class ProductB {
  protected:
    std::string name_;
  public:
    ProductB() {
      name_ = "ProductB";
    }
    virtual std::string GetName() const {
      return name_;
    }
  };


  class Product_A1 :public ProductA {
  public:
    Product_A1() {
      name_ += "1";
    }
  };
  class Product_A2 :public ProductA {
  public:
    Product_A2() {
      name_ += "2";
    }
  };

  class Product_B1 : public ProductB {
  public:
    Product_B1() {
      name_ += "1";
    }
  };

  class Product_B2 :public ProductB {
  public:
    Product_B2() {
      name_ += "2";
    }
  };


  class ProductFactory {
  public:
    virtual ProductA* CreateProductA() = 0;
    virtual ProductB* CreateProductB() = 0;
  };

  class ProductFactory_1 :public ProductFactory {
  public:
    virtual ProductA* CreateProductA() {
      return new Product_A1();
    }
    virtual ProductB* CreateProductB() {
      return new Product_B1();
    }
  };

  class ProductFactory_2 :public ProductFactory {
  public:
    virtual ProductA* CreateProductA() {
      return new Product_A2();
    }
    virtual ProductB* CreateProductB() {
      return new Product_B2();
    }
  };


}



#endif // DEBUG

