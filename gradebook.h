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
    float calcTotalPossible();
    float calcTotalGrade();
    void inFile(std::string fileName);
    void outFile(std::string fileName);
    void getOneGrade(std::string category, int assignmentNum);
    void getCategoryGrade(std::string category);
    void addGrade(std::string Category, int index,std::string Grade);
    void changeGrade(std::string Category, int index, std::string Grade);



};

#endif
