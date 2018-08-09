//SAVITCH PROGRAMMING PROJECT 1 GRADING
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>


using namespace std;

//GLOBAL VARIABLES
const int MAX=300; //more than needed


//structures
struct student{
    float quiz1;//the first quiz score
    float quiz2;//the second quiz score
    float midterm;//the midterm score
    float FINAL; // the final exam score
    float grade;
    char letter;
};

int main(int argc, char** argv) {
//Declare variables here
int choice;//the choice in the beginning

//display inputs and output


    cout << "How many students would you like to grade: " << endl;
    cin >> choice;

    //new declared variables
        const int amount=static_cast<const int>(choice);
        char input[amount][MAX];//the array for the cin.getline
        student s[amount];//the amount of students for the structure
        
        cin.ignore();//ignores the enter and eats it up before the
        //for loop begins
        
        //inputs all the information
        cout << "Input all grades in terms of %" << endl;
            for (int x = 0; x < amount; x++ ){
                cout << "Enter the name for student " << x+1 << ": ";
                cin.getline(input[x], MAX); 
                cout << "Enter the quiz 1 and 2 score for that student: ";
                cin >> s[x].quiz1 >> s[x].quiz2;
                cout << "Enter the midterm score: ";
                cin >> s[x].midterm;
                cout << "Enter the the score for the final: ";
                cin >> s[x].FINAL;
                
                //THIS NEXT PART CALCULATES THE GRADE AND LETTER
                    cout << fixed << showpoint << setprecision(2);
                    s[x].grade=(((s[x].quiz1+s[x].quiz2)/2)*.25)+//quiz
                            (s[x].midterm*.25)+//midterm score
                            (s[x].FINAL*.50);//final score
                    
                //THIS NEXT PART CALCULATES THE FINAL SCORE
                    if (s[x].grade>=90){
                        s[x].letter=65;
                    }
                    if (s[x].grade<90&&s[x].grade>=80){
                        s[x].letter=66;
                    }
                    if (s[x].grade<80&&s[x].grade>=70){
                        s[x].letter=67;
                    }
                    if(s[x].grade<70&&s[x].grade>=60){
                        s[x].letter=68;
                    }
                    if (s[x].grade<60){
                        s[x].letter=70;
                    }
                    
                //EATS UP THE LAST ENTER FOR THE CIN.GETLINE
                    cin.ignore();
            }
        
 
    //output the results
        cout << "Grade Calculations" << endl;
    for (int x = 0; x < amount ; x++ ){
        cout << "\nStudent:          " << input[x] << endl;
        cout << "Grade Percentage: " << s[x].grade << "%" << endl;
        cout << "Final Grade     : " << s[x].letter << endl;

    }

       
    return 0;
}

