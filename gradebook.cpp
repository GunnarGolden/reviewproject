#include <iostream>
#include <vector>
#include <fstream>
#include "gradebook.h"
#include <string>
#include <cmath>

Gradebook::Gradebook(){

}

//Calculates the total possible grade you could've gotten in every category
float Gradebook::calcTotalPossible() {
    int possible = 0;
    for (int i = 0; i < grades.size(); i++) {
        possible += grades[i].totalPossibleCategory;
    }
    totalPossible = possible;
    return totalPossible;
}

//Calculates your total grade from every category
float Gradebook::calcTotalGrade() {
    int total = 0;
    for (int i = 0; i < grades.size(); i++) {
        total += grades[i].totalGradeCategory;
    }
    totalGrade = total;
    return totalGrade;
}

//Gets the category titles and grades from given fileName, and updates the Gradebook and makes Categories based on them.
void Gradebook::inFile(std::string fileName){
    std::fstream file;
    std::string line;
    Category currentCategory;
    file.open(fileName);
    while (getline(file, line)) {
        //Stops once it detects "Total:" since this is how the file is supposed to end.
        if (line == "Total:") {
            currentCategory.calcTotalPossible();
            currentCategory.calcTotalGrade();
            grades.push_back(currentCategory);
            calcTotalPossible();
            calcTotalGrade();
            file.close();
            return;
        }
        //Checks if the first character is a number. If it isn't, then make a new category
        if (line[0] < 48 || line[0] > 57) {
            //Is there already a category? If yes, add it to the list of grades
            if (currentCategory.categoryGrades.size() > 0) {
                currentCategory.calcTotalPossible();
                currentCategory.calcTotalGrade();
                grades.push_back(currentCategory);
            }
            //Set currentCategory to new category title and reset grades.
            currentCategory.title = line;
            currentCategory.categoryGrades.clear();
        }
        else {
            //If it is a grade, calculate the percentage and add it to category
            currentCategory.categoryGrades.push_back(line);
        }
    }
    //Add set of grades to the grade book, calculate total possible grade and final grade, then close the file.
    //This only runs if the file doesn't end in "Total:"
    currentCategory.calcTotalPossible();
    currentCategory.calcTotalGrade();
    grades.push_back(currentCategory);
    calcTotalPossible();
    calcTotalGrade();
    file.close();
}

//Outputs contents of gradebook onto text file. Adds total grade at the end.
void Gradebook::outFile(std::string fileName){
    std::fstream file;
    std::string line;
    Category currentCategory;
    file.open(fileName);
    //For every category in the grades
    for (int i = 0; i < grades.size(); i++) {
        //Output the title of the category
        file << grades[i].title << std::endl;
        //For every grade in the category, output that grade
        for (int j = 0; j < grades[i].categoryGrades.size(); j++) {
            file << grades[i].categoryGrades[j] << std::endl;
        }
    }
    //convert totalGrade and totalPossible to float to get percentage
    float total = totalGrade;
    float possible = totalPossible;
    float percentage = floor((total/possible) * 100);
    //Add Total to the end
    file << "Total:" << std::endl;
    file << percentage << " (" << totalGrade << "/" << totalPossible << ")" << std::endl;
    file.close();
}

// function gives you the grade you have in a given category and assignment number
void Gradebook::getOneGrade(std::string category, int assignmentNum){

    int num = 0;
    category[0] = toupper(category[0]);
    //find the index of the category which is num
    for (int i = 0;i < grades.size(); i++) {
        if (grades[i].title == category) {
            num = i;
            break;
        }
    }
    std::string assignment = category + " " + std::to_string(assignmentNum);
    //output the assignemnt with the grades
    std::cout << "Your grade for " << assignment << " is " << grades[num].categoryGrades[assignmentNum-1] << std::endl;
}

//function gives you all grades from the category and category total
void Gradebook::getCategoryGrade(std::string category){
    int num = 0;
    category[0] = toupper(category[0]);
    for (int i = 0 ; i < grades.size() ; i++) {
        if (grades[i].title == category) {
            num = i;
            break;
        }
    }
    int totalC = 0;
    int total = 0;
    for(int j = 0; j < grades[num].categoryGrades.size(); j++)
    {
        totalC = totalC + stoi(grades[num].categoryGrades[j]);
        std::cout<<category<<" "<<j+1<<": "<<grades[num].categoryGrades[j]<<"\n";
    }
    float categoryGrade = totalC ;
    std::cout<<category<<" total grade: "<<categoryGrade<<"\n";

}

//add grade into the gradebook
void Gradebook::addGrade(std::string category, int index,std::string Grade){
    //num variable is a temp variable used to keep track of where the specific category is in the grade vector. We then use this to determine where we are inserting our grade.
    int num = 0;
    category[0] = toupper(category[0]);
    for (int i = 0;i < grades.size(); i++) {
        if (grades[i].title == category) {
            num = i;
            break;
        }
    }
    //insert function allows us to insert the grade we want into the grades vector and pushes everything else back.
    grades[num].categoryGrades.insert(grades[num].categoryGrades.begin()  + index - 1, Grade);
}
//changes grade of an already existing grade
void Gradebook::changeGrade(std::string category, int index, std::string Grade) {
    //num variable is a temp variable used to keep track of where the specific category is in the grade vector. We then use this to determine where we are changing our grade.
    int num=0;
    category[0] = toupper(category[0]);
    for (int i = 0;i < grades.size(); i++) {
        if (grades[i].title == category) {
            num = i;
            break;
        }
    }
    //use the num variable to change the existing grade into the new grade.
    grades[num].categoryGrades[index - 1] = Grade;
}
