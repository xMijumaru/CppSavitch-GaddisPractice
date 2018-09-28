/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   customerdata.cpp
 * Author: xMijumaru
 * 
 * Created on September 28, 2018, 5:27 AM
 */

#include "customerdata.h"

customerdata::customerdata():personaldata(){
    MailingList=false;
    srand(static_cast<unsigned int>(time(0)));
    customerNumber=rand()%10000+10;
}
customerdata::customerdata(string a, string b, string c, string d, string e, 
        int f, int g):
 personaldata(a, b, c, d, e, f, g){
    MailingList=false;
    srand(static_cast<unsigned int>(time(0)));
    customerNumber=rand()%10000+10;
}
customerdata::customerdata(string a, string b, string c, string d, string e,
        int f, int g, int h, bool i): personaldata(a, b, c, d, e, f, g){
    customerNumber=h;
    MailingList=i;
}
bool customerdata::setmail(bool x){
 MailingList=x;   
}
int customerdata::setnum(int y){
    customerNumber=y;
}