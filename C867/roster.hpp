//
//  roster.hpp
//  C867
//
//  Created by Luis Vegerano on 12/14/20.
//

#ifndef roster_hpp
#define roster_hpp
#include <array>
#include <stdio.h>
#include "student.hpp"
#include "degree.h"
using namespace std;

class Roster {
public:
    Roster(); //Default constructor for Roster
    
    // Setting Instance Variables from part D1
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int dCourse1, int dCourse2, int dCourse3, DegreeProgram degreeProgram);
    void removeStudent(string studentID);
    void pringAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    //adding index
    int addingIndex;
    
    ~Roster();
    
private:
    //Array for Roster
    Student *ClassRosterArray[5];
    
    
    
};
#endif /* roster_hpp */
