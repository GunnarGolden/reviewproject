#include <iostream>
#include <string>
#include <vector>
#include "gradebook.h"

int main(int argc, char* argv[]) {
    Gradebook mainGradebook;
    mainGradebook.inFile(argv[1]);
    std::string input;
    std::cout<<"Welcome to your gradebook. ";
    while (input != "end" && input != "End" && input != "END"){
        std::cout<<"Here are your possible commands:\nGrade- \nCategory- \n"
                   "Specific- \nAdd- \nChange- \nEnd- \n";
        std::cin>>input;
        for (int i = 0 ; i < input.size() ; i++){
            input[i] = tolower(input[i]);
        }
        if (input == "grade"){
            std::cout<<"Showing grade now: " << std::endl;
            float grade = mainGradebook.calcTotalGrade()/mainGradebook.calcTotalPossible();
            grade = grade * 100;
            std::cout<<grade<<"\n";
        }
        else if (input == "category"){

        }
        else if (input == "specific"){
            std::string category;
            int assignmentNum;
            std::cout << "Which category would you like to find? Ex. Lab" << std::endl;
            std::cin >> category;
            std::cout << "What is your order you wanna find for your category? Ex. Assignment 2 then input 2" << std::endl;
            std::cin >> assignmentNum;
            mainGradebook.getOneGrade(category, assignmentNum);
        }
        else if (input == "add"){
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
        else if (input == "change"){
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
        else if (input == "end"){
            std::cout<<"Now exiting the gradebook";
        }
        else {
            std::cout<<"Looks like you input something besides one of the allowed commands. Please try again." << std::endl;
        }
    }

}
