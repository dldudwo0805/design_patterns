#ifndef _BUILDER_HPP_
#define _BUILDER_HPP_
//https://refactoring.guru/design-patterns/builder
//Builder lets you construct complex objects step by step
//produce differenct types and representations of an object using the same construction code.

#include "common.hpp"

namespace builder
{
  class Product1 {
  public:
    std::vector<std::string> parts_;
    void ListParts() const {
      std::cout << "Product Parts: ";
      for (size_t i = 0; i < parts_.size(); i++) {
        if (parts_[i] == parts_.back())
          std::cout << parts_[i];
        else
          std::cout << parts_[i] << ", ";
      }
      std::cout << std::endl;
    }
  };

  class Builder {
  public:
    virtual ~Builder() {};
    virtual void ProducePartA() const = 0;
    virtual void ProducePartB() const = 0;
    virtual void ProducePartC() const = 0;
  };

  class ConcreteBuilder1 :public Builder {
  private:
    Product1* product_;

  public:

    ConcreteBuilder1() {
      this->Reset();
    }
    ~ConcreteBuilder1() {
      delete product_;
    }
    void Reset() {
      this->product_ = new Product1();
    }
    //Product Method
    virtual void ProducePartA() const {
      this->product_->parts_.push_back("PartA");
    }
    virtual void ProducePartB() const {
      this->product_->parts_.push_back("PartB");
    }
    virtual void ProducePartC() const {
      this->product_->parts_.push_back("PartC");
    }

    Product1* GetProduct() {
      Product1* result = this->product_;
      return result;
    }
  };


  class Director {
  private:
    Builder* builder_;

  public:

    void set_builder(Builder* builder) {
      builder_ = builder;
    }

    void BuildMinimalViableProduct() {
      builder_->ProducePartA();
    }

    void BuilderFullFeatureProduct() {
      builder_->ProducePartA();
      builder_->ProducePartB();
      builder_->ProducePartC();
    }
  };

  //다시 한번 볼 필요가 있는듯
  void ClientCode(Director& director) {
    ConcreteBuilder1* builder = new ConcreteBuilder1();
    director.set_builder(builder);
    director.BuildMinimalViableProduct();
    Product1* p = builder->GetProduct();
    p->ListParts();
    director.BuilderFullFeatureProduct();
    p->ListParts();
    delete p;

    builder->ProducePartA();
    builder->ProducePartC();
    p = builder->GetProduct();
    p->ListParts();
    delete p;

    delete builder;
  }


}//namespace builder


#endif // !_BUILDER_HPP_

