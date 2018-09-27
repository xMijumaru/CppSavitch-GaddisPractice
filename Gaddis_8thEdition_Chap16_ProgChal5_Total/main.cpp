/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: xMijumaru
 *
 * Created on September 26, 2018, 7:05 PM
 */

#include <iostream>
#include <cstdlib>
#include <cmath>


using namespace std;

//Function Prototypes
template <class A>
A total (A&x){
    A value, total=0;
    
    cout << "Enter Number ";
    for (int y=0;y < x; y++){
        cout << y + 1 << " : ";
        cin >> value;
        total+=value;
    }
    return total;
}
int main(int argc, char** argv) {
//Declare Variables here
    int num;        //the numbers that will be entered onto the class
    int finals;
    //Display inputs and outputs
    cout << "How many values will be inputted in: ";
    cin >> num;
    
    finals=total(num);
    cout << "The sum of the numbers are: " << finals << endl; 
    
    return 0;
}

