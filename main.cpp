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
            std::string category;
            int assignmentNum;
            std::cout << "Which category would you like to find? Ex. Lab" << std::endl;
            std::cin >> category;
            std::cout << "What is your order you wanna find for your category? Ex. Assignment 2 then input 2" << std::endl;
            std::cin >> assignmentNum;
            mainGradebook.getOneGrade(category, assignmentNum);
        }
        else if (input == "Add Grade"){
            //get category title
            std::string input2="";
            std::cout<<"Would you like to add a grade to Projects, Assignments, or Labs? \n";
            std::cin>>input2;
            //get index
            int index;
            std::cout<<"Which Project, Assignment, or Lab number would you like to add? \n";
            std::cin>>index;
            //get grade and insert it into gradebook
            std::string Grade="";
            std::cout<<"What is the grade you would like to add? \n";
            std::cin>>Grade;
            mainGradebook.addGrade(input2, index,Grade);
        }
        else if (input == "Change Grade"){
            //get category title
            std::string Category="";
            std::cout<<"Would you like to change a grade in Projects, Assignments, or Labs? \n";
            std::cin>>Category;
            //get index
            int index;
            std::cout<<"Which Project, Assignment, or Lab number would you like to change? \n";
            std::cin>>index;
            //get grade and insert it into gradebook
            std::string Grade="";
            std::cout<<"What is the grade you would like to change? \n";
            std::cin>>Grade;
            mainGradebook.changeGrade( Category, index,  Grade);

        }
        else if (input == "End"){
            std::cout<<"Now exiting the gradebook";
        }
        else {
            std::cout<<"Looks like you input something besides one of the allowed commands. Please try again." << std::endl;
        }
    }

}
