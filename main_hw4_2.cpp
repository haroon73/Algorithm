/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw4_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw4_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw4_2.cpp
 * Abstract: This program find the max numbers of apples and shows combinations of which boxes gave us that max number. The program take input from user which is the number of boxes. The program convert that number to the number of combinations (2 to power of input). The program removes all consecutive 1 from vector because it will not give us our combination. 
 * ID: 7263
 * Name: Mohammad Haroon
 * Date: 02/22/2023
 */

#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int> check(int dec, int index) {
	vector<int> v, v2;
	// declare to integer vectors

	while (dec > 0) {		  // converting decimal to binary number
		v.push_back(dec % 2); // pushing each bit to vector
		dec /= 2;
	}

	int num = v.size(); // take the size of the vector.

	// checking if vector has correct  number of bits if not push those zero
	// bits to the vector
	if (num < index) {
		for (int i = num; i < index; i++) {
			v.push_back(0);
		}
	}

	// copying elements from v vector to v2 vector in reverse order.
	for (int i = v.size() - 1; i >= 0; i--) {
		v2.push_back(v[i]);
	}
	return v2; // return vector
}

int main() {

    
	int sumApples = 0; // hold the sum of apples
	vector<int> v, v2, v3, v4;
	int numBoxes, box;
	cin >> numBoxes; // take input from user number of boxes
	for (int i = 0; i < numBoxes; i++) {
		cin >> box; // take number of apples for each box
		v2.push_back(box); // pushing boxes to vector
	}
    // checking if number of boxes greater then 2 
	if (numBoxes > 2) {
		int num = pow(2, numBoxes); // converting to number of combinations 
		for (int i = 0; i < num; i++) {
            // converting to binary numbers
			v = check(i, numBoxes);
			
			for (int j = 0; j < numBoxes; j++) {
                // removing consecutive 1 from vector
				if (v[j] == 1 && v[j + 1] == 1) {
					v.clear(); // clearing vector from 1
				}
			}
			for (int k = 0; k < v.size(); k++) {
                // checking if combination == 1 then find max number of apples
				if (v[k] == 1) {
					sumApples += v2[k]; // storing max number of apples
				}
			}
			v3.push_back(sumApples); // pushing max values to vector

			sumApples = 0; // resting sum variable of max apple

			v.clear(); // clearing vector 
		}

		int max = 0; // storing max number of apple
		int index; // storing index number where max number apple found

		for (int i = 0; i < v3.size(); i++) {
            // checking in vector max number of apples
			if (v3[i] > max) {
				max = v3[i];
				index = i;
			}
		}
// printing final result 
		v4 = check(index, numBoxes);
        cout << "Boxes:";
		for (int i = 0; i < v4.size(); i++) {
			if (v4[i] == 1) {
				if (i != v4.size() - 1) {
					cout << i << " ";

				} else {
					cout << i;
				}
			}
		}

		cout << endl;
		cout << "Max Apples:" << max << endl;

        // if number of boxes 2 then printing the result 
	} else {
		if (v2[0] > v2[1]) {
			cout << "Boxes:";
			cout << 0;
			cout << endl;
			cout << "Max Apples:" << v2[0] << endl;
		} else {
			cout << "Boxes:";
			cout << 1;
			cout << endl;
			cout << "Max Apples:" << v2[1] << endl;
		}
	}

	return (0);
}
