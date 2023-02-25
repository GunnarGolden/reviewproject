#ifndef REVIEWPROJECT_CATEGORY_H
#define REVIEWPROJECT_CATEGORY_H
#include <string>
#include <vector>

class Category {
private:
    std::string title;
    std::vector<std::string> categoryGrades;
    int totalPossibleCategory;
    int totalGradeCategory;
    friend class Gradebook;
public:
    void calcTotalPossible();
    void calcTotalGrade();
};

#endif //REVIEWPROJECT_CATEGORY_H