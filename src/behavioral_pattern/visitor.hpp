#ifndef _VISITOR_HPP_
#define _VISITOR_HPP_
//https://refactoring.guru/design-patterns/visitor
//write more detail
//not understand

#include "common.hpp"

namespace visitor
{
  class ConcreteComponentA;
  class ConcreteComponentB;

  class Visitor {
  public:
    virtual void VisitConcreteComponentA(const ConcreteComponentA* element) const = 0;
    virtual void VisitConcreteComponentB(const ConcreteComponentB* element) const = 0;
  };

  class Component {
  public:
    virtual ~Component() {};
    virtual void Accept(Visitor* visitor) const = 0;
  };

  class ConcreteComponentA :public Component {
  public:
    virtual void Accept(Visitor* visitor)const {
      visitor->VisitConcreteComponentA(this);
    }
    std::string ExclusiveMethodOfConcreteComponentA() const {
      return "A";
    }
  };

  class ConcreteComponentB :public Component {
  public:
    virtual void Accept(Visitor* visitor)const {
      visitor->VisitConcreteComponentB(this);
    }
    std::string ExclusiveMethodOfConcreteComponentB() const{
      return "B";
    }
  };

  class ConcreteVisitor1 :public Visitor {
  public:
    virtual void VisitConcreteComponentA(const ConcreteComponentA* element) const {
      std::cout << element->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor1\n";
    }
    virtual void VisitConcreteComponentB(const ConcreteComponentB* element) const {
      std::cout<<element->ExclusiveMethodOfConcreteComponentB()<< " + ConcreteVisitor1\n";
    }
  };

  class ConcreteVisitor2 :public Visitor {
  public:
    virtual void VisitConcreteComponentA(const ConcreteComponentA* element) const {
      std::cout << element->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor2\n";
    }
    virtual void VisitConcreteComponentB(const ConcreteComponentB* element) const {
      std::cout << element->ExclusiveMethodOfConcreteComponentB() << " + ConcreteVisitor2\n";
    }
  };

  void ClientCode() {
    std::array<const Component*, 2> components = { new ConcreteComponentA, new ConcreteComponentB };
    std::cout << "The client code works with all visitors via the base Visitor interface:\n";
    Visitor* visitor1 = new ConcreteVisitor1;
    for (const Component *comp : components) {
      comp->Accept(visitor1);
    }
    std::cout << "\n";
    std::cout << "It allows the same client code to work with different types of visitors:\n";
    Visitor* visitor2 = new ConcreteVisitor2;
    for (const Component *comp : components) {
      comp->Accept(visitor2);
    }

    for (const Component *comp : components) {
      delete comp;
    }
    delete visitor1;
    delete visitor2;
  }


}

#endif


