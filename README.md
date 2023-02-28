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
}
```
Compiling the code:
In order to compile the code, you must insert the text file you want as a command line argument. If you are manually compiling, you must use:
g++ main.cpp gradebook.cpp category.cpp, then use ./a.out textfilename.txt. If you are just using the play button on cLion, click edit configuration and add
textfilename.txt under executable, then press the play button. After running the code, a list of text options will enter asking what you would like to do,
giving you input options, and explaining what each of those options do. The options are: Grade, Category, Specific, Add, Change, and End. Each one has a summary
with it explaining what it does. Once you select one of these, any further instructions needed will continue to appear until you have given it all the information
to execute the command. An example of this would be if you select "Category", it will ask you to specify which category, which you can see the options from
the text file examples. We have Labs, Assignments, and Projects as our options. Once one command has happened and a result has been returned, you can repeat 
this process again, until you input the "End" command. Once the "End" command has been said, the program will end and the text file you entered will be updated
with any new changes you made to it by adding or changing any grades. And that is all it takes to run the code. You should find it easy and specific, as 
it tells you exactly what it wants at all inputs. 

