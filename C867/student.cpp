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

Student::Student(
                 string studenID,
                 string fName,
                 string lName,
                 string email,
                 int age,
                 int* daysCourse,
                 enum DegreeProgram degree)
{
    studentID = studenID;
    firstName = fName;
    lastName = lName;
    email = email;
    age = age;
    daysToComplete = daysCourse;
    setDegreeProgram(degree);
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

//Print / Deconstruct
void Student::print(){
    
}

Student::~Student(){
    
}
