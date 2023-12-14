/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw4_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw4_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw4_1.cpp
 * Abstract: This program find consecutive numbers if it find that number it will just print the first consecutive number with dash and the last consecutive number and it will remove all consecutive numbers in middle of first and last. 
 * ID:7263
 * Name:Mohammad Haroon
 * Date:02/19/2023
 */

#include <bits/stdc++.h>
#include <cstring>
#include <vector>
using namespace std;

int main() {
	vector<int> v1;

	int num1, num2;

	cin >> num1; // take number of value from keyboard

	for (int i = 0; i < num1; i++) {
		cin >> num2; // take input
		v1.push_back(num2); // pushing the value to vector
	}

	sort(v1.begin(), v1.end()); // sortting vector asc order

	int count = 0;
	int i = 0;
	while (i < v1.size()) {
        // checking for not consecutive numbers
		if (v1[i] + 1 != v1[i + 1]) {
			if (i != v1.size() - 1) {
				cout << v1[i] << " ";

			} else {
				cout << v1[i];
			}
			count = 0;
		} else { // finding the consecutive numbers
			count++; // incrument
			if (count == 1) {
				cout << v1[i] << "-";
			}
			
		}
		i++;
	}
	cout << endl;
	return (0);
}
