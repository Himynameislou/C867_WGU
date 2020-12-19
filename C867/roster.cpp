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

void Roster::parser(string studentData){
    DegreeProgram degPro = SOFTWARE;
    if (studentData.at(8) == NETWORK) {
        degPro = NETWORK;
    }
    else if (studentData.at(8) == SOFTWARE){
        degPro = SOFTWARE;
    }
    char rhs = studentData.find(",");  //May have to change type from char to int if this doesnt work.  Int Rhs gave warning for every instance
    string stuID = studentData.substr(0, rhs);
    
    int lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstNM = studentData.substr(lhs, rhs - lhs); //first name
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastNM = studentData.substr(lhs, rhs - lhs); //last name
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emAdd = studentData.substr(lhs, rhs - lhs); //email address
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int ageStu = stoi(studentData.substr(lhs, rhs - lhs)); //age
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int d1 = stoi(studentData.substr(lhs, rhs - lhs)); //Days 1
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int d2 = stoi(studentData.substr(lhs, rhs - lhs)); //Days 2
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int d3 = stoi(studentData.substr(lhs, rhs - lhs)); //Days 3
    
    add(stuID, firstNM, lastNM, emAdd, ageStu, d1, d2, d3, degPro);
}

void Roster::add(string sID, string fN, string lN, string eAddress, int age, int dCourse1, int dCourse2, int dCourse3, DegreeProgram degPro){
    int daysArr[3] = {dCourse1, dCourse2, dCourse3};
    ClassRosterArray[++lastEntry] = new Student(sID, fN, lN, eAddress, age, daysArr, degPro);
}

void Roster::pringAll(){
    Student::printFormatHeader();
    for (int i = 0; i <= Roster::lastEntry; i++) {
        cout << ClassRosterArray[i]->getStudentId(); cout << '\t';
        cout << ClassRosterArray[i]->getFirstName(); cout << '\t';
        cout << ClassRosterArray[i]->getLastName(); cout << '\t';
        cout << ClassRosterArray[i]->getEmail(); cout << '\t';
        cout << ClassRosterArray[i]->getAge(); cout << '\t';
        cout << ClassRosterArray[i]->getNumberDays()[0]; cout << '\t';
        cout << ClassRosterArray[i]->getNumberDays()[1]; cout << '\t';
        cout << ClassRosterArray[i]->getNumberDays()[2]; cout << '\t';
        cout << degreeString[ClassRosterArray[i]->getDegreeProgram()] << endl;
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
        cout << ClassRosterArray[i]->getStudentId() << ": ";
        cout << (ClassRosterArray[i]->getNumberDays()[0] + ClassRosterArray[i]->getNumberDays()[1] + ClassRosterArray[i]->getNumberDays()[2])/3 << endl;
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
    else cout << sID << " not found." << endl << endl;
}

Roster::~Roster(){
    cout << "Destructor called" << endl << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Destroying student #" << i + 1 << endl;
        delete ClassRosterArray[i];
        ClassRosterArray[i] = nullptr;
    }
}
