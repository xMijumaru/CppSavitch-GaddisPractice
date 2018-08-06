//SAVITH CHAPTER 8 PROGRAMMING PROJECT 7, LESS THAN SEXIST LANGUAGE
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

//global variables
const int mm = 300;//more than needed in the char array

//function prototypes
void input(char[], vector <char> &);//this function will do the input and correction
void print(char[], vector<char> &);//prints out the final solution
void corrector(char[]); //capitalizes and lowers

int main() {
	//declare variables here
	char sentence[mm];//the sentence for the original sentence
	vector <char>revision;//the revision that will be stored onto this vector

	//display inputs and outputs here
	input(sentence, revision);//calls fourth the input function
	print(sentence, revision);//prints out the final solution


	return 0;
}
//this function prints out the final solution
void print(char s[], vector <char> & r) {
	char choice;//the choice of the user
	cout << "\nWould you like this sentence or the original?" << endl;
	for (int x = 0; x < r.size(); x++) {
		cout << r[x];
	}
	cout << endl;
	cout << "\n1) Original" << endl;
	cout << "2) New" << endl;
	cin >> choice;
	while (choice < 49 || choice>50) {
		cout << "Invalid choice, please try again: ";
		cin >> choice;
	}
	switch (choice) {
		case '1': {
			r.resize(1);
			cout << s << endl;
			break;
		}
		case '2': {
			for (int x = 0; x < r.size(); x++) {
				cout << r[x];
			}
			cout << endl;
			break;
		}
	}
			
}

//function prototypes
void input(char s[], vector <char> & r) {
	cout << "Enter your sentence: " << endl;
	cin.getline(s, mm);
	cout << "\nYour original sentence (with few edits): " << endl;
	corrector(s);
	cout << s << endl;
	for (int x = 0; x < strlen(s); x++) {
		r.push_back(s[x]);//pushes back the letter
		if (s[x-4]+s[x-3]+s[x-2]+s[x-1]+s[x]==396) {
			r.resize(x);//eliminates the period
			r.push_back(32);
			r.push_back(111);
			r.push_back(114);
			r.push_back(32);
			r.push_back(104);
			r.push_back(101);
			r.push_back(114);
			r.push_back(46);//pushes the period back

		}
		//the case if him is in the middle of the sentence or beginning
		if ((s[x - 4] + s[x - 3] + s[x - 2] + s[x - 1] + s[x] == 382)||
			(s[x - 3] + s[x - 2] + s[x - 1] + s[x] == 318 && x - 3 == 0)) {
			r.push_back(111);
			r.push_back(114);
			r.push_back(32);
			r.push_back(104);
			r.push_back(101);
			r.push_back(114);
			r.push_back(32);
		}
		//if there is no period at the end of the sentence
		if (s[x - 3] + s[x - 2] + s[x - 1] + s[x] == 350 
			&& x==strlen(s)-1) {
			r.push_back(32);
			r.push_back(111);
			r.push_back(114);
			r.push_back(32);
			r.push_back(104);
			r.push_back(101);
			r.push_back(114);
			r.push_back(46);//pushes the period 
		}
		//adds the she in the middle
		if ((s[x - 3] + s[x - 2] + s[x - 1] + s[x] == 269) ||
			(s[x - 2] + s[x - 1] + s[x] == 205 && x - 2 == 0)) {
			r.push_back(111);
			r.push_back(114);
			r.push_back(32);
			r.push_back(115);
			r.push_back(104);
			r.push_back(101);
			r.push_back(32);
		}
		//adds she at the end
		if (s[x - 3] + s[x - 2] + s[x - 1] + s[x] == 283) {
			r.resize(x);//eliminates the period
			r.push_back(32);
			r.push_back(111);
			r.push_back(114);
			r.push_back(32);
			r.push_back(115);
			r.push_back(104);
			r.push_back(101);
			r.push_back(46);//pushes the period 
		}
		//adds she at the end if there is no period
		if (s[x - 2] + s[x - 1] + s[x] == 237
			&& x == strlen(s) - 1) {
			r.push_back(32);
			r.push_back(111);
			r.push_back(114);
			r.push_back(32);
			r.push_back(115);
			r.push_back(104);
			r.push_back(101);
			r.push_back(46);//pushes the period 
		}
	}

}
//this part will capitalize the first word and lowercase the other
void corrector(char s[]) {
	//capitalizes
	if (s[0] >= 97 && s[0] <= 122) {
		s[0] -= 32;
	}
	//lowers
	for (int x = 1; x < strlen(s); x++) {
		if (s[x] >= 65 && s[x] <= 90) {
			s[x] += 32;
		}
	}
}