/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw7_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw7_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw7_1.cpp
 * Abstract: This program uses the technique of divide and conquer to find the
 *smallest element in a vector. It achieves this by using a recursive function
 *to search for the smallest element. The program prompts the user to input the
 *number of elements in the vector, as well as the elements themselves, which
 *are then stored in the vector. The program then calls the "min_div_N_conq"
 *function to find the smallest number in the vector. 
 *ID: 7263 
 *Name: Mohammad Haroon 
 *Date: 03/22/2023
 */

#include <iostream>
#include <vector>
using namespace std;

// Function to find smallest element in the vector
int min_div_N_conq(vector<int> vec, int start, int end) {
	int min1, min2;
	if (start == end) // if first index and last index equal return the first
					  // index as smallest element
	{
		return vec[start];
	} else {
		// recursive function call to find smallest elemnt
		min1 = min_div_N_conq(vec, start, (start + end) / 2);
		min2 = min_div_N_conq(vec, (start + end) / 2 + 1, end);
	}
	if (min1 > min2) { // comparing two variables to find smallest element
		return min2;
	} else {
		return min1;
	}
}

int main() {
	int num;
	cin >> num; // user input
	vector<int> vec;
	for (int i = 0; i < num; i++) { // user input for all the elements
		int ele;
		cin >> ele;
		vec.push_back(ele);
	}
	int lastIndex = vec.size() - 1; // find the last index of vector
	int min = min_div_N_conq(vec, 0, lastIndex); // function call
	cout << min << endl;						 // print the result
	return 0;
}
