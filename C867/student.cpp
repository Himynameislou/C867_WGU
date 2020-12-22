//
//  student.cpp
//  C867
//
//  Created by Luis Vegerano on 12/13/20.
//

#include "student.hpp"
#include "degree.h"
#include <iostream>
#include <string>

using namespace std;

Student::Student(){
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    for (int i =0; i < daysInCourseArrSize; i++) {
        this->daysToComplete[i] = 0;
    }
    this->degreeP = DegreeProgram::SECURITY;
}

Student::Student(
                 string studenID,
                 string fName,
                 string lName,
                 string email,
                 int age,
                 int daysToComplete[],
                 DegreeProgram degree)
{
    studentID = studenID;
    firstName = fName;
    lastName = lName;
    this->email = email;
    this->age = age;
    for (int i =0; i < daysInCourseArrSize; i++) {
        this->daysToComplete[i] = daysToComplete[i];
    }
    this->degreeP = degree;
}

Student::~Student(){} //deconstructor

//Getters
string Student::getStudentId(){
    return studentID;
}
string Student::getFirstName(){
    return firstName;
}
string Student::getLastName(){
    return lastName;
}
string Student::getEmail(){
    return this->email;
}
int Student::getAge(){
    return this->age;
}
int* Student::getNumberDays(){
    return this->daysToComplete;
}
//insert degree program getter
DegreeProgram Student::getDegreeProgram(){
    return degreeP;
}

//Setters
void Student::setStudentId(string studenID){
    this->studentID = studenID;
}
void Student::setFirstName(string fName){
    this->firstName = fName;
}
void Student::setLastName(string lName){
    this->lastName = lName;
}
void Student::setEmail(string email){
    this->email = email;
}
void Student::setAge(int age){
    this->age = age;
}
void Student::setDaysCourse(int daysToComplete[]){
    for (int i = 0; i < daysInCourseArrSize; i++) {
        this->daysToComplete[i] = daysToComplete[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degree){
    this->degreeP = degree;
}

//Print Methods

//Header
void Student::printFormatHeader(){
    cout << "Header Format: Student ID || First Name || Last Name || Email || Age || Days In Courses || Degree Type\n";
}

//Print
void Student::print(){
    cout << "Student ID: " << this->getStudentId() << '\t'<< '\t';
    cout << "First Name: " << this->getFirstName() << '\t'<< '\t';
    cout << "Last Name: "<< this->getLastName() << '\t'<< '\t';
    cout <<"Email :"<< this->getEmail() << '\t'<< '\t'<< '\t'<< '\t';
    cout <<"Age: "<< this->getAge() << '\t'<< '\t'<< '\t';
    cout << "Days in Course: {" << this->getNumberDays()[0] << ',';
    cout << this->getNumberDays()[1] << ',';
    cout << this->getNumberDays()[2] << "}" <<'\t'<< '\t'<< '\t';
    cout <<"Degree: "<< degreeString[this->getDegreeProgram()] << endl;
}

