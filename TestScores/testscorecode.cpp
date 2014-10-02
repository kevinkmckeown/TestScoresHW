#include<iostream>
using namespace std;

// Function declarations
int findLargest(int[], int);
float findAverage(int[], int);

int main(){
	int size;
	int input;
	int maxScore;
	int largestScore;
	float averageScore;

	// Ask the user for the maximum possible score and number of tests being entered
	cout << "Enter maximum score for the test: ";
	cin >> maxScore;
	cout << "Enter the number of test scores you will be entering: ";
	cin >> size;	
	cout << endl << endl;

	// Dynamically allocate an array to the size of the amount of tests the user entered
	int* scores = new int[size];

	// Ask the user for the score for each test and update the scores array
	for (int i = 0; i < size; i++){
		cout << "Enter score for Test " << i + 1 << " (0-" << maxScore << "): ";
		cin >> input;
		if (input >= 0 && input <= maxScore){	// Only allow scores within the range 0-maxScore
			*(scores+i) = input;
			cout << endl;
		}
		else{
			cout <<  "Score out of bounds!" << endl << "Try again!" << endl << endl;
			i--;
		}

	}

	// Call calculating functions. Each is passed the array and the variable indicating its size
	largestScore = findLargest(scores, size);
	averageScore = findAverage(scores, size);

	// Display the largest and average test score.
	cout << endl << "Largest test score: " << largestScore << endl;
	cout << "Average test score: " << averageScore << endl;
	
	delete scores;
}

// Find the largest test score entered by the user and return it
int findLargest(int ar[], int size){

	// Set largest to first score in ar and cycle through ar to compare largest to each score
	int largest = *ar;
	for (int i = 0; i < size; i++){
		if (*(ar + i) > largest){
			largest = *(ar + i);
		}
	}
	return largest;
}

// Find the average test score entered by the user and return it.
// Give user the option to exlude the lowest test scores from the calculation.
float findAverage(int ar[], int size){
	char input;
	int lowest;
	int newSize = 0;
	int total = 0;
	float avg;

	// Ask the user if it wants to exclude the lowest test score setting their input to a char variable
	cout << "Calculating average test score..." << endl;
	cout << "Do you want to exclude the lowest test score in the calculation? (y or n):";
	
	// Loop until y, Y, n, or N are entered. use toupper to capitalize their input for comparison
	do{
		cin >> input;
		input = toupper(input);
	} while (input != 'Y' && input != 'N');

	// If the user entered Y, find the lowest test score
	if (input == 'Y'){
		lowest = *ar;
		for (int i = 0; i < size; i++){
			if (*(ar + i) < lowest){
				lowest = *(ar + i);
			}
		}
		// Add any test score that isn't equal to lowest to the total. Increment newSize for each addition
		for (int i = 0; i < size; i++){
			if (*(ar + i) != lowest){
				total += *(ar + i);
				newSize++;
			}
		}

		// Force float division to find the average score.
		avg = (float)total / newSize;
	}
	// If the user entered N, calculate the total score tally and divide it by the original size variable.
	else if (input == 'N'){
		for (int i = 0; i < size; i++){
			total += *(ar + i);
		}
		avg = (float)total / size;
	}
	return avg;
}