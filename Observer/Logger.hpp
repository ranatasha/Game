#pragma once
#include <list>
#include "Observer.hpp"
class Subject;
#include "../Entity/Character/Player.hpp"
#include "../Entity/Character/Enemy/Cat.hpp"
#include "../Entity/Character/Enemy/Zombie.hpp"
#include "../Entity/Character/Enemy/Owl.hpp"
#include <iostream>

class Logger: public Observer 
{
	protected:
		std::string received_message;
		Subject* cur_subject;
	public:
		void Update(std::string& received_message, Subject* subject) override;
		virtual void PrintInfo() = 0;
};