/*
 * Reference: I implemented Kahn’s algorithm for topological sorting 
 *using the implementation source provided in the lecture 
 *chapter.https://www.geeksforgeeks.org/topological-sorting-indegree- 
 *based-solution

 * INSTRUCTION:
 *     This is a C++ starting code for hw9_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw9_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
/ 


 * Title: main_hw9_1.cpp
 * Abstract: This program uses the Kahn Algorithm for topological 
 *sorting to find the degree of incoming vertices and then determine 
 *the topological order. The program takes two inputs: the first 
 *input shows the number of vertices in the graph, and the second 
 *input shows the number of edges in the graph. The program uses a 
 *2D array to store all incoming vertices and find the number of 
 *degrees for each vertex. The program stores the adjacency list in 
 *a 2D vector. The program then uses a queue to find the topological 
 *order in the graph.
 * ID: 7263
 * Name: Mohammad Haroon
 * Date: 04/12/2023
 */

#include <bits/stdc++.h>
using namespace std;


int main() {
	

	int num; // take input of number vertex
	cin >> num;

    // 2D array store incoming degree of the vertex
    int v[num][num];
  
   // initializing 2D array all indexs with zero
   	for(int i = 0 ;i < num ; i++){
	    for(int j = 0 ; j < num ; j++){
	       v[i][j]=0;
	     
	    }
	   
		}
    
	int numEdges; // taking number of edges
	cin >> numEdges;
	
	// 2D vector to store the list of adjancey 
      vector<vector<int>> adj(num);
    
	for(int i = 0 ; i < numEdges ; i++ ){
	    int e1 , e2; // taking number of vertex and edge 
	    cin >> e1 >> e2;
	    v[e1][e2] =1; // marking income vertex with 1 in 2D array
	    adj[e1].push_back(e2); // puting value in 2D vector
	}
	
	
   // finding income degree of teh graph and printing the result 
	int sum =0;
	for(int i = 0 ;i < num ; i++){
	    for(int j = 0 ; j < num ; j++){
	        sum += v[j][i];
	    }
	    cout << "In-degree[" << i << "]:" << sum << endl; 
	    sum =0;
	}


// using Kahn Algorithm topological sort to find the order in the graph. 

queue<int>q;
vector<int>in_degree(num , 0);
vector<int>sortOrder;

  for (int i = 0; i < num; i++) {
     
       
        for (int j : adj[i])
            in_degree[j]++;
      
    }
   


for(int i = 0 ; i < in_degree.size() ; i++){
    if(in_degree[i] == 0){
        q.push(i);
    }
}


  
    
    
    while(!q.empty()){
   
   int num3 = q.front();
   sortOrder.push_back(num3);
   q.pop();
   
   
        for (int i : adj[num3]){
               in_degree[i]--;

            if (in_degree[i] == 0){
                q.push(i);
            }
 
    
    }
   
   
        
    }

    // printing the final result of the order. 
    cout << "Order:";
  for(int i = 0 ; i < sortOrder.size() ; i++){
      if(i == sortOrder.size() -1){
          cout << sortOrder[i];
      }
      else{
          cout << sortOrder[i] << "->";
      }
  }
cout << endl;

    return (0);
}




