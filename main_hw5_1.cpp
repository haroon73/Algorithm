/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw5_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw5_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw5_1.cpp
 * Abstract: This program uses recursion to reverse an integer number inputted by the user. It 
 *achieves this by using the modulo operator (%) to obtain the remainder and the division 
 *operator (/) to reach the base case, which is zero.
 * ID: 7263
 * Name: Mohammad Haroon 
 * Date: 02/26/2023
 */

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// function that work as recursive function to reverse a integer number
void rev(int num , int rNum =0 ){
    if(num == 0){ // base case
        cout << rNum ;
    }
    else{
        int d = num % 10; // get reminder 
         rNum = (rNum * 10) +d;
       
         
        rev(num /10 , rNum ); // recursive case or function self call 
    }
   
}

int main() {
    
    int num;
    cin >> num; // user input 
	
	rev(num); //  function call to reverse the number 
	cout << endl;

    return (0);
}




