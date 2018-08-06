//SAVITCH CHAPTER 9 PRGRAMMING PROJECT 4 AIRPLANE WITH POINTER

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

//Global Variables
const int COL = 4;//the plane will always have 4 seats in regards to the column
				  //THE PROBLEM CONSIST OF ALWAYS HAVING THE COLUMNS SET TO 4

				  //Function Prototypes
void input(int &);//takes in the input for the rows

int main(int argc, char** argv) {
	//Declare the variables here
	int row;//the row of the plane
	typedef  char * seat;//seat object for the pointers
	seat *NewSeat;//the assignment of the seating goes here
	char letter[COL] = { 'A','B','C','D' };
	int ChangeRow; //changes the row
	int ChangeCol; //changes the column
	int choice = 0;//whether the person wants to change the seats of the plane or not

				   //display inputs and outputs here 

	input(row);//calls the input function

			   //declare the pointer and assign the values
	NewSeat = new seat[row];//sets the row equal to the amount the user input
	for (int x = 0; x<row; x++) {
		NewSeat[x] = new char[COL];
		//adds columns to each of the rows
	}

	//copies A, B, C, and D to the following pointers
	for (int x = 0; x<row; x++) {
		for (int y = 0; y<COL; y++) {
			NewSeat[x][y] = letter[y];
		}
	}

	while (choice != 2) {

		//Couts the results
		for (int x = 0; x < row; x++) {
			cout << x + 1 << " ";
			for (int y = 0; y < COL; y++) {
				cout << NewSeat[x][y] << " ";
			}
			cout << endl;
		}

		//The next part of this program will prompt the user to input the choices of the plane 
		cout << "\nWould you like to fill any planes seats?: \n1)Yes \n2)No " << endl;
		cin >> choice;
		while (choice < 1 || choice>2) {
			cout << "Invalid Option Chosen, please try again: ";
			cin >> choice;
		}
		if (choice == 1) {
			cout << "\nWhich Plane row would you like to fill? " << endl;
			for (int x = 0; x < row; x++) {
				cout << x + 1 << ") " << x + 1 << endl;
			}
			cin >> ChangeRow;

			while (ChangeRow<1 || ChangeRow>row) {
				cout << "Invalid Option Chosen, Please Try again: ";
				cin >> ChangeRow;
			}

			cout << "\nWhich Seat would you like to be switched out?\n1)A\n2)B\n3)C\n4)D" << endl;
			cin >> ChangeCol;
			while (ChangeCol > 4 || ChangeCol < 1) {
				cout << "Invalid Option Chosen, Please Try again: ";
				cin >> ChangeCol;
			}

			//This part of the program will change the number to X
			if (NewSeat[ChangeRow - 1][ChangeCol - 1] == 'X') {
				cout << "\nYou Can not fill a seat that has already been filled" << endl;
			}
			else if (NewSeat[ChangeRow - 1][ChangeCol - 1] != 'X') {
				NewSeat[ChangeRow - 1][ChangeCol - 1] = 'X';
			}

		}
	}
	//Couts the final answer
	cout << "This is the New Passanger seating chart :" << endl;
	for (int x = 0; x < row; x++) {
		cout << x + 1 << " ";
		for (int y = 0; y < COL; y++) {
			cout << NewSeat[x][y] << " ";
		}
		cout << endl;
	}

	//Dymanically delete the pointers here
	for (int x = 0; x < row; x++) {
		delete[] NewSeat[x];//this deletes the rows that were allocated
	}
	delete[] NewSeat;//deletes the pointer
	NewSeat = nullptr;//makes the pointer equal to nothing
	row = 0;//makes row equal to zero

	

	return 0;
}

//asks for a user input
void input(int & row) {

	cout << "How many rows are on the plane you wish to fill?: ";
	cin >> row;
	while (row<1) {
		cout << "Invalid Entry, Please try again: ";
		cin >> row;
	}
}

