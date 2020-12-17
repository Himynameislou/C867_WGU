//
//  student.hpp
//  C867
//
//  Created by Luis Vegerano on 12/13/20.
//

#ifndef student_hpp
#define student_hpp

#include <stdio.h>
// Include CString Library
#include <string>
// Include Degree Header File
#include "./degree.h"

using namespace std;


class Student {
public:
    Student(); //Default Constructor
    
    //Student Array
    Student(
            string studentID,
            string firstName,
            string lastName,
            string email,
            int age,
            int* days,
            DegreeProgram degreeProgram
            );
    
    //Setters
    void setStudentId(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDaysCourse(int* days);
    void setDegreeProgram(DegreeProgram);
    
    //Getters
    string getStudentId();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getNumberDays();
    
    
    //Print and Degree functions
    void print();
    virtual DegreeProgram getDegreeProgram();
    
    
    //Deconstructor
    ~Student();
    
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int* daysToComplete;
    DegreeProgram degreeP;
};

#endif /* student_hpp */
