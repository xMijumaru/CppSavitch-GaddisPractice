
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "MOVIE.h"
#include <string>
#include <cstring>

using namespace std;

struct movie{
    string name;    //the name of the movie
    string MPAA;    //the MPAA rating
};


int main(int argc, char** argv) {
//Declare Variables here
    const int num=2; //the program problem wants 2 movies
    movie s[num];    //creates a structure with 2 movies

    
    //Initialize Variables
    s[0].MPAA="R";
    s[0].name="Movie 1";
    
    s[1].MPAA="PG-13";
    s[1].name="Movie 2";
        
    //Display Inputs and outputs
        MOVIE movie1 (s[0].name,s[0].MPAA),
              movie2 (s[1].name,s[1].MPAA);
        
                movie1.Display();       //displays movie 1
                movie2.Display();       //displays movie 2

    return 0;
}

