//SAVITCH CHAPTER 9 PROBLEM 16 READ IN RACER FILE IN ORDER TO CONDUCT A SEARCH
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
	//declare the variables here
	ofstream in;//outputs and edits the file
	ifstream out;//reads in the file
	vector <int>GunTime; //the gun time of racers
	vector <int> RaceNum; //the racers number
	vector <int> Hour; // the times of the racers
	vector <int> Min;//the minute of the racer
	vector <int> Sec;// the second of the player
	char choice=0; // the choice by the user

	//Display inputs and outputs here
	out.open("Text.txt");//opens the file
	
	//create the integers that will hold the value in order to start the push
	//back proccess
	int gun, num, hour, min, sec;//gun time, racer number, hour, min, second
	while (out >> gun >> num >> hour >> min >> sec) {
		GunTime.push_back(gun);
		RaceNum.push_back(num);
		Hour.push_back(hour);
		Min.push_back(min);
		Sec.push_back(sec);
	}

	//this part will run the menu
	while ( choice != 51) {
		cout << "Press 1 to view the log that was read in" << endl;
		cout << "Press 2 to search for a specific racer" << endl;
		cout << "Press 3 to end the menu" << endl;
		cin >> choice;
		while (choice < 49 || choice>51) {
			cout << "Invalid Option chosen, please try again: ";
			cin >> choice;
		}
		switch (choice) {
			case '1':{
				int size = GunTime.size();
				for (int x=0;x<size;x++){
					if (GunTime[x] < 10) {
						cout << 0;
					}
					cout << GunTime[x] << " "
						 << RaceNum[x] << " ";
					if (Hour[x] < 10) {
						cout << 0;
					}
					cout << Hour[x] << " ";
					if (Min[x] < 10) {
						cout << 0;
					}
					cout << Min[x] << " ";
					if (Sec[x] < 10) {
						cout << 0;
					}
					cout << Sec[x] << endl;
				}
				break;
			}
			case '2': {
				vector<int>occur;//the occurance of a specific number
				int search;
				cout << "Which racer would you like to search: ";
				cin >> search;
				//will run my search for occurances
				for (int x = 0; x < RaceNum.size(); x++) {
					if(search == RaceNum[x]) {
						occur.push_back(x);
					}
				}
				if (occur.size() < 1) {
					cout << "The Number was not found" << endl;
					cout << endl;
				}
				else {
					for (int x = 0; x < occur.size(); x++) {
						if (GunTime[occur[x]] < 10) {
							cout << 0;
						}
						cout << GunTime[occur[x]] << " " << RaceNum[occur[x]]
							<< " ";
						if (Hour[occur[x]] < 10) {
							cout << 0;
						}
						cout << Hour[occur[x]] << " ";
						if (Min[occur[x]] < 10) {
							cout << 0;
						}
						cout << Min[occur[x]] << " ";
						if (Sec[occur[x]] < 10) {
							cout << 0;
						}
						cout << Sec[occur[x]] << endl;

					}
				}
				break;
			}
		}

	}
	


	return 0;
}