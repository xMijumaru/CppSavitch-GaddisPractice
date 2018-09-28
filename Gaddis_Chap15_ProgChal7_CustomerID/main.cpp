/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: xMijumaru
 *
 * Created on September 27, 2018, 6:33 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "personaldata.h"
#include "customerdata.h"

using namespace std;
const int MM=300;           //more than is needed

//Function Prototypes
void input(string&,string&,string&,string&,string&, int& , int&);
void menu (customerdata&);       //prompts a short menu
int main(int argc, char** argv) {
    //Declare the variables here
    string name;
    string last;
    string address;
    string city;
    string state;
    int zip=0;
    int phone=0;
    
    
    //Display outputs and calculations here
    input (name,last,address,city,state,zip,phone);
    customerdata a(name,last,address,city,state,zip,phone);
   
    return 0;
}
void menu (customerdata& a){
    int choice=0;
    while(choice !=3){
    cout << a.getfn() << endl;
    cout << a.getln() << endl;
    cout << a.getad() << endl;
    cout << a.getci() << endl;
    cout << a.getst() << endl;
    cout << a.getzi() << endl;
    cout << a.getph() << endl;
    
    if (a.getmail()==false){
        cout << "Customer is not on the mailing list" << endl;
    }else{
        cout << "Customer is on the mailing list " << endl;
    }
    cout << "Press 1 to add " << a.getfn() << " " << a.getln() << " to the"
            <<" mailing list" << endl;
    cout << "Press 2 to remove from the mailing list " << endl;
    cout << "Press 3 to terminate " << endl;
    cin >> choice;
    switch (choice){
        case 1:
            a.setmail(false);
            break;
        case 2:
            a.setmail(true);
    }
    }
}

//all of the function definitions
void input(string&a, string&b, string&c, string&d ,string&e , int& f, int&g){
    cout << "Enter the first name: ";
    cin >> a;
    cout << "Enter the last name:  ";
    cin >> b;
    cout << "Enter the address:    ";
    cin >> c;
    cout << "Enter the city:       ";
    cin >> d;
    cout << "Enter the State:      ";
    cin >> e;
    cout << "Enter the Zip Code:   ";
    cin >> f;
    while (f<=9999||f>=100000){
        cout << "Invalid zip code, please try again: ";
        cin >>f;
    }
    cout << "Enter the Phone Number with the area code: " << endl;
    cin >> g;
    while (g<=999999999||g>=10000000000){
        cout << "Invalid Phone number, Please try again: ";
        cin >> g;
    }
        
}