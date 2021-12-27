#pragma once
#include "Command.hpp"
#include <iostream>

enum LogsType{CONSOLE, FILETYPE, CONS_FILE};

class SelectLogType: public Command  
{
	private:
		LogsType logType;
	public:
		void execute();
		void setLogType(LogsType logType){this->logType = logType;};
		LogsType getType(){return logType;}

};