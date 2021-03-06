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

using namespace std;

class Roster {
    
private:
    int lastEntry = -1; //Used to loop over STUDENTS when adding to Roster
    //Array for Roster
    static const int numStudents = 5;
    //Fix for E2 comment. E2a. E2b. E3a. E3b. E3d. E3e. E3f.
    // Changed Class Name below from "ClassRosterArray" to "classRosterArray" to comply with Rubric.
    Student* classRosterArray[numStudents];
    
public:
    //Roster(); //Default constructor for Roster
    void parser(string row); //Will be used to parse data properly into row
    
    // Setting Instance Variables from part D1
    //Adding student data into Roster
    void add(
              
             string sID,
             string fN,
             string lN,
             string eAddress,
             int age,
             int dCourse1,
             int dCourse2,
             int dCourse3,
             DegreeProgram degPro);
    void printAll();
    void printByDegreeProgram(DegreeProgram degPro);
    void printInvalidEmails();
    void printAverageDaysInCourse(string studentID);
    void removeStudent(string sID);

    ~Roster();
};
#endif /* roster_hpp */
