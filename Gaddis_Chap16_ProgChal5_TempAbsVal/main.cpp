/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: xMijumaru
 *
 * Created on September 26, 2018, 6:33 PM
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

//Function Prototypes
template <class A> A AbsVal (A &v){
    A NwVal;
    NwVal=(v>=0)? v: (v * -1);
    return NwVal;
}

int main(int argc, char** argv) {
//Declare my variables here
    int answer1, value1;
    float answer2, value2;
   
    //process inputs and outputs
    cout << "Enter any whole number: " << endl;
    cin >> value1;
    cout << "Enter any number now: " << endl;
    cin >> value2;
    
    answer1=AbsVal(value1);
    answer2=AbsVal(value2);
    
    cout << "The absolute value of the first number is: " << answer1 
            << endl;
    cout << "The absolute value for the second number is : " << answer2
            << endl;
    
    return 0;
}

