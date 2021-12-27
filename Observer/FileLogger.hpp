#pragma once
#include "Logger.hpp"
#include <fstream>

class FileLogger: public Logger
{
	protected:
		std::ofstream file;
	public:
		FileLogger();
		void PrintInfo() override;
		void Update(std::string& received_message, Subject* subject){
    		this->received_message = received_message;
    		this->cur_subject = subject;
    		PrintInfo();
		}
		~FileLogger();

};