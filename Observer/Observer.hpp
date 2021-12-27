#pragma once
#include <string>

class Subject;
class Observer  
{
	public:
		virtual void Update(std::string &received_message, Subject* subject) = 0;
		virtual ~Observer() {};

};