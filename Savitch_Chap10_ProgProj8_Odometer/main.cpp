//SAVITCH CHAPTER 10 PROGRAMMING PROJECT 8
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "odometer.h"

using namespace std;


int main(int argc, char** argv) {
//Declare Variables here
    float Gal;//gallons consumed
    float MPG; // the miles per gallon of the vehicle
    float MilDrv; //the miles that will be driven
    
    //Display inputs and outputs
    Gal=0;       //total gallons consumed
    MPG=33.5;    //miles per gallon
    MilDrv=10000; //miles driven
   
    //creates the object
    odom Solution (Gal, MPG, MilDrv);//passes in the variables
    Solution.CoutMilage();
    
    return 0;
}

