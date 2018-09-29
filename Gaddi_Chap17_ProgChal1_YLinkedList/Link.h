/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Link.h
 * Author: xMijumaru
 *
 * Created on September 29, 2018, 7:13 AM
 */

#ifndef LINK_H
#define LINK_H
#include <cstdlib>
#include <iostream>
using namespace std;

class Link {
protected:
    struct node{
        int value;          //the value for the integer to be held
        node *next;         //pointer to the next value
    };
    node *head;             //will point to the head of the linked
                            //list
    
public:
    //Constructor
    Link()
    {head=nullptr;}
    void appendnode(int);           //adds to the end of the list
    void insertnode (int);          //inserts a node in the middle
    void deletenode (int);          //deletes a specific node
    void display () const;          //displays the list
    virtual ~Link();

};

//12345678901234567890123456789012345678901234567890123456789012345678901234567
//12345678901234567890123456789012345678901234567890123456789012345678901234567

//this is for the cpp part
void Link::appendnode(int x){
    node *newnode;          //points to the new node
    node *hunter;          //the point of this is to traverse the nightmare

//Allocates a new node and stores the value the newnode
    newnode= new node;
    newnode->value=x;
    newnode->next = nullptr;
    
//this checks to see if there is a new node on the list
    if(!head){
        head=newnode;
    }
    else{
    
    hunter=head;        //my hunter will use the head of the variable to
                        //begin traversing the nightmare
    
//this part of the append mode will begin to look for the last value
    while(hunter->next){
        hunter=hunter->next;
    }        //finds the last node on the list
        //insert onto the last part of the list
        hunter->next=newnode;
    
    }
}

void Link::display() const{
    node * hunter;      //my hunter will traverse through the nightmare
    
    //makes the hunter begin his nightmare in the beginning of my linked list
    hunter=head;
    //begins the nightmare
    while(hunter!=nullptr){
        cout << hunter->value << " ";
        hunter=hunter->next;
    }
    
}

void Link::deletenode(int y){
    node *hunter;       //traverses the nightmare
    node *lastnode;     //goes through the next node
    if (head==nullptr){
        cout << "Empty link list, cannot delete" << endl;
    }
    if (head->value == y){
        hunter=head->next;
        delete head;
        head=hunter;
    }
    //if hunter is not in the beginning
    else {
        hunter=head;
        while (hunter!=nullptr&&hunter->value!=y){
            lastnode=hunter;
            hunter=hunter->next;
        }
        if (hunter){
            lastnode->next=hunter->next;
            delete hunter;
        }
    }
}

//the purpose is to insert an integer onto the link list
void Link::insertnode(int z){
    node *newnode;
    node *hunter;
    node *lastnode=nullptr;
    
    //allocates a new node and stores it there
    newnode = new node;
    newnode->value=z;
    
    //this is just in case there is nothing on the node
    if (head==nullptr){
        newnode->next=nullptr;
    }
    //the purpose of this is to insert newnode
    else{
        //position at the head of the list
        hunter=head;
        
        //initializes previousnode to nullptr
        lastnode=nullptr;
        
        while (hunter!= nullptr&& hunter ->value <z){
            lastnode=hunter;
            hunter=hunter->next;
        }
        //if the new node is to be 1st on the list
        //insert it before all other nodes
        if (lastnode==nullptr){
            head=newnode;
            newnode->next=hunter;
        }else{
            //otherwise insert after the previous code
            lastnode->next=newnode;
            newnode->next=hunter;
        }
        
    }    
    
}


Link::~Link(){
    node *hunter;
    node *nextnode;
    
    hunter=head;//always has to be equal to the head
    
    while (hunter != nullptr){
        nextnode=hunter->next;      //points to the next one
        delete hunter;              //deletes current hunter
        hunter=nextnode;            //makes hunter equal to the next variable
    }
}

#endif /* LINK_H */

