
#ifndef MOVIE_H
#define MOVIE_H

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class MOVIE{
public:
    MOVIE ();                                   //regular constructor
    MOVIE (string, string);         //overloaded constructor
    void Display () const;                     //runs the rating menu
    
protected:
    string MovRate;     //the MPAA rating of the movie
    string MovName;     //the name of the movie

    
    
  
    
};
#endif /* MOVIE_H */

