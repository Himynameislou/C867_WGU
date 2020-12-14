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
#include "./student.hpp"
using namespace std;

class Roster {
public:
    Roster(); //Default constructor for Roster
    
    // Setting Instance Variables from part D1
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);
    
    void removeStudent(string studentID);
    void printCourseDays(string studentID);
    void printInvalidEmails();
    void printDegreeType();
    
private:
    //Array for Roster
    Student *ClassRosterArray[5];
    
    
};
#endif /* roster_hpp */
