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

void Roster::parser(string studentData){
    DegreeProgram degPro = SECURITY;
    if (studentData.at(8) == NETWORK) {
        degPro = NETWORK;
    }
    else if (studentData.at(8) == SOFTWARE){
        degPro = SOFTWARE;
    }
    int rhs = studentData.find(",");
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
