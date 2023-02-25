#ifndef REVIEWPROJECT_GRADEBOOK_H
#define REVIEWPROJECT_GRADEBOOK_H
#include "category.h"
#include <iostream>
#include <vector>
#include <utility>
#include <string>

class Gradebook {
private:
    std::vector<Category> grades;
    int totalPossible;
    int totalGrade;

public:
    Gradebook();
    void calcTotalPossible();
    void calcTotalGrade();
    void inFile(std::string fileName);
    void outFile(std::string fileName);
    void getOneGrade(int category, int assignmentNum);
    void getGrades();
    void getCategoryGrade(int category);
    void addGrade(int grade);
    void changeGrade(int category, int assignmentNum, int newGrade);




};

#endif
