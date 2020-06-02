#ifndef _ADAPTER_HPP_
#define _ADAPTER_HPP_
//https://refactoring.guru/design-patterns/adapter
//Allows objects with incompatible interfaces to collaborate
//Consider when implementation of adapter pattern.
//1.What classes does it consist of?
//2.What roles do these classes play?
//3.In what way the elements of the pattern are related?

#include "common.hpp"

namespace adapter
{
  //conceptual
  class Target {
  public:
    virtual ~Target() = default;
    virtual std::string Request() const {
      return "Target: The default target's behavior.";
    }
  };

  class Adaptee {
  public:
    std::string SpecificRequest() const {
      return ".eetpadA eht fo roivaheb laicepS";
    }
  };

  class Adapter :public Target {
  private:
    Adaptee *adaptee_;

  public:
    Adapter(Adaptee* adaptee) : adaptee_(adaptee) {}
    virtual std::string Request() const{
      std::string to_reserve = this->adaptee_->SpecificRequest();
      to_reserve.reserve();
      return "Adapter: (TRANSLATED) " + to_reserve;
    }
  };

}


#endif
