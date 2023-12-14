/*
 * Reference: I implemented Kahn’s algorithm for topological sorting using 
 *the implementation source provided in the lecture 
 *chapter.https://www.geeksforgeeks.org/topological-sorting-indegree- 
 *based-solution/ 
 *
 * INSTRUCTION:
 *     This is a C++ starting code for hw9_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw9_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw9_2.cpp
 * Abstract: This program displays the alphabetical order of characters 
 *for an alien language. The program takes input from the user in the form 
 *of the number of lines and a string. The program stores all of the 
 *strings in a vector for later comparison, and each character from each 
 *string is stored in a set. The set removes duplicates and sorts the 
 *characters in ascending order, which shows the number of vectors. The 
 *program then pushes all of the characters from the set to a vector to 
 *identify each character by index number.
 *The program then uses three loops to compare each string to find the 
 *topological order between each string, and stores these relationships in 
 *a 2D vector. The program uses the Kahn Algorithm to print the 
 *topological order.
 * ID: 7263
 * Name: Mohammad Haroon
 * Date: 04/14/2023
 */

#include <bits/stdc++.h>
using namespace std;

int main() {

    // set that store vertices 
  set<char> s;
    
  string nam; // take string input from keyboard 
  int num = 0; // store the length of the string 
    
  vector<char> v; // vector to store vertices to have access to index
    
  vector<string> v2; // vector to store all string input for later use
    
  int userV;
  cin >> userV; // take input from user to show number of line

  for (int i = 0; i < userV; i++) {
    cin >> nam; // string input 
    num = nam.length(); // find the length of string
    for (int j = 0; j < num; j++) {
      char c = nam[j]; // converting string to char
      s.insert(c); // inserting char valus to set
      c = ' ';
    }
    num = 0; 
    v2.push_back(nam); // pushing all string to vector for later comparisons 
    nam = " ";
  }

  // pushing all vertices to vector from set to use the index number
  for (auto i = s.begin(); i != s.end(); i++) {
    v.push_back(*i);
  }

 

  int size = v.size(); // finding the number of vertices

    //2D vector that store adjancey of matrix 
  vector<vector<int>> adj(size);

  int sizeV; // store the length of string for the loop 

    
  for (int i = 0; i < userV - 1; i++) {
    string name = v2[i]; // storing string from vector 
    int sizeName = name.length(); // getting the length  of the string 

    for (int j = i + 1; j < userV; j++) {
      string name2 = v2[j]; // storing string from vector 
      int sizeName2 = name2.length(); // find the length of string
        // finding min length string 
      if (sizeName > sizeName2) {
        sizeV = sizeName - 1;
      } else {
        sizeV = sizeName;
      }

      for (int k = 0; k < sizeV; k++) {
          // comparing the strings char to find topological order
        if (v2[i][k] != v2[j][k]) {


            // find the index of each char to add those numbers to adjancey list 
          vector<char>::iterator itr = find(v.begin(), v.end(), v2[i][k]);
          int n1 = distance(v.begin(), itr);
          vector<char>::iterator itr2 = find(v.begin(), v.end(), v2[j][k]);
          int n2 = distance(v.begin(), itr2);

          adj[n1].push_back(n2); // adding 2D vector 

          break;
        }
      }
    }
  }


    // using queue for kahn algorithm 

  vector<int> degree(size, 0);
  queue<int> q;

  for (int i = 0; i < size; i++) {
   
    for (int j : adj[i])
      degree[j]++;
  }
  for (int i = 0; i < size; i++) {

    if (degree[i] == 0) {
      q.push(i);
    }
  }

  vector<int> sortOrder;

  while (!q.empty()) {
    int num3 = q.front();
    sortOrder.push_back(num3);

    q.pop();

    for (int i : adj[num3]) {
      degree[i]--;

      if (degree[i] == 0) {
        q.push(i);
      }
    }
  }


    // printing the final result of topology sort order 
  for (int i = 0; i < sortOrder.size(); i++) {
    int num = sortOrder[i];

    if (i == sortOrder.size() - 1) {
      cout << v[num];
    } else {
      cout << v[num] << "->";
    }
  }
  cout << endl;

  return (0);
}
