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
    Roster Roster;
    //String to Parse
    const string studentData[] =
    {
        "S,A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "N,A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "J,A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "S,A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "J,A5,Luis,Vegerano,louie1598@gmail.com,37,33, 20,32,SOFTWARE"
    };
    
    const int numStud = 5;
    
    /* Parsing and displaying all students in roster */
    cout<< "Displaying all students: " << endl;
    for (int i = 0; i < numStud; i++) {
        Roster.parser(studentData[i]);
    }
    Roster.pringAll();
    cout << endl;
    
    /* Displaying students by degree type instead of ID*/
    for (int i = 0; i < 3; i++) {
        cout << "Displaying by degree type: " << degreeString[i] << endl;
        Roster.printByDegreeProgram((DegreeProgram)i);
    }
    //Displaying Invalid IDs
    cout << "Displaying students with invalid emails" << endl;
    Roster.printInvalidEmails();
    cout << endl;
    
    //Displaying average Days in Course by student
    cout << "Displaying average days in course: " << endl;
    Roster.printAverageDaysInCourse(studentData[4]);
    
    /* First removes student and then runs again to validate student was removed*/
    
    //Removing student ID A3
    cout << "Removing student with ID - A3" << endl;
    Roster.removeStudent("A3");
    cout << endl;
    
    //Runs again to show student was removed
    cout << "Removing student with ID - A3" << endl;
    Roster.removeStudent("A3");
    cout << endl;
    
    
    
    
    system("pause");
    return 0;
    
};
