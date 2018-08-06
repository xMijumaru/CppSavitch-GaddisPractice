//THE PURPOSE OF THIS PROGRAM IS TO CREATE A COMPUTER LAB PROGRAM THAT KEEPS TRACK AND SEARCHES FOR USERS
//SAVITCH PROGRAMMING PROJECT 5 COMPUTER LAB
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cctype>
#include <sstream>//converts int,float etc to string
using namespace std;

//Global Variables
const int lab = 4;//The number of labs will always be equal to 4
typedef string *s;//creates an object to the character pointer s

//Function Prototypes
void *choice1 (s *);//the option for the first choice
void *choice2(s *);//the option for the second choice
void *choice3(s *);//the option for the third choice
void *output(s *);//the function for the outputs

int main() {
	//Decalare variables here
	int change[lab] = { 5,6,4,3 };//the corresponding values 
	
	s *NumOfLabs; // keeps tracks of the lab components
	NumOfLabs = new s[lab];//creates a pointer equal to 4
	int choice = 0;

	//Dynamically allocate the second part of the array
	for (int x = 0; x < lab; x++) {
		NumOfLabs[x] = new string[change[x]];//keeps track of the computer labs
	}

	//sets the value for the first computer lab
	for (int x = 0; x < 5; x++) {
		NumOfLabs[0][x] = "empty"; 
	}
	//sets the value for the second computer lab
	for (int x = 0; x < 6; x++) {
		NumOfLabs[1][x] = "empty";
	}
	//sets the value for the third computer lab
	for (int x = 0; x < 4; x++) {
		NumOfLabs[2][x] = "empty";
	}
	//sets the value for the last computer lab
	for (int x = 0; x < 3; x++) {
		NumOfLabs[3][x] = "empty";
	}
	
	do {
		//cout all the solutions
		cout << "Lab Number Computer Stations" << endl;
		cout << endl;
		output(NumOfLabs);//shows the output of the computer lab
		
		//This parts create the menu option for the program
		cout << "\nPress 1 to log a user into the system" << endl;
		cout << "Press 2 to log a user out of the system" << endl;
		cout << "Press 3 to search for a user name" << endl;
		cout << "Press 4 to end the program and menu" << endl;
		cin >> choice;

		//this switch case will handle all the options
		switch (choice) {
			case 1: {
				choice1(NumOfLabs);//calls the choice 1 function
				break;
			}
			case 2: {
				choice2(NumOfLabs);//calls fourth the choice 2 function
				break;
			}
			case 3: {
				choice3(NumOfLabs);//calls the choice 3 function
				break;
			}
			case 4: {
				cout << "Terminating Program " << endl;
				break;
			}
			default:{
				cout << "Invalid Entry chosen" << endl;
			}

		}

	} while (choice != 4);

	

	//Delete the variables here
	for (int x = 0; x < lab; x++) {
		delete[] NumOfLabs[x];
	}
	delete[] NumOfLabs;
	NumOfLabs = nullptr;


	return 0;
}

//function prototypes
void *output(s * NumOfLabs) {
	cout << "1   ";
	for (int x = 0; x < 5; x++) {
		cout << x + 1 << ": " << NumOfLabs[0][x] << " ";
	}
	cout << endl;

	cout << "2   ";
	for (int x = 0; x < 6; x++) {
		cout << x + 1 << ": " << NumOfLabs[1][x] << " ";
	}
	cout << endl;

	cout << "3   ";
	for (int x = 0; x < 4; x++) {
		cout << x + 1 << ": " << NumOfLabs[2][x] << " ";
	}
	cout << endl;

	cout << "4   ";
	for (int x = 0; x < 3; x++) {
		cout << x + 1 << ": " << NumOfLabs[3][x] << " ";
	}
	cout << endl;

	return 0;
}
//the purpose of this function is to log a user into a system
void *choice1(s * NumOfLabs) {
	int comp;//the temporary choice of the user for the computer
	int lab;//the lab number for the computer
	int id;//the id number of the user
	cout << "Enter the computer lab number (1-4), followed by the enter button, " << endl;
	cout << "then the computer number:" << endl;
	cin >> lab;
	cin >> comp;
	//this part will run the checks for the functions
	while (lab == 1 && (comp > 5 || comp < 1)) {
		cout << "Computer lab 1 must be between 1-5, try again: ";
		cin >> comp;
	}
	while (lab == 2 && (comp > 6 || comp < 1)) {
		cout << "Computer lab 2 must be between 1-6, try again: ";
		cin >> comp;
	}
	while (lab == 3 && (comp > 4 || comp < 1)) {
		cout << "Computer lab 3 must be between 1-4, try again: ";
		cin >> comp;
	}
	while (lab == 4 && (comp > 3 || comp < 1)) {
		cout << "Computer lab 4 must be between 1-3, try again: ";
		cin >> comp;
	}
	//this parts prompts the user to enter the id number
	cout << "Enter the 5 digit ID number of the person you want to log in: ";
	cin >> id;

	//runs the checks for the id numbers
	while (id < 10000 || id>99999) {
		cout << "ID number must be 5 digits, try again: ";
		cin >> id;
	}
	
	//converts the integer to a string

	stringstream NewInt;//creates a a stringstream object named newint
	NewInt << id;//makes new int equl to the id
	string Input = NewInt.str();//makes a string equal to the integer
	

	//this part logs in the id and checks to see if someone else is logged in
	if (NumOfLabs[lab - 1][comp - 1] == "empty") {
		NumOfLabs[lab - 1][comp - 1] = Input;
	}
	if (NumOfLabs[lab - 1][comp - 1] != "empty") {
		cout << "\nLog in failed, Another user is already logged in" << endl;
	}
	//beautifies it a little
	cout << endl;

	return 0;
}
//this function runs the second choice
void *choice2(s* NumOfLabs) {
	int lab;//the number of lab
	int comp;//the computer that has to be logged out
	cout << "Enter the computer lab number (1-4), followed by the enter button, " << endl;
	cout << "then the computer number:" << endl;
	cin >> lab;
	cin >> comp;
	//this part will run the checks for the functions
	while (lab == 1 && (comp > 5 || comp < 1)) {
		cout << "Computer lab 1 must be between 1-5, try again: ";
		cin >> comp;
	}
	while (lab == 2 && (comp > 6 || comp < 1)) {
		cout << "Computer lab 2 must be between 1-6, try again: ";
		cin >> comp;
	}
	while (lab == 3 && (comp > 4 || comp < 1)) {
		cout << "Computer lab 3 must be between 1-4, try again: ";
		cin >> comp;
	}
	while (lab == 4 && (comp > 3 || comp < 1)) {
		cout << "Computer lab 4 must be between 1-3, try again: ";
		cin >> comp;
	}
	if (NumOfLabs[lab - 1][comp - 1] == "empty") {
		cout << "No user has been logged in, command failed " << endl;
	}
	if (NumOfLabs[lab - 1][comp - 1] != "empty") {
		NumOfLabs[lab - 1][comp - 1] = "empty";
		cout << "User has been logged out" << endl;
	}
	//beautifies it a little
	cout << endl;

	return 0;
}
//the purpose of this function is to run the 3rd choice option
void *choice3(s* NumOfLabs) {
	int search;//the id to search
	bool found;//if the computer is found, a true will be returned to signify that it was found
	int lab=0;//the lab that the id will be found in
	int comp=0;//the computer that the id will be found in
	int occurance=0; //the frequency of the id number
	cout << "Enter the number you wish to search: ";
	cin >> search;
	while (search < 10000 || search>99999) {
		cout << "Number must be 5 digits, try again:  ";
		cin >> search;
	}
	//changes the integer to string in check
	stringstream change;
	change << search;
	string NewSearch = change.str();

	//runs all the checks
	for (int x = 0; x < 5; x++) {
		if (NumOfLabs[0][x] == NewSearch) {
			found = true;
			lab = 1;
			comp = x + 1;
			occurance++;
		}
		
	}
	
	for (int x = 0; x < 6; x++) {
		if (NumOfLabs[1][x] == NewSearch) {
			found = true;
			lab = 2;
			comp = x + 1;
			occurance++;
		}
	}
	
	for (int x = 0; x < 4; x++) {
		if (NumOfLabs[2][x] == NewSearch) {
			found = true;
			lab = 3;
			comp = x + 1;
			occurance++;
		}
	}

	for (int x = 0; x < 3; x++) {
		if (NumOfLabs[3][x] == NewSearch) {
			found = true;
			lab = 4;
			comp = x + 1;
			occurance++;
		}
	}
	if (found == true) {
		cout << "ID " << NewSearch << " was found " << endl;
		cout << "Computer Lab:    " << lab << endl;
		cout << "Computer Number: " << comp << endl;
		cout << "Number of Frequencies: " << occurance << endl;
	}
	else{
		cout << "ID " << NewSearch << " was not found" << endl;
	}
	cout << endl;
	return 0;
}