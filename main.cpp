#include <iostream>
#include <string>
#include "gradebook.h"

int main(int argc, char* argv[]) {
    Gradebook mainGradebook;
    mainGradebook.inFile(argv[1]);
    std::string input;
    std::cout<<"Welcome to your gradebook. Here are the commands you can do:";
    while (input != "end" && input != "End" && input != "END"){
        std::cout<<"\nShow Grade- \nShow Category Grade- \n"
                   "Show Single Grade- \nAdd Grade- \nChange Grade- \nEnd- \n";
        std::cin>>input;
        if (input == "ShowGrade"){
            std::cout<<"Showing grade now" << std::endl;
        }
        else if (input == "Show Category Grade"){

        }
        else if (input == "Show Single Grade"){

        }
        else if (input == "Add Grade"){

        }
        else if (input == "Change Grade"){

        }
        else if (input == "End"){

        }
        else {
            std::cout<<"Looks like you input something besides one of the allowed commands. Please try again." << std::endl;
        }
    }

}
