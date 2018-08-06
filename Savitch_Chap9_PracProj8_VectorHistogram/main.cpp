//SAVITCH CHAPTER 9 PROGRAMMING PROJECT 8, GRADING HISTOGRAM USING A VECTOR AND STORING IT INTO A DYNAMIC ARRAY TO CREATE A HISTOGRAM
#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>//stringstream function

using namespace std;

//Global Variables


//Function Prototypes
void input(vector <float> &, vector <float> &);//passes the vector in by reference and inserts
//the vector
void WorkPrint(vector <float> &, float *, int, vector <float> &);//does the work and prints out the solutions

int main() {
	//declare the variables here
	vector <float> grade;//the vector that takes in a grade
	vector <float>var;//will insert the variables that were inserted
	float *histogram; //will create a dynamic array for the histogram to be stored onto
	
	//Display the inputs and outputs
	input(grade, var);// calls fourth the input function
	
	//this part will create a dynamic array for the histogram to be stored in
	histogram = new float[grade.size()];//creates a dynamic array the size of the vector

	int n = grade.size();//the size to pass into the WorkPrint function

	WorkPrint(grade, histogram, n, var);//calls fourth the work and printing of the solution


	//Delete the dynamically allocated arrays
	delete[] histogram;
	histogram = nullptr;



	return 0;
}

//the purpose of this function is to do the work and print out the solutions
void WorkPrint(vector <float> & grade, float * histogram, int n, vector <float> & var) {
	vector<float>occur;//sticks the occurance into this vector
	int check = 0;//number of checks that will be done
	int limit = var.size();//the limit for the computer to check
	while (check != limit) {
		int NumOcc = 0; //keeps track of the number of occurances
		check++;//increases the number of checks
		for (int x = 0; x < grade.size(); x++) {
			if (var[check-1] == grade[x]) {
				NumOcc++;
			}
		}
		occur.push_back(NumOcc);//pushes the occurance rate to the vector
	
	}
	//NOW THAT WE HAVE OUR INTEGERS AND OCCURANCES, IT IS TIME TO CREATE THE 
	//DYNAMIC ARRAY
	float *answer1 = new float[var.size()];//the dynamic array to carry the variables
	float *answer2 = new float[occur.size()];//variable to carry the occurance variables
	int i = var.size();//MUST USE I AND J BECAUSE COMPILER WILL GIVE AN ERROR IF YOU USE A VECTOR.SIZE()
	int j = occur.size();//^^DUE TO INVALID CONVERSION OF POINTER TO VECTOR
	//copy the content of the vector onto the arrays
	for (int x = 0; x < i; x++) {
		answer1[x] = var[x];
	}
	for (int x = 0; x < j; x++) {
		answer2[x] = occur[x];
	}
	//OUTPUTS THE FINAL RESULTS
	for (int x = 0; x < i; x++) {
		cout << "Number of " << *(answer1 + x) << "'s : " << *(answer2 + x) << endl;
	}
	
	//delete the local pointers
	delete[] answer1;
	delete[] answer2;
	answer1 = nullptr;
	answer2 = nullptr;
}

//the purpose of this function is to have the user input the grades
void input(vector<float> & grade, vector <float> & var) {
	
	float insert; //the variable that must be inserted
	cout << "Input the grades, and insert -1 when finished: ";
	cin >> insert;
	while (insert >= 0) {
		//This part will check for occurances in the grade vector
		//THIS HAS TO GO FIRST FOR THE CHECK IN ORDER TO ADD THE FIRST VARIABLE TO THE VAR VECTOR
		//THIS WILL ONLY ADD ONE OCCURANCE THOUGH, IF IT DOESNT GO FIRST, THEN NO NUMBER WILL
		//BE ADDED BECAUSE THE INSERT==GRADE[X] WILL ALWAYS RETURN FALSE
		if (grade.size() < 1) {
			var.push_back(insert);
		}
		else {
			bool check = true;//will run the check for vector number 2
			for (int x = 0; x < grade.size(); x++) {
				if (insert == grade[x]) {
					check = false;
				}
			}
			if (check == true) {
				var.push_back(insert);
			}

		}
		//END OF VAR VECTOR PUSHES
		grade.push_back(insert);//pushes the variable into the vector
		cout << insert << " has been added, insert the next grade: ";
		cin >> insert;
	}
	cout << endl;
	
}