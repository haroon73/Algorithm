/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw1_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw1_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */
// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw1_1.cpp
 * Abstract: This program finds no intersecting numbers in two sets of vectors. There are seven vectors used in this program. For sorting of vectors builds function has been used. The program takes input from the keyboard and then the sort function sorts the two vectors in asc order. The program then uses the loop to find duplicates in both vectors and stores the result in two new vectors. The result of two new vectors inserts it into a new vector as a merge. The final check for none intersects number takes place and the result is printed. 
 * ID: 7263
 * Name: Mohammad Haroon
 * Date: 02/01/2023
 */

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int count = 0;

	int num1, num2, num3, num4;

  vector<int> v1;
  vector<int> v2;
	vector<int> v4;
	vector<int> v5;
	vector<int> v6;
	vector<int> v7;
	vector<int> v8;

	cin >> num1; // get input from keyborad for number of elements
  
	
  // enter the element of first v1
	for (int i = 0; i < num1; i++) {
		cin >> num3;
		v1.push_back(num3);
	}

    cin >> num2;
   // enetr element of v2 
	for (int i = 0; i < num2; i++) {
		cin >> num4;
		v2.push_back(num4);
	}
  // sorting both vectors by using build in function
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());


  // checking for none duplicates elements in v1 and store it in new vector 
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] != v1[i + 1]) {
			v4.push_back(v1[i]);
		}
	}
	for (int i = 0; i < v2.size(); i++) {
		if (v2[i] != v2[i + 1]) {
			v5.push_back(v2[i]);
		}
	}


  // merging v4 and v5 vectors to new vector v6 using build in function 
	v6.insert(v6.begin(), v4.begin(), v4.end());
	v6.insert(v6.end(), v5.begin(), v5.end());

  // sorting the vector
	sort(v6.begin(), v6.end());

  // checking for none duplicates elements and store it in new vector
	for (int i = 0; i < v6.size(); i++) {
		if (v6[i] == v6[i + 1]) {
			i++;
		} else {
			v7.push_back(v6[i]);
		}
	}

  // sorting vector in dec order 
	sort(v7.begin(), v7.end(), greater<int>());

  // printing the result
	if (v7.empty()) {
		cout << "Answer:NONE" << endl;
	} else {
    cout <<"Answer:";
		for (int i = 0 ; i < v7.size() ; i++) {
			cout << v7[i] ;
      if(i == v7.size() -1 ){
        cout << endl;
      }
      else{
        cout << " ";
      }
      
		}
	}

	return 0;
}