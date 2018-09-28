/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   personaldata.cpp
 * Author: xMijumaru
 * 
 * Created on September 27, 2018, 8:00 PM
 */

#include "personaldata.h"


personaldata::personaldata(){
    first="blank";
    last="blank";
    address="blank";
    city="blank";
    zip=0;
    phone=0;
}
personaldata::personaldata(string a, string b, string c, string d, string e,
        int f, int g){
    first=a;
    last=b;
    address=c;
    city=d;
    state=e;
    zip=f;
    phone=g;
}
string personaldata::setad(string x)
{
    address=x;
}
string personaldata::setci(string x){
    city=x;
    }

string personaldata::setfn(string x){
    first=x;
}
string personaldata::setln(string x){
    last=x;
} 
int personaldata::setzi(int x){
    zip=x;
    
} 
string personaldata::setst(string x){
    state=x;
    
}
int personaldata::setph(int x){
    phone=x;
}