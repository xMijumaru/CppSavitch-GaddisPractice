#ifndef ODOMETER_H
#define ODOMETER_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

class odom{
public:
    
    odom();                   //original constructor
    odom(float, float, float);// the overloaded constructor
    void CoutMilage () const;//couts the final solution
   
protected:
   float GalCsm; //the gallons consumed
   float MilPGal;//the miles per gallon
   float Driven; //the miles driven
   
};
void pause (int);

#endif /* ODOMETER_H */

