# ReviewProject
Welcome to our Review Project, by Daxton Tassone, Sean Reth, Tanya Lee, and Gunnar Golden. Here is some pseudocode we used before we began our coding process:
```#include <iostream>
#include <vector>
#include "gradebook.h"

//constructor that makes a gradebook (not sure if we need this)
Gradebook::Gradebook(){

}
//infile will open the file and read it into multiple vectors. Might have to make a second class to make this process easier
void Gradebook::inFile(){
  //open file
  //read lines into vectors
}
//outfile will take those vectors and print them back to the same file they were in before
void Gradebook::outFile(){
  //read lines of vectors to files
  
  //close file
}
//get one grade will get a single grade, given the category and the assignment number
void Gradebook::getOneGrade(int category, int assignmentNum){
  //loop through the vectors till it finds the right category
  //loop throuhg the assignments till it finds the right number
  //print that grade
}
//get grade will get the whole grade of the whole class given the info
void Gradebook::getGrades(){
  //calculate total possible grade
  //calculate grade recieved
  //divide grade recieved by total possible and multiple by 100
}
//get category grade will give all the grades in that category and the overall grade in that category
void Gradebook::getCategoryGrade(int category){
  //loop through and print all grades in that category
  //divide the grade you got by the max grade and multiply by 100

}
//add grade function adds a grade to a category
void Gradebook::addGrade(int grade){
  //loop through vector to find right category and location
  //push new grade there
}
//change grade takes a grade and changes it, given its category, assignment number, and the new grade
void Gradebook::changeGrade(int category, int assignmentNum, int newGrade){
  //loop through and find category
  //find assignment number (given assignment number - 1)
  //replace it with new Grade
}```
