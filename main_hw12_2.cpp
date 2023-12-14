/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw12_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw12_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw12_2.cpp
 * Abstract: The program utilizes the Floyd algorithm to compute and 
 *display all-pairs shortest paths. Its implementation involves the 
 *use of two 2D arrays. Upon receiving user input, the program 
 *assigns the values from the original 2D array to a new array. It 
 *then scans for any occurrences of -1 within the array and replaces 
 *them with a significantly large integer value, often referred to as 
 *MAX, to represent an infinite distance. Subsequently, the program 
 *applies the Floyd algorithm to determine the shortest path between 
 *all pairs of vertices in the graph represented by the array. This 
 *algorithm efficiently calculates the distances by considering intermediate 
 *vertices and updating the shortest path values. Upon completion of the 
 *algorithm, the program reverts any occurrences of the large integer value 
 *back to -1, effectively restoring the original representation of infinite 
 *distances. By leveraging the Floyd algorithm and employing appropriate 
 *data structures, the program offers an effective solution for computing 
 *and displaying all-pairs shortest paths while efficiently handling missing 
 *or infinite distance values within the graph.
 * ID: 7263
 * Name: Mohammad Haroon
 * Date: 08/05/2023
 */
#include <iostream>
#include <algorithm>

using namespace std;



int main(){
    
    int size;
    cin >>size;
    int arr[size][size]; // declaration of 2D array
    
    int MAX = 10000000; // huge positive vlaue that replace -i in 2D array

    // taking user input to store in 2D array
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ;j < size ; j++){
            int v;
            cin >> v;
            arr[i][j] = v;
        }
    }


    // 2D array that will store value from orginal 2D array
    int arr2[size][size];
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ;j < size ; j++){
          
           arr2[i][j]=arr[i][j];
        }
       
    }

    // checking for -1 to be replace with MAX integer value
      for(int i = 0 ; i < size ; i++){
        for(int j = 0 ;j < size ; j++){
          if(arr2[i][j] == -1){
              arr2[i][j] =MAX;
          }
        }
       
    }
    

    // using Floyd algorithm to find shortest path 
    for(int k = 0 ; k < size ; k++){
        for(int i = 0 ; i < size ; i++){
            for(int j = 0 ; j < size ; j++){
                arr2[i][j] = min(arr2[i][j] ,( arr2[i][k] + arr2[k][j]));
            }
        }
    }


    // replace back MAX integer value with -1
     for(int i = 0 ; i < size ; i++){
        for(int j = 0 ;j < size ; j++){
          if(arr2[i][j] == MAX){
              arr2[i][j] =-1;
          }
        }
       
    }
    
     //Print final result 
     for(int i = 0 ; i < size ; i++){
        for(int j = 0 ;j < size ; j++){
            if(j == size -1){
                cout << arr2[i][j];
            }
            else{
                cout << arr2[i][j] << " ";
            }
           
        }
        cout << endl;
    }
    

    return 0;
}