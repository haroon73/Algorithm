/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw12_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw12_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw12_1.cpp
 * Abstract: This program is designed to solve the Coin Row problem 
 *efficiently. It incorporates a user input mechanism to determine 
 *the number of coins involved. Based on this input, the program 
 *intelligently selects the most valuable coins and presents the 
 *user with a comprehensive breakdown of the coins used to achieve 
 *highest possible value. To achieve this, the program leverages the 
 *backtracking technique, a well-known algorithmic approach for 
 *problem-solving. By employing two regular arrays and a vector data 
 *structure, the program effectively stores and organizes the 
 *necessary index numbers. The vector serves as a repository for all 
 *the index numbers that contribute to constructing the optimal 
 *value from the available coins. By combining these techniques and 
 *data structures, the program provides a robust and systematic 
 *solution to the Coin Row problem, showcasing its ability to 
 *efficiently determine the best coin selection strategy for 
 *maximizing value.
 * ID: 7263
 * Name: Mohammad Haroon
 * Date: 05/08/2023
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // take size and number of coin will print
  int size, key;
  cin >> size;

  int arr[size + 1]; // declaration of an array with size + 1
  arr[0] = 0; // adding zero to index 0 becuase 0 is always  zero

    // take user input for the number of coins
  for (int i = 1; i <= size; i++) {
    cin >> key;
    arr[i] = key;
  }

  int num = 0; // storing add coins 
  int num2 = 0;

  int arr2[size + 1]; // declaration of an array that store max add cois
  arr2[0] = arr[0]; // the zero index 0
  arr2[1] = arr[1]; // the first index always have the first index value

  vector<int> v; // vector that store backtrace values

    // operation that find the best values of the coins when pick up 

  for (int i = 2; i <= size; i++) {

    num = (arr2[i - 2] + arr[i]);
    num2 = arr2[i - 1];

    if (num2 > num) {
      arr2[i] = num2;
    } else {
      arr2[i] = num;
    }
  }


    // backtracing to find the path of bect coins values 
  for (int i = size; i >= 0; i -= 2) {

    if (i != 0) {
      if (arr2[i - 1] != arr2[i]) {
        v.push_back(i);
      }
    }
    if (i == 0) {
      if (arr2[i] != arr2[i + 1] && arr2[i + 1] == arr2[i + 2]) {
        v.push_back(i + 1);
      }
    }
  }

    // sorting the vector in acceding order
  sort(v.begin(), v.end());
 // print backtrace resut
  cout << "Best set:";
  for (int i = 0; i < v.size(); i++) {
    if (i == v.size() - 1) {
      cout << v[i];
    } else {
      cout << v[i] << " ";
    }
  }

    // find the best value from an array 
  cout << endl;
  int large = arr[0];
  for (int i = 0; i <= size; i++) {
    if (arr2[i] > large) {
      large = arr2[i];
    }
  }

  cout << "Max value:" << large << endl;

  return 0;
}