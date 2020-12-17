//
//  degree.h
//  C867
//
//  Created by Luis Vegerano on 12/13/20.
//

#ifndef degree_h
#define degree_h
#include <iostream>

using namespace std;

// Define an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE.

enum DegreeProgram {SECURITY, NETWORK, SOFTWARE};

//Using degree type as index
static const string degreeString[]= {"SECURITY", "NETWORK", "SOFTWARE"};


#endif /* degree_h */
