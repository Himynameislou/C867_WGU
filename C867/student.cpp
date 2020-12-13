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

Student::Student(string studenID, string fName, string lName, string email, int age, int* daysCourse){
    studentID = studenID;
    firstName = fName;
    lastName = lName;
    email = email;
    age = age;
    numberDaysPerClass[0] = daysCourse[0];
    numberDaysPerClass[1] = daysCourse[1];
    numberDaysPerClass[2] = daysCourse[2];
}
