#ifndef _OBSERVER_HPP_
#define _OBSERVER_HPP_
//https://refactoring.guru/design-patterns/observer
//Define a subscription mechanisim to notify multiple objects about any events 
//that happen to object they're observing.
#include "common.hpp"

namespace observer
{
  class IObserver {
  public:
    virtual ~IObserver() { };
    virtual void Update(const std::string& message_from_subject) = 0;
  };

  class ISubject {
  public:
    virtual ~ISubject() {};
    virtual void Attach(IObserver* observer) = 0;
    virtual void Detach(IObserver* observer) = 0;
    virtual void Notify() = 0;
  };

  class Subject : public ISubject {
  public:
    virtual ~Subject() {
      std::cout << "Destructor of Concrete Subject class\n";
    }

    virtual void Attach(IObserver* observer) {
      list_observer_.push_back(observer);
    }
    virtual void Detach(IObserver* observer) {
      list_observer_.remove(observer);
    }
    virtual void Notify() {
      std::list<IObserver*>::iterator it = list_observer_.begin();
      while (it != list_observer_.end()) {
        (*it)->Update(message_);
        ++it;
      }
    }

    void CreateMessage(std::string message = "empty") {
      this->message_ = message;
      Notify();
    }
    
    void SomeBusinessLogic() {
      this->message_ = "change message message";
      Notify();
      std::cout << "I'm about to do some thing important\n";
    }

  private:
    std::list<IObserver*> list_observer_;
    std::string message_;
  };

  class Observer :public IObserver {
  public:
    Observer(Subject& subject) :subject_(subject) {
      this->subject_.Attach(this);
      std::cout << "Hi, I'm the Observer \"" << ++Observer::static_number_ << "\".\n";
      this->number_ = Observer::static_number_;
    }
    virtual ~Observer() {
      std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
    }

    virtual void Update(const std::string& message_from_subject) {
      message_from_subject_ = message_from_subject_;
      PrintInfo();
    }
    void RemoveMeFromTheList() {
      subject_.Detach(this);
      std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
    }
    void PrintInfo() {
      std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
    }

  private:
    std::string message_from_subject_;
    Subject &subject_;
    static int static_number_;
    int number_;
  };
  int Observer::static_number_ = 0;

  void ClientCode() {
    Subject* subject = new Subject;
    Observer* o1 = new Observer(*subject);
    Observer* o2 = new Observer(*subject);
    Observer* o3 = new Observer(*subject);
    Observer* o4;
    Observer* o5;

    subject->CreateMessage("Hello world!");
    o3->RemoveMeFromTheList();

    subject->CreateMessage("The weather is hot today");
    o4 = new Observer(*subject);
    
    o2->RemoveMeFromTheList();
    o5 = new Observer(*subject);

    o4->RemoveMeFromTheList();
    o1->RemoveMeFromTheList();

    delete o1;
    delete o2;
    delete o3;
    delete o4;
    delete o5;
  }


}//namespace observer
#endif // !_OBSERVER_HPP_

