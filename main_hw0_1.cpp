/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw0_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw0_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw0_1.cpp
 * Abstract: In this program we find the sum of two integer numbers , and we find the difference 
             of two interger numbers where we have if else condational statment to find the 
             differences.
 * ID: 7263
 * Name: Mohammad Haroon
 * Date: 01/24/2023
 */

#include <iostream>
using namespace std;

int main()
{
int num1 , num2 , sum , diff;
  
cin >> num1 >> num2;

 sum = (num1 + num2);

if(num1 > num2){
  diff = (num1 - num2);
}
  else if (num2 > num1){
   diff = (num2 - num1);
  }
  else{
    diff = 0;
  }
cout << "SUM:" << sum << endl;
cout << "DIFF:" << diff << endl;
  
    return 0;
}

