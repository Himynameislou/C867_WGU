//
//  roster.cpp
//  C867
//
//  Created by Luis Vegerano on 12/14/20.
//

#include "roster.hpp"
#include "student.hpp"
#include "degree.h"
#include <string>
#include <iostream>


using namespace std;

Roster Roster();
DegreeProgram degPro;
void Roster::parser(string studentData){
//Setting Degree output of Degree Type based off Code Letter Inserted
    DegreeProgram degPro = SECURITY;
        if (studentData.back() == 'K') {
            degPro = NETWORK;
        }
        else if (studentData.back() == 'E'){
            degPro = SOFTWARE;
        }
//This starts parsing at the code letter I inserted
    //char rhs = studentData.find(",");
    //string code = studentData.substr(0, rhs);
    
//Student ID
    char rhs = studentData.find(",");
      
    string stuID = studentData.substr(0, rhs);
    
//first name
    int lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstNM = studentData.substr(lhs, rhs - lhs);
    
//last name
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastNM = studentData.substr(lhs, rhs - lhs);
    
//email address
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emAdd = studentData.substr(lhs, rhs - lhs);
    
//age
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int ageStu = stoi(studentData.substr(lhs, rhs - lhs));
    
//Days 1
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int d1 = stoi(studentData.substr(lhs, rhs - lhs));
    
//Days 2
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int d2 = stoi(studentData.substr(lhs, rhs - lhs));
    
//Days 3
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int d3 = stoi(studentData.substr(lhs, rhs - lhs));

    
//Adding to Roster
    add(stuID, firstNM, lastNM, emAdd, ageStu, d1, d2, d3, degPro);
}

void Roster::add(string sID, string fN, string lN, string eAddress, int age, int dCourse1, int dCourse2, int dCourse3, DegreeProgram degPro){
    int daysArr[3] = {dCourse1, dCourse2, dCourse3};
    ClassRosterArray[++lastEntry] = new Student(sID, fN, lN, eAddress, age, daysArr, degPro);
}

void Roster::pringAll(){
    Student::printFormatHeader();
    for (int i = 0; i <= Roster::lastEntry; i++) {
        cout << ClassRosterArray[i]->getStudentId(); cout << '\t'<< '\t';
        cout << "First Name: " << ClassRosterArray[i]->getFirstName(); cout << '\t'<< '\t';
        cout << "Last Name: " << ClassRosterArray[i]->getLastName(); cout << '\t'<< '\t';
        cout << "Email: " << ClassRosterArray[i]->getEmail(); cout << '\t'<< '\t'<< '\t'<< '\t';
        cout << "Age: " << ClassRosterArray[i]->getAge(); cout << '\t'<< '\t'<< '\t';
        cout << "Days in Course: {" << ClassRosterArray[i]->getNumberDays()[0]; cout << ",";
        cout << ClassRosterArray[i]->getNumberDays()[1]; cout << ",";
        cout << ClassRosterArray[i]->getNumberDays()[2]; cout << "}" << '\t'<< '\t'<< '\t';
        cout << "Degree: " << degreeString[ClassRosterArray[i]->getDegreeProgram()] << endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degPro){
    Student::printFormatHeader();
    for (int i = 0; i <= Roster::lastEntry; i++) {
        if (Roster::ClassRosterArray[i]->getDegreeProgram() == degPro) {
            ClassRosterArray[i]->print();
        }
    }
    cout << endl;
}

//Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
void Roster::printInvalidEmails(){
    bool valid = false;
    for (int i =0; i <= Roster::lastEntry; i++) {
        string emailValidator = (ClassRosterArray[i]->getEmail());
        if (emailValidator.find('@') == string::npos || (emailValidator.find('.') == string::npos)) {
            valid = true;
            cout << emailValidator << ": " << ClassRosterArray[i]->getEmail() << endl;
        }
        else if (emailValidator.find(' ') != string::npos){
            valid = true;
            cout << emailValidator << ": " << ClassRosterArray[i]->getEmail() << endl;
        }
        if (!valid) {
            cout << "NONE" << endl;
        }
    }
}

void Roster::printAverageDaysInCourse(string studenId){
    for (int i = 0; i <= Roster::lastEntry; i++) {
        cout <<"Student ID: "<< ClassRosterArray[i]->getStudentId() << ", averages ";
        cout << (ClassRosterArray[i]->getNumberDays()[0] + ClassRosterArray[i]->getNumberDays()[1] + ClassRosterArray[i]->getNumberDays()[2])/3 << " days in a course." <<endl;
    }
    cout << endl;
}

void Roster::removeStudent(string sID){
    bool found = false;
    for (int i = 0; i <= Roster::lastEntry; i++) {
        if (ClassRosterArray[i]->getStudentId() == sID) {
            found = true;
            if (i < numStudents - 1) {
                Student* temp = ClassRosterArray[i];
                ClassRosterArray[i] = ClassRosterArray[numStudents - 1];
                ClassRosterArray[numStudents - 1] = temp;
            }
            Roster::lastEntry--;
        }
    }
    if (found) {
        cout << sID << " removed from roster." << endl << endl;
        this->pringAll(); //Removed Student will not display
    }
    else cout << sID << " not found." << endl;
}

Roster::~Roster(){
    
    for (int i = 0; i < numStudents; i++) {
        cout << "Destroying student #" << i + 1 << endl;
        delete ClassRosterArray[i];
        ClassRosterArray[i] = nullptr;
    }
}
