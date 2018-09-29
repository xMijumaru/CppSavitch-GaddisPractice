/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: xMijumaru
 *
 * Created on September 29, 2018, 7:13 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Link.h"

using namespace std;

//Function Prototypes
void Menu (int, int, Link&);
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));//random numbers
    int random=rand()%90+10;     //random number 
    int num=0;                  //user generated number
    Link ThrowRand;             //will throw a random number to my object
 
    //process inputs and outputs
   Menu (num, random, ThrowRand);//begins the menu
    
    
    
    return 0;
}
//all the function prototypes
void Menu(int x, int y, Link& z){
    int choice=0;     //the choice of the user
    
    cout << "Testing the link list functions" << endl;
    z.appendnode(rand()%90+10);
    z.appendnode(rand()%90+10);
    
    while (choice != 5){ 
    cout << "Press 1 to append a number to our link list" << endl;
    cout << "Press 2 to display that current link list " << endl;
    cout << "Press 3 to delete a number of the link list" << endl;
    cout << "Press 4 to add a number onto the link list " << endl;
    cout << "Press 5 to end the menu" << endl;
    cin >> choice;
    while (choice<0||choice>5){
        cout << "Invalid Option, please try again: ";
        cin >> choice;
    }
    switch (choice){
        case 1:
            cout << "Please add the number you wish to append to the list : ";
            cin >> x;
            z.appendnode(x); //throws the x value to our linked list
            x=0;
            cout << "Number has been appended" <<endl;
            break;
        case 2:
            z.display();
            cout << endl;
            break;
        case 3:
            cout << "Please add the number you wish to delete: ";
            cin >>x;
            z.deletenode(x);
            break;
        case 4: 
            cout << "Please add the number you wish to add: " << endl;
            cin >> x;
            z.insertnode(x);
            break;
        case 5:
            break;
        default: 
            cout << "Out of bounds, drastic error " << endl;
            break;
    }
    
    }
}

