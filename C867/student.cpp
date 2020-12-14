//
//  student.cpp
//  C867
//
//  Created by Luis Vegerano on 12/13/20.
//

#include "student.hpp"
#include <iostream>
#include "./degree.h"
#include <string>

using namespace std;

Student::Student(){
}

Student::Student(string studenID, string fName, string lName, string email, int age, int* daysCourse, enum DegreeProgram degree){
    studentID = studenID;
    firstName = fName;
    lastName = lName;
    email = email;
    age = age;
    numberDaysPerClass[0] = daysCourse[0];
    numberDaysPerClass[1] = daysCourse[1];
    numberDaysPerClass[2] = daysCourse[2];
    setDegreeProgram(degree);
}

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
int *Student::getNumberDays(){
    return numberDaysPerClass;
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
void Student::setDaysCourse(int d0, int d1, int d2){
    Student::numberDaysPerClass[0] = d0;
    Student::numberDaysPerClass[1] = d1;
    Student::numberDaysPerClass[2] = d2;
}
void Student::setDegreeProgram(DegreeProgram degree){
    degreeP = degree;
}

void Student::print(){
    
}

Student::~Student(){
    
}
