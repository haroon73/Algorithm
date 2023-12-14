/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw7_3.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw7_3.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw7_3.cpp
 * Abstract: This document presents two different approaches to rearrange a
 *vector such that all negative numbers are placed before all positive numbers.
 *The first approach in this program uses two indices, i and j. The index i
 *points to the first element of the vector, while the index j points to the
 *last element of the vector. When index i encounters a positive number, it is
 *swapped with the negative number pointed to by index j. The second approach in
 *this program starts with the indices i and j positioned at the end of the
 *array. The index j scans each number of the vector from right to left, while
 *index i holds the position of the last negative number encountered while
 *moving from right to left. If index j points to a positive number during the
 *scan, the values of indices i and j are swapped. This approach ensures that
 *all negative numbers are placed before positive numbers in the resulting
 *vector. 
 *ID: 7263 
 *Name:Mohammad Haroon
 * Date: 03/22/2023
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	vector<int> v2;

	int num;
	cin >> num; // user input
	for (int i = 0; i < num; i++) {
		int ele;
		cin >> ele;		  // user input
		v.push_back(ele); // push all elements to vectors
		v2.push_back(ele);
	}

	int size = v.size(); //  getting the size o fthe vector

	int j = v.size() - 1; // variable the point to the last index of vector
	int i = 0;			  // variable pointing to first index of vector
	while (i != j) { // first approch 
		if (v[i] < 0) {
			i++;
		} else if (v[j] > 0) {
			j--;

		} else if (v[i] > 0 || v[j] < 0) {
			int temp = v[i];
			v[i] = v[j];
			v[j] = temp;
			j--;
		}
	}

	int k = size - 1;
	int l = size - 1;

    // printing the first approch 
	for (int i = 0; i < v.size(); i++) {
		if (i == v.size() - 1) {
			cout << v[i];
		} else {
			cout << v[i] << " ";
		}
	}
	cout << endl;

	while (k >= 0 && l >= 0) { //second approch 
		if (v2[k] > 0 && v2[l] > 0 && k == l) {
			k--;
			l--;

		}

		else if (v2[k] > 0) {
			k--;

		} else if (v2[l] < 0) {
			l--;

		} else if (v2[l] > 0) {
			int temp = v2[l];
			v2[l] = v2[k];
			v2[k] = temp;
			l--;
		}
	}
   // printing the result of second approch 
	for (int i = 0; i < v2.size(); i++) {
		if (i == v2.size() - 1) {
			cout << v2[i];
		} else {
			cout << v2[i] << " ";
		}
	}
	cout << endl;

	return 0;
}
