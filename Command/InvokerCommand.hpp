#pragma once
#include "Command.hpp"	
class InvokerCommand  
{
	private:
		Command* command;
	public:

		void setCommand(Command* command);
		void executeCommand();
		~InvokerCommand();

};