#include "category.h"

void Category::calcTotalPossible() { //Calculates the total possible grade you could've earned
    int possible = 0;
    int temp;
    std::string line;
    //Goes through whole list of grades
    for (int i = 0; i < categoryGrades.size(); i++) {
        line = categoryGrades[i];
        //Searches for the list for "/" symbol, then adds the bit afterwards to the total possible grade;
        for (int j = 0; j < line.length(); j++) {
            if (line[j] == 47) {
                line.erase(0, j+1);
                temp = std::stoi(line);
            }
        }
        possible += temp;
    }
    totalPossibleCategory = possible;
}

void Category::calcTotalGrade() { //Calculates the total grade you earned
    int total = 0;
    std::string line;
    //Goes through whole list
    for (int i = 0; i < categoryGrades.size(); i++) {
        line = categoryGrades[i];
        //Adds first number to total
        total += std::stoi(line);
    }
    totalGradeCategory = total;
}