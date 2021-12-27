#include "ConsoleLogger.hpp"
	
void ConsoleLogger::PrintInfo(){
    std::cout << this->received_message;
    Player* ptr = dynamic_cast<Player*>(cur_subject);
    if(ptr)
        std::cout << ptr;
    else{
        Cat* ptr = dynamic_cast<Cat*>(cur_subject);
        if(ptr)
            std::cout << ptr;
        else{
            Owl* ptr = dynamic_cast<Owl*>(cur_subject);
            if(ptr)
                std::cout << ptr;
            else{
                Zombie* ptr = dynamic_cast<Zombie*>(cur_subject);
                if(ptr)
                    std::cout << ptr;
            }
        }
    }
};