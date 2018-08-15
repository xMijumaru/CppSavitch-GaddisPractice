//checks for a sentence occurance
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

//Function Prototypes


int main(int argc, char** argv) {
    //Declare Variables here
    const int MM=300;       //more than needed
    char enter[MM];         //the phrase that will be entered
    char phrase[MM];        //the phrase that the program will check
    int NumToCk;            //the number of chars that will be checked
    int SentSiz;            //the original size of the sentence
    int PhraseCon;          //Converts the phrase to an integer value
    int EQUAL;              //calculates the int value in order to make it equal
    vector <int> line;      //the lines that the phrase are included in
    
    //Declare inputs and outputs
    cout << "Enter the sentence that will be checked: " << endl;
    cin.getline(enter, MM);
    cout << "Enter the phrase you wish to check: " << endl;
    cin.getline(phrase, MM);
    
        //Process Calculations here
    
        //this part sets all the initial calculations
        SentSiz= strlen(enter);      //the size of the sentence
        NumToCk=strlen(phrase);       //makes the amount equal to the variable
        PhraseCon=0;                  //initially sets the value to zero
        EQUAL=0;                      //sets the value of equal to zero
        
        for (int x = 0; x < NumToCk; x++ ){
            PhraseCon += phrase[x];   //sets the value of phrase con
        }
        
        //this part will start to run the check
            for (int y = 0; y < SentSiz; y++ ){
                
                if ( phrase[0] == enter[y] ){
                    
                    for (int z = y; z < NumToCk + y; z++ ){
                        
                        EQUAL += enter[z];
                    }
                }
                if ( EQUAL == PhraseCon ){
                    
                    line.push_back(y+1);
                    
                    EQUAL=0;
                }
                else {
                    
                    EQUAL=0;
                    
                }
            }
            //Display outputs
        if (line.size() >= 1 ){
            cout << "The Phrase: " << "'" << phrase << "'" << endl;
            cout << "was found in Char: ";
            for (int x = 0; x < line.size(); x++ ){
                cout << line[x] << " ";
            }
        }
        else {
            cout << "No Occurence found " << endl;
        }
        
    return 0;
}

