#ifndef _STRATEGY_HPP_
#define _STRATEGY_HPP_
//https://refactoring.guru/design-patterns/strategy
//It focuses on answering thease questions
//1. What classes does it consist of?
//2. What roles do thease classes play?
//3. In what way the elements of the pattern are related?
#include "common.hpp"

namespace strategy
{
class Strategy{
public:
    virtual ~Strategy();
    virtual std::string DoAlgorithms(const std::vector<std::string> & data) const =0;
};

class Context{
  private:
    Strategy* strategy_;

public:
    Context(Strategy* strategy = nullptr) : strategy_(strategy){}
    ~Context(){
        delete this->strategy_;
    }
    void SetStrategy(Strategy* strategy){
        this->strategy_ = strategy;
    }

    void DoSomeBusinessLogin() const
    {
        std::vector<std::string> s_vec{"a","e","c","f","g"};
        std::string result = this->strategy_->DoAlgorithms(s_vec);
        std::cout<<result<<std::endl;
    }
};

class ConcreteStrategyA:public Strategy{
  public:
    virtual std::string DoAlgorithms(const std::vector<std::string>& data) const{
        std::string result;
        std::for_each(std::begin(data), std::end(data), [&result](const std::string& letter){
            result+=letter;
        });
        std::sort(std::begin(result), std::end(result));
        return result;
    }
};

class ConcreteStrategyB:public Strategy{
public:
    virtual std::string DoAlgorithms(const std::vector<std::string>& data) const{
        std::string result;
        std::for_each(std::begin(data), std::end(data), [&result](const std::string& letter){
            result+=letter;
        });
        std::sort(std::begin(result), std::end(result));
        for(int i=0; i<result.size()/2; i++){
            std::swap(result[i], result[result.size() -i -1]);
        }
        return result;
    }
};


void ClientCode(){
    Context* context = new Context(new ConcreteStrategyA);
    std::cout<<"Normal Sorting"<<std::endl;
    context->DoSomeBusinessLogin();
    std::cout<<std::endl;
    std::cout<<"Reverse Sorting"<<std::endl;
    context->SetStrategy(new ConcreteStrategyB);
    context->DoSomeBusinessLogin();
    std::cout<<std::endl;
    delete context;
}
}
#endif // STRATEGY_HPP
