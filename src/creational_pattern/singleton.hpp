#ifndef _SINGLETON_HPP_
#define _SINGLETON_HPP_
//https://refactoring.guru/design-patterns/singleton
//Singleton is a creational design pattern that lets you ensure
//that a class has only one instance, while providing 
//a global access point to this instance

//Implementation of Singleton
//Make the default constructor private, to prevent other objects from using the new operator
//Create static creation method that acts as a constructor.
#include "common.hpp"

class Singleton {
private:
  //default constructor has to implement at private
  Singleton(const std::string& val) {
    value_ = val;
  };
  //make static singleton pointer instance
  static Singleton* instance_;
  std::string value_;
public:
  //delete copy constructor
  Singleton(Singleton& other) = delete;
  //delete assign operator
  void operator=(const Singleton& other) = delete;

  static Singleton* GetInstance() {
    if (instance_ == nullptr) {
      instance_ = new Singleton("");
    }
    return instance_;
  }
  std::string value() const{
    return value_;
  }
  std::string& value() {
    return value_;
  }
  void Print() {
    std::cout << value_ << std::endl;
  }
};
Singleton* Singleton::instance_ = nullptr;

//Thread safe class
class SingletonThreadSafe {
private:
  static SingletonThreadSafe* instance_;
  static std::mutex mutex_;
  std::string value_;
  SingletonThreadSafe() :value_("") {};
  ~SingletonThreadSafe() {};

public:
  SingletonThreadSafe(SingletonThreadSafe& other) = delete;
  void operator=(const SingletonThreadSafe& other) = delete;

  static SingletonThreadSafe* GetInstance() {
    if (instance_ == nullptr) {
      std::lock_guard<std::mutex> lock(mutex_);
      if (instance_ == nullptr) {
        instance_ = new SingletonThreadSafe();
      }
    }
    return instance_;
  }
  std::string value() const {
    return value_;
  }
  std::string& value() {
    return value_;
  }

  void Print() {
    std::cout << value_ << std::endl;
  }
};
SingletonThreadSafe* SingletonThreadSafe::instance_ = nullptr;
std::mutex SingletonThreadSafe::mutex_;
#endif // 
