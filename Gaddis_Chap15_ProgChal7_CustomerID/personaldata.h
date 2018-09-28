/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   personaldata.h
 * Author: xMijumaru
 *
 * Created on September 27, 2018, 8:00 PM
 */

#ifndef PERSONALDATA_H
#define PERSONALDATA_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctime>
using namespace std;

class personaldata {
public:
  public:
    personaldata();             //a blank constructor
    personaldata(string, string, string, string, string, int, int);
   //mutators
    string setfn(string);              //sets in the first name
    string setln(string);              //sets in the last name
    string setad(string);             //sets the address of the customer
    string setci(string);                
    string setst(string);
    int setzi(int);
    int setph(int);
    
    //accessors
   string getfn() const{return first;}
   string getln() const {return last;}
   string getad() const{return address;}
   string getci() const {return city;}
   string getst () const {return state;}
   int getzi() const {return zip;}
   int getph() const {return phone;}
   
   
    
protected:
   
    string first;               //the first name of the person
    string last;                          
    string city;
    string address;
    string state;               //the state of the person
    int zip;                    //the zip code of the person
    int phone;                  //the phone number of the person


};

#endif /* PERSONALDATA_H */

