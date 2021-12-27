#include "InvokerCommand.hpp"  
	
void InvokerCommand::setCommand(Command* command){
    this->command = command;
}

void InvokerCommand::executeCommand(){
    this->command->execute();
}
	
InvokerCommand::~InvokerCommand()
{
	delete command;
}