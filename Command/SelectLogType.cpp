#include "SelectLogType.hpp"  

void SelectLogType::execute(){
    std::string s ="Enter the type of LogsOutput:\n\t0 - through the console;\n\t1 - through the file logs.txt\n\t2 - through the both: console and file\nEnter: ";
    std::cout<<s;
    int choice;
    do {
        std::cin >> choice;
        switch(choice){
            case 0:
                std::cout<<"\nCONSOLE type of LogsOutput was selected.\n\n";
                this->setLogType(CONSOLE);
                break;
            case 1:
                std::cout <<"\nFILE type of LogsOutput was selected.\n\n";
                this->setLogType(FILETYPE);
                break;
            case 2:
                std::cout <<"\nCONSOLE&FILE type of LogsOutput was selected.\n\n";
                this->setLogType(CONS_FILE);
                break;
            default:
                choice = -1;
                std::cout << "\nSuch type of LogsOutput doesn't exist. Try again.\nEnter:" ;
        }
    } while(choice == -1);
}
