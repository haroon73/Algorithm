/*
 * Reference: how to implment vector of vector and sorting got from Dr.Byun code
 *in BFS *program.
 * INSTRUCTION:
 *     This is a C++ starting code for hw6_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw6_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw6_2.cpp
 * Abstract: This program aims to connect several connected components of a graph with a 
 *minimum number of edges to create a single connected component. The graph is stored using a 
 *vector of vectors, and the program utilizes DFS to obtain the desired result. User input is 
 *required for the number of vertices and edges, as well as the starting and ending edges. The 
 *graph is sorted for better performance. The program uses the run-time stack to implement 
 *DFS. 
 * ID: 7263
 * Name: Mohammad Haroon
 * Date: 03/08/2023
 */

#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
using namespace std;


// DFS function that using recusiion or run-time stack 
void dfs(int v, vector<vector<int>> &vec, vector<int> &markArray) {
	markArray[v] = 1; // marking visited vertices with one


    // checking for unvisited vertices
	for (auto num : vec[v]) {
		if (markArray[num] == 0) {
			dfs(num, vec, markArray);
		}
	}
}

int main() {
	vector<vector<int>> vec;

	int numV, numE, startE, endE;

	cin >> numV;

	vec.resize(numV);

	cin >> numE;

	for (int i = 0; i < numE; i++) {
		cin >> startE >> endE;
		vec[startE].push_back(endE);
	}

	vector<int> markArray = {0};
	vector<int> v;
	for (int i = 0; i < vec.size(); i++) {
		if (markArray[i] == 0) {
			v.push_back(i); // pushing the min number of edges to vector 
			dfs(i, vec, markArray);
		}
	}



    // printing the final result 
	if (v.size() > 1) {
		for (int i = 0; i < v.size() - 1; i++) {
			cout << "Edge: " << v[i] << "-" << v[i + 1] << endl;
		}
	} else {
		cout << "No new edge:" << endl;
	}

	return (0);
}
