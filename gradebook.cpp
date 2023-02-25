#include <iostream>
#include <vector>
#include <fstream>
#include "gradebook.h"


Gradebook::Gradebook(){

}

//Calculates the total possible grade you could've gotten in every category
void Gradebook::calcTotalPossible() {
    int possible = 0;
    for (int i = 0; i < grades.size(); i++) {
        possible += grades[i].totalPossibleCategory;
    }
    totalPossible = possible;
}

//Calculates your total grade from every category
void Gradebook::calcTotalGrade() {
    int total = 0;
    for (int i = 0; i < grades.size(); i++) {
        total += grades[i].totalGradeCategory;
    }
    totalGrade = total;

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
    //Add total to the end
    file << "Total:" << std::endl;
    file << totalGrade << "/" << totalPossible << std::endl;
    file.close();
}

void Gradebook::getOneGrade(int category, int assignmentNum){

}

void Gradebook::getGrades(){

}

void Gradebook::getCategoryGrade(int category){

}

void Gradebook::addGrade(int grade){

}

void Gradebook::changeGrade(int category, int assignmentNum, int newGrade){

}
