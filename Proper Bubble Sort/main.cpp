#include <iostream>
#include <vector>
using namespace std;
int main() {
	const int n = 6;
	int grade[n] = { 6,5,4,3,2,1 };
	//this part of the function will run a bubble sort
	for (int x = 0; x < n - 1; x++) {
		for (int y = x + 1; y< n; y++) {
			if (grade[x]>grade[y]) {
				int temp = grade[x];
				grade[x] = grade[y];
				grade[y] = temp;
			}
		}
	}

	for (int x = 0; x < n; x++) {
		cout << grade[x] << " ";
	}
	
	return 0;
}

