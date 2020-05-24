#ifndef _TEMPLATE_METHOD_HPP
#define _TEMPLATE_METHOD_HPP
//https://refactoring.guru/design-patterns/template-method

#include "common.hpp"

namespace template_method
{
class AbstractClass{
public:
    void TemplateMethod() const{
        this->BaseOperation1();
        this->BaseOperation2();
        this->BaseOperation3();
        this->Hook1();
        this->Hook2();
    }
    virtual ~AbstractClass(){}

protected:
    void BaseOperation1() const{
        std::cout <<"Abstract Class:Base1"<<std::endl;
    }
    void BaseOperation2() const{
        std::cout<< "Abstract Class:Base2"<<std::endl;
    }
    void BaseOperation3() const{
        std::cout<<"Abstract Class:Base3"<<std::endl;
    }

    virtual void RequiredOperation1() const =0;
    virtual void RequiredOperation2() const =0;

    virtual void Hook1() const {}
    virtual void Hook2() const {}
};

class ConcreteClass1:public AbstractClass{
protected:
    virtual void RequiredOperation1() const{
        std::cout<<"Concrete Class1: Impl1"<<std::endl;
    }
    virtual void RequiredOperation2() const{
        std::cout<<"Concrete Class1: impl2"<<std::endl;
    }
};

class ConcreteClass2:public AbstractClass{
protected:
    virtual void RequiredOperation1() const{
        std::cout<<"Concrete Class2: impl1"<<std::endl;
    }
    virtual void RequiredOperation2() const {
        std::cout<<"Concrete Class2:impl2"<<std::endl;
    }

    void Hook1() const{
        std::cout<<"Hook of concrete class2"<<std::endl;
    }
};

void ClientCode(){
    std::cout<<"Template Method Concrete Class1"<<std::endl;
    AbstractClass* concrete1 = new ConcreteClass1();
    concrete1->TemplateMethod();
    std::cout<<std::endl;
    std::cout<<"Template Method Concrete Class2"<<std::endl;
    AbstractClass* concrete2 = new ConcreteClass2();
    concrete2->TemplateMethod();
    std::cout<<std::endl;
    delete concrete1;
    delete concrete2;
}

}

#endif // TEMPLATE_METHOD_HPP
