/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: xMijumaru
 *
 * Created on September 27, 2018, 3:37 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

//Global Variables
const int size=5;       //the size of the array that will be searched

//Function Prototypes
template <class T>
void ArraySearch (T [], vector <int>&, const int);

int main(int argc, char** argv) {
//Declare the variables here
    char first[size]={'a','G','J','T','z'};
    int second[size]={5,8,23,87,90};
    float third[size]={34.5,12.7,33.7,89.0,90.87};
    int choice;             //The choice that the user will input
    vector<int>index;       //if the number is found, the index will be stored
                            //inside of the vector
    
    //Process inputs and outputs
    cout << "which array do you wish to search a value for: " << endl;
    cout << "1) Character\n2) Integer\n3) float" << endl;
    cin >> choice;
    while (choice>3||choice<1){
        cout << "Invalid command, try again: " << endl;
        cin >> choice;
    }
    switch (choice){
        case 1:
            ArraySearch(first,index,0);
            break;
        case 2:
            ArraySearch(second,index,1);
            break;
        case 3:
            ArraySearch(third, index,2);
            break;
    }
    
    //Display the outputs here
    if (index.size()>0){
    cout << "The value you inserted was found in index: ";
            for (int x=0; x< index.size();x++){
                cout <<index[x]<< " ";
            }
    }
         else{
             cout << "The value does not exist in the array" << endl;
            }
    
    return 0;
}
//this is where all the functions take place
template <class T>
void ArraySearch (T a[], vector <int>& b, const int c){
   //Declare variables here
    T value;            //the value that will be searched
    string search[3]= {"Character", "Integer", "Float"};
    
    //display outputs and calculations
    cout << "Enter the " << search[c] << " you wish to search: ";
    cin >> value;
    for (int x=0; x<size;x++){
        if (a[x]==value){
            b.push_back(x);
        }
    }
}