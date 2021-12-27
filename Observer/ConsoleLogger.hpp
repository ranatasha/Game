#pragma once
#include "Logger.hpp"
#include <iostream> 

class ConsoleLogger: public Logger{
	public:
		void PrintInfo() override;
		void Update(std::string& received_message, Subject* subject){
    		this->received_message = received_message;
    		this->cur_subject = subject;
    		PrintInfo();
		}
};