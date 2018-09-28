/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   customerdata.h
 * Author: xMijumaru
 *
 * Created on September 28, 2018, 5:27 AM
 */

#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H
#include "personaldata.h"
class customerdata : public personaldata {
public:
    customerdata();
    customerdata(string, string, string, string, string, int, int);
    customerdata(string, string, string, string, string, int, int, int, bool);
    int setnum(int);
    bool setmail(bool);
    int getnum()const{return customerNumber;}
    bool getmail()const{return MailingList;}
    
private:
    int customerNumber; //the customers number
    bool MailingList;        //if the customer is on the mailing list
};

#endif /* CUSTOMERDATA_H */

