#include "Subject.hpp"  

void Subject::Notify(){
  std::list<Observer*>::iterator iterator = list_observer.begin();
    while (iterator != list_observer.end()) {
      (*iterator)->Update(message, this);
      ++iterator;
    }
}
void Subject::CreateMessage(std::string message){
    this->message = message;
    Notify(); 
}