
#include "MOVIE.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

MOVIE::MOVIE(){
    
    MovName="NULL";
    MovRate="NULL";
    
}

MOVIE::MOVIE(string a , string c ){
    
    MovName=a;
    MovRate=c;
    
}

void MOVIE::Display() const{
    //Declare variables here
    vector <int> rating={0,0,0,0,0};
    int num;                    //the number of people that will rate it
    int temp;                   //the temporary value will store the info
    int enter;                  //entering the ratings
    float AvRate;               //The average rating
    
    //Display inputs and outputs
    cout << "How Many People will rate " << MovName << endl;
    cin >> num;
    
    for (int x = 0; x < num; x++ ){
        cout << "Enter the Rating for person " << x+1 << ": ";
         cin >> enter;
         
            while (enter > 5 || enter < 1 ){
                cout << "Only Numbers 1-5 are accepted, try again: ";
                cin >>enter;
            }
         
       rating[enter-1]+=1;        //adds it to the vector
       temp+=enter;               //adds the overall rating to num
       
    }
    
    AvRate= temp/num;
    
    //Output the results on here
        cout << fixed << showpoint;
        cout << setw(1) << "Name: " << setw(49) << MovName << endl;
        cout << setw(1) << "Rating: " << setw(41) << MovRate << endl;
        for (int x = 0; x < rating.size(); x++ ){

            cout << setw(1) << "Number of " << x+1 << " rates: " 
                    << setw(30) << rating[x] << endl;

        }
        
        cout << "Average Rating: " << setprecision(2) << AvRate << endl;
    
}
