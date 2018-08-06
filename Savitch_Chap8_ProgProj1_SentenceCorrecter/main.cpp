//SAVITCH PROGRAMMING PROJECT 1 CHAPTER 8 CORRECT A SENTENCE IN A CHARACTER ARRAY
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
//global variables

//function prototypes
void input(const int, char [] );
void correct(const int, char[]);//corrects the sentence

int main() {
	//Declare the variables here
	const int max = 101;//the question wants the array to be a max of 100 chars
	char sent[max];//the array that will carry the sentence

	//Declare inputs and outputs
	input(max, sent);//calls the input function
	correct(max, sent);//calls the corrector function


	return 0;
}
//correcter function
void correct(const int max, char sent[]) {
	//Declare variables here
	vector <char>Final;//prints out the final sentence
	int limit = strlen(sent);//the size of the cstring

	//In the ASCII table, lower case letters are 97-122. subtracting 32
	//will change it to its upper case counterpart
	if (sent[0] >= 97 && sent[0] <= 122) {
		sent[0] -= 32;
	}
	//this part will check for uppercase letters
	//uses the same ASCII TABLE mechanic like above, but their sets are now
	//for lowercase
	for (int x = 1; x < limit; x++) {
		if (sent[x] >= 65 && sent[x] <= 90) {
			sent[x] += 32;
		}
	}
	//the corrections will be done on here
	for (int x = 0; x < limit; x++) {
		//this case runs the words that dont have a space proceeding them
		if (sent[x] != ' ' && sent[x + 1] != ' '||sent[x+1]=='\0') {
			Final.push_back(sent[x]);
		}
		//this case runs the words that have a space proceeding it
		if (sent[x] != ' '&&sent[x + 1] == ' ') {
			Final.push_back(sent[x]);
			Final.push_back(32);//32 is ascii for space
		}
	}
	//OUTPUTS THE FINAL SOLUTION
	cout << "The Corrected Sentence: " << endl;
	for (int y = 0; y < Final.size(); y++) {
		cout << Final[y];
	}
	cout << endl;
}

//input function
void input(const int max, char sent[] ) {
	cout << "Enter a sentence with 100 character or less (ended with a period)" << endl;
	cin.getline(sent, max);
}