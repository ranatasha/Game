#include "FileLogger.hpp"  
FileLogger::FileLogger(){
    file.open("logs.txt");
}
void FileLogger::PrintInfo(){
    file << received_message;
    Player* ptr = dynamic_cast<Player*>(cur_subject);
    if(ptr)
        file << ptr;
    else{
        Cat* ptr = dynamic_cast<Cat*>(cur_subject);
        if(ptr)
            file << ptr;
        else{
            Owl* ptr = dynamic_cast<Owl*>(cur_subject);
            if(ptr)
                file << ptr;
            else{
                Zombie* ptr = dynamic_cast<Zombie*>(cur_subject);
                if(ptr)
                    file << ptr;
            }
        }
    }
};
FileLogger::~FileLogger(){
    file.close();
}