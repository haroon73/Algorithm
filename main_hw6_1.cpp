/*

 * Reference: how to implment vector of vector and sorting got from Dr.Byun code
 *in BFS program.
 * INSTRUCTION:
 *     This is a C++ starting code for hw6_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw6_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw6_1.cpp
 * This program is designed to display an array of marks in DFS. The user is
 *prompted to input the number of vertices and edges through a for loop, and
 *subsequently inputs the start and end edges. All edges are pushed to a vector
 *of vectors and sorted by ascending order in a list of edges. The mark array is
 *initialized with zero to indicate that no vertices have been visited yet. The
 *program then calls a recursive function using the run-time stack to visit each
 *vertex. After visiting each vertex, the mark array updates the visited vertex
 *with a value of one. The program also handles disconnected or multiple graphs.
 *It utilizes a global count variable to keep track of each vertex and a global
 *map to store vertices and the number of times they are visited. ID: 7263 Name:
 *Mohammad Haroon Date: 03/08/2023
 */

#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
using namespace std;

// gl0bal vvariable the count at which nummber vertices visited
int cnt = 0;

// global map that store vertices as key and number of visit as value
map<int, int> m;

//DFS function that work as run-time stack 
void dfs(int v, vector<vector<int>> &vec, vector<int> &markArray) {
	markArray[v] = 1; // marking each vertex after visiting

	cnt++;				// count the number of visit of each vertices
	m.insert({v, cnt}); // inserting key and value to the map for final print

	for (auto num : vec[v]) { // for each loop

		if (markArray[num] == 0) { // checking the vertice visited or not

			dfs(num, vec, markArray); // recurisive call of function work as
									  // run-time stack
		}
	}
}

int main() {

    // vector of vector storing graph
	vector<vector<int>> vec;
    // input variable 
	int numV, numE, startE, endE;

	cin >> numV; // taking number of vertices

	vec.resize(numV); 

	cin >> numE; // taking number of edges

	for (int i = 0; i < numE; i++) {
		cin >> startE >> endE;
		vec[startE].push_back(endE); // pushing to vector 
	}
     //sortng the graph 
	for (int i = 0; i < vec.size(); i++) {
		sort(vec[i].begin(), vec[i].end());
	}

    // markarray intilize with zero 
	vector<int> markArray = {0};


    //handling if graph is disconnected or have more then one graphs
	for (int i = 0; i < vec.size(); i++) {
		if (markArray[i] == 0) {
            
			dfs(i, vec, markArray);
		}
	}
   // printing the final result 
	for (auto &k : m) {
		cout << "Mark[" << k.first << "]:" << k.second << endl;
	}

	return (0);
}
