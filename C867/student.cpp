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
                 int* daysToComplete[],
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
    return email;
}
int Student::getAge(){
    return age;
}
int* Student::getNumberDays(){
    return daysToComplete;
}
//insert degree program getter
DegreeProgram Student::getDegreeProgram(){
    return degreeP;
}

//Setters
void Student::setStudentId(string studenID){
    Student::studentID = studenID;
}
void Student::setFirstName(string fName){
    Student::firstName = fName;
}
void Student::setLastName(string lName){
    Student::lastName = lName;
}
void Student::setEmail(string email){
    Student::email = email;
}
void Student::setAge(int age){
    Student::age = age;
}
void Student::setDaysCourse(int* days){
    for (int i = 0; i < 3; i++){
        daysToComplete[i] = days[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degree){
    degreeP = degree;
}

void Student::print(){
    
}

