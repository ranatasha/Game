#pragma once
#include "Observer.hpp"
class FileLogger;
class ConsoleLogger;
	
class Observable  
{
	public:
		virtual void Attach(Observer* observer) = 0;
		virtual void Detach(Observer* observer) = 0;
  		virtual void Notify() = 0;
		virtual ~Observable() {};

};