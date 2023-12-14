/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw0_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw0_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw0_2.cpp
 * Abstract:This program has array of size 5 where it can find smallest and largest integer numbers , and it can find median number from odd sets of number. 
 * ID: 7263
 * Name: Mohammad Haroon 
 * Date: 01/24/2023
 */

#include <iostream>
using namespace std;

int main()
{
    int arraySize = 5; // varaiable to use for array and loop size.
    int arr[arraySize]; // integer array sizeof 5
  for(int i = 0 ; i < arraySize ; i++){
    cin >> arr[i]; // getting input from keyboard
  }

  int max = arr[0]; // integer varaible to find larger element of an array 
  int min = arr[0]; // integer varaible to find smaller element of an array.

  for(int i = 0 ; i < arraySize ; i++){
    if(arr[i] < min){ // checking if there is small element in an array 
      min = arr[i]; // assign small number to min varaible 
    }
  else if (arr[i] > max){ // checking for larger elemengt in an array 
      max = arr[i]; // assign that element to max varaible
    }
  }
  // sortting an array in dec
  for(int i = 0 ; i < arraySize ; i++){
    for(int j = i + 1 ; j < arraySize ; j++){
      if(arr[i] > arr[j]){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  // printing all the results 
int med = arr[2];
cout << "MIN:" << min << endl;
cout << "MAX:" << max << endl;
cout << "MEDIAN:" << med << endl;


  

    return 0;
}

