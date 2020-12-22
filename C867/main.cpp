//
//  main.cpp
//  C867
//
//  Created by Luis Vegerano on 12/13/20.
//

#include <iostream>
#include "student.hpp"
#include "roster.hpp"
#include "degree.h"

using namespace std;

int main() {
    cout << "C867 - Scripting & Programming; Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 001459305" << endl;
    cout << "Luis Vegerano" << endl;
    cout << endl;
  
    
    
    Roster classRoster; //classRoster instance
//String to Parse
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Luis,Vegerano,louie1598@gmail.com,37,33, 20,32,SOFTWARE"
    };
    
    const int numStud = 5;
    
/* Parsing and displaying all students in roster */
    cout<< "Displaying all students: " << endl;
    for (int i = 0; i < numStud; i++) {
        classRoster.parser(studentData[i]);
    }
    classRoster.printAll();
    cout << endl;
    
//Displaying Invalid Emails
    cout << "Displaying students with invalid emails:" << endl;
    classRoster.printInvalidEmails();
    cout << endl;
    
//Displaying average Days in Course by student
    cout << "Displaying average days in course: " << endl;
    classRoster.printAverageDaysInCourse(studentData[4]);
    
//Degree Type
    cout << "Displaying by degree type: " << degreeString[2] << endl;
    classRoster.printByDegreeProgram((DegreeProgram)2);
   

/* First removes student and then runs again to validate student was removed */
    
//Removing student ID A3
    cout << "Removing student with ID - A3" << endl;
    classRoster.removeStudent("A3");
    cout << endl;
    
//Runs again to show student was removed
    cout << "Removing student with ID - A3" << endl;
    classRoster.removeStudent("A3");
    cout << endl;
    
};
