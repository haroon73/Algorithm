/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw3_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw3_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw3_2.cpp
 * Abstract: This program is designed to determine the maximum number of events
 * that occurred within a 24-hour time period. To do this, the program prompts
 * the user for the number of events that took place and the starting and ending
 * times for each event. The program then utilizes a nested for loop structure:
 * the outer loop iterates through the number of events entered by the user,
 * while the inner loop runs from the start hour of the event until the end hour
 * of the event. As the loops run, the program updates an array index to keep
 * track of how many events are occurring at each hour. Finally, the program
 * identifies the maximum number of events recorded in the array to determine
 * the busiest hour. 
 *ID:7263 
 *Name: Mohammad Haroon 
 *Date: 02/14/2023
 */
#include <iostream>

using namespace std;
const int SIZE = 25;
int main() {
	int num1, num2, num3;

	// the array with size 24 an dintilize with zero
	int arr[SIZE] = {0};

	// take input from keyboard for the number of event
	cin >> num1;

	for (int i = 0; i < num1; i++) { // outter loop run on number of events

		cin >> num2 >>
			num3; // input from keyboard for start and end of the events
		for (int j = num2; j <= num3;
			 j++) { // inner loop run on events start and end hours

			arr[j] += 1; // updating the array index
		}
	}

	int max = arr[0]; // variable to store the max value from array
	for (int i = 0; i < SIZE; i++) {
		if (arr[i] > max) { // finding the max value in array
			max = arr[i];
		}
	}
	// printig the final result
	cout << "Max events: " << max << endl;

	return 0;
}
