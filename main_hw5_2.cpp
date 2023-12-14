/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw5_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw5_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw5_2.cpp
 * Abstract: Write the main purpose of the program.
 * ID: Write your 4-digit ID
 * Name: Write your name
 * Date: MM/DD/YYYY
 */

/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw5_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw5_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw5_2.cpp
 * Abstract: This program works as a TSP algorithm to print the starting path, all the middle 
 *paths, and the starting path again with the lowest cost in terms of time. The program uses an 
 *unordered_map to store the vertices, and all edge information is stored in a 2-D vector.
 * ID: 7263
 * Name: Mohammad Haroon
 * Date: 03/02/2023
 */

#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {

    // unorder_map to store vertices 
	unordered_map<string, int> m;
	unordered_map<int, string> m2;

	string name; // take input from keyboard for vertice or city nmaes

	int vertice; // take number of vertices
	cin >> vertice;

    // 2-D vector to store edges information 
	vector<vector<int>> arr(vertice, vector<int>(vertice));

    // take vertices input from key board storing in map
	for (int i = 0; i < vertice; i++) {
		cin >> name;
		m.insert({name, i});
		m2.insert({i, name});
	}


      // intilizing 2-D vector all indexes with -1
	for (int i = 0; i < vertice; i++) {
		for (int j = 0; j < vertice; j++) {
			arr[i][j] = -1;
		}
	}

    
	string city, city2;
	int num, numEdge;

    // take number of edges 
	cin >> numEdge;

    // storing edges information from one path to anther in 2-D vector
	for (int i = 0; i < numEdge; i++) {
		cin >> city >> city2 >> num;
		for (auto &k : m) {
			for (auto &l : m2) {
				if (k.first == city && l.second == city2) {
					arr[k.second][l.first] = num;
				}
			}
		}
	}


    // replacing all -1 value with higher number to show infinte edges 
	for (int i = 0; i < vertice; i++) {
		for (int j = 0; j < vertice; j++) {
			if (arr[i][j] == -1) {
				arr[i][j] = 100000;
			}
		}
	}


    // vector that store  permutation number 
	vector<int> a;


    //taking  permutation numbers
	for (int i = 1; i < vertice; i++) {
		a.push_back(i);
	}
   // sorting vector in ascd order
	sort(a.begin(), a.end());

    // variable that store factorial number
	long long factorial = 1;
     // 
	for (int i = 1; i < vertice; ++i) {
		factorial *= i;
	}

    // 2-D vector that store all permutation numbers 
	vector<vector<int>> vec(factorial, vector<int>(vertice + 1));

	for (int i = 0; i < factorial; i++) {
		next_permutation(a.begin(), a.end()); // function call to get permutation number

		for (int k = 0; k < vertice - 1; k++)
            // adding all permutation number to 2-D vector
			vec[i][k] = a[k];
	}

    // adding zero to column one row zero which shows starting path
	for (int i = 0; i < factorial; i++) {
		vec[i].insert(vec[i].begin(), 0);
	}

    // add zero to vector last column to show end again in starting path
	for (int i = 0; i < factorial; i++) {
		vec[i].push_back(0);
	}

	long long sum = 0;
	long long large = 100000;
	vector<int> indexV, findV;
    // finding the cost of edges and find the start path to end path 
	for (int i = 0; i < factorial; i++) {
		for (int j = 0; j < vertice; j++) {
			int index1 = vec[i][j];
			int index2 = vec[i][j + 1];

			sum += arr[index1][index2];
			indexV.push_back(vec[i][j]);
		}

		if (large > sum) {
			large = sum;
			findV = indexV;
		}
		indexV.clear();

		sum = 0;
	}


    // printing the final result 
	if (large < 100000) {
		cout << "Path:";
		for (int i = 0; i < findV.size() + 1; i++) {
			for (auto &p : m2) {
				if (p.first == findV[i]) {
					if (i == findV.size()) {
						cout << p.second;
					} else {
						cout << p.second << "->";
					}
				}
			}
		}
		cout << endl;
		cout << "Cost:" << large << endl;
	} else {
		cout << "Path:" << endl;
		cout << "Cost:" << -1;
	}
	cout << endl;

	return (0);
}
