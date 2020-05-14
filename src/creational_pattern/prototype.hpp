#ifndef _PROTOTYPE_HPP_
#define _PROTOTYPE_HPP_
//https://refactoring.guru/design-patterns/prototype
//have to add more information of this pattern
//Not all objects can be copied because of some private and not visible fields from outside.

#include "common.hpp"

typedef enum Type_ {
  PROTO_TYPE_1=0,
  PROTO_TYPE_2
}Type;

//interface class
class Prototype {
protected:
  std::string prototype_name_;
  float prototype_field_;

public:
  Prototype() {};
  Prototype(std::string prototype_name) :prototype_name_(prototype_name) {}
  virtual ~Prototype() {}
  virtual Prototype* Clone() const = 0;
  virtual void Method(float prototype_field) {
    this->prototype_field_ = prototype_field;
    std::cout << "Call Method from " << prototype_name_ << " witd field " << prototype_field_ << std::endl;
  }
};


class ConcretePrototype1 : public Prototype {
private:
  float concrete_prototype_field1_;
public:
  ConcretePrototype1(std::string prototype_name, float_t concrete_prototype_field) :
    Prototype(prototype_name), concrete_prototype_field1_(concrete_prototype_field) {}

  Prototype* Clone()const override {
    return new ConcretePrototype1(*this);
  }

};

class ConcretePrototype2 :public Prototype {
private:
  float concrete_prototype_field2_;
public:
  ConcretePrototype2(std::string prototype_name, float_t concrete_prototype_field) :
    Prototype(prototype_name), concrete_prototype_field2_(concrete_prototype_field) {}

  Prototype* Clone()const override {
    return new ConcretePrototype2(*this);
  }
};


class PrototypeFactory {
private:
  std::unordered_map<Type, Prototype*, std::hash<int>> prototypes_;

public:
  PrototypeFactory() {
    prototypes_[Type::PROTO_TYPE_1] = new ConcretePrototype1("Prototype_1", 5);
    prototypes_[Type::PROTO_TYPE_2] = new ConcretePrototype2("Prototype_2", 6);
  }


  Prototype* CreatePrototype(Type type) {
    return prototypes_[type]->Clone();
  }
};




#endif // !_PROTOTYPE_HPP_

