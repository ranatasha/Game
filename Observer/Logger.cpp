#include "Logger.hpp"  

void Logger::Update(std::string& received_message, Subject* subject){
    std::cout<<"CHECK\n";
    this->received_message = received_message;
    this->cur_subject = subject;
    PrintInfo();
}