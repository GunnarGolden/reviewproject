#ifndef REVIEWPROJECT_GRADEBOOK_H
#define REVIEWPROJECT_GRADEBOOK_H
#include <iostream>
#include <vector>


class Gradebook {
private:
    std::vector<std::vector<int>> grades;

public:
    Gradebook();
    void inFile();
    void outFile();
    void getOneGrade(int category, int assignmentNum);
    void getGrades();
    void getCategoryGrade(int category);
    void addGrade(int grade);
    void changeGrade(int category, int assignmentNum, int newGrade);




};


#endif
