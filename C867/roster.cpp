//
//  roster.cpp
//  C867
//
//  Created by Luis Vegerano on 12/14/20.
//

#include "roster.hpp"
#include <string>
using namespace std;

const string studentData[] =
{
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Luis,Vegerano,louie1598@gmail.com,37,33, 20,32,SOFTWARE"
};

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int dCourse1, int dCourse2, int dCourse3, DegreeProgram degree){
    //Days in Course sub-array
    int* daysInCourse = new int [3];
    //Assign 3 values for this array
    daysInCourse[0] = dCourse1;
    daysInCourse[1] = dCourse2;
    daysInCourse[2] = dCourse3;
    
    
    
}
