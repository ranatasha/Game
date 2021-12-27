#pragma once
#include "Observable.hpp"
#include <iostream>

//#include "../Entity/Character/Character.hpp"
#include <list>

	
class Subject: public Observable  
{
	protected:
		std::list<Observer*> list_observer;
  		std::string message;
	public:
		void Attach(Observer* observer)override{list_observer.push_back(observer);}
		void Detach(Observer* observer)override{list_observer.pop_back();}

		void Notify() override;
		void CreateMessage(std::string message = "Empty");
		
};
