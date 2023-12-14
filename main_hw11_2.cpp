/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw11_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw11_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw11_2.cpp
 * Abstract:This program simulates linear probing. It uses two 
 *vector pairs where the original elements are stored in one 
 *vector pair. When the user inputs an element for insertion, 
 *the program checks if the load factor is higher than 0.5. If 
 *yes, the program starts rehashing, where all the old elements 
 *are stored in a temporary vector pair. The original vector 
 *pair is then resized with a new prime number, and the program 
 *starts rehashing from the temporary vector pair to the 
 *original vector pair.The program checks the status of each 
 *element by entering the index number, which shows "Empty" when 
 *the index has a value of 0, "Active" when the index has a 
 *value of 1, and "Deleted" when the index has a value of -1. 
 *The program also searches for a specific value and can delete 
 *a specific element from the table. The program also shows the 
 *table size.
 * ID: 7263
 * Name: Mohammad Haroon
 * Date: 05/03/2023
 */
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// This function checking if the integer is prime or not
bool isPrime(int n) {
  if (n < 2) {
    return false;
  }
  for (int i = 2; i < n / 2; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

// this function return next prime
int findPrime(int n) {
  int prime = n + 1;
  while (!isPrime(prime)) {
    prime++;
  }
  return prime;
}

int main() {

    // to store the size of the table
  int arraySize;

  cin >> arraySize;

    // original vector pair to store both key and stat
  vector<pair<int, int>> arr(arraySize, make_pair(0, 0));

  int numLoop; // take input from user choice 

  cin >> numLoop;

  // count key when add to table and decrement when delete key from table. Wher this variable use to find load factor value.
  int count = 0; 
  while (numLoop > 0) {

      // for user input 
    string choice;

    cin >> choice;

      // if user choose to insert key to table
    if (choice == "insert") {
       // count++;
      int insertValue;

       cin >> insertValue;
       int indexNum = insertValue % arraySize;
           // if index stat is 0 or -1 add the key to that index
        if (arr[indexNum].second == 0 || arr[indexNum].second == -1) {

             if(arr[indexNum].second != -1){
                count++;
            }
          arr[indexNum] = make_pair(insertValue, 1);
   
        }

        else { // if index stat is 1 find empty space or reuse delete space

          int newIndex2 = indexNum;
          while (arr[newIndex2].second != 0) {

              newIndex2++; 

              // loop circular 
            if (newIndex2 == arraySize) {
              newIndex2 = 0;
            }
              // break the loop if index is -1
            if (arr[newIndex2].second == -1 ) {
              break;
            }
          }
            if(arr[newIndex2].second != -1){
                count++;
            }
           // insert key
          arr[newIndex2] = make_pair(insertValue, 1);
            
    
        }

       
      

        // find the laod factor value
      double loadFactor = count / (arraySize + 0.0);

        // if laoder factor is higher
      if (loadFactor >= 0.5) {

          // declaring temporary vector pair to store all keys from orignal table
        vector<pair<int, int>> temp(arraySize);

        
          // assigning all keys from orignal to temp
        temp.assign(arr.begin(), arr.end());
       
          // doubles the table size
        int doubleNum = arraySize * 2;

          // function call to find next prime number
        arraySize = findPrime(doubleNum);

          // resizing the table 
        arr.resize(arraySize);

          // inti both key and stat to zero 
        for (int i = 0; i < arraySize; i++) {
          arr[i] = make_pair(0, 0);
        }

        int n, n2, indexRe;

          // rehashing from temp to original vector pair
        for (int i = 0; i < temp.size(); i++) {

          if (temp[i].second != 0) {

            n = temp[i].first;
            n2 = temp[i].second;
                  // getting index number 
              indexRe = n % arraySize;

            if (arr[indexRe].second == 0) {

            
              arr[indexRe] = make_pair(n, n2);
            } else { // find space for two same index key

              int newIndex = indexRe;
              while (arr[newIndex].second != 0) {

                  newIndex++;
                if (newIndex == arraySize) {
                  newIndex = 0;
                }
                  if(arr[newIndex].second == -1){
                      break;
                  }
              }
              arr[newIndex] = make_pair(n, n2);
            }
          }
        }

      } else { // if load factor less then 0.5

       
      }

    } else if (choice == "displayStatus") { // find the status base on index number

      int displayS;
      cin >> displayS;
        
      if (arr[displayS].second == 0) {
        cout << "Empty" << endl;
      } else if (arr[displayS].second == -1) {
        cout << arr[displayS].first << " Deleted" << endl;
      } else if (arr[displayS].second == 1) {
        cout << arr[displayS].first << " Active" << endl;
      }

    } else if (choice == "tableSize") { // find the table size
      cout << arraySize << endl;

    } else if (choice == "search") { // searching the key in table
      int searchVal;
      cin >> searchVal;
      int findKey = searchVal % arraySize;
        
      if (arr[findKey].first == searchVal && arr[findKey].second != -1) {
        cout << arr[findKey].first << " Found" << endl;
      } else { // find the key if not found in index , and look unitl meet 0.

        int indexS = findKey;
        while (arr[indexS].first != searchVal) {

          indexS++;
          if (indexS == arraySize) {
            indexS = 0;
          }
            if(arr[indexS].second == 0 || arr[indexS].second == -1){
                break;
            }
        }

        if (arr[indexS].first == searchVal && arr[indexS].second != -1) {
          cout << arr[indexS].first << " Found" << endl;
        }

        else {
          cout << searchVal << " Not found" << endl;
        }
      }

    } else if (choice == "delete") { //  deleting key from a table
      int deleteVal;
      cin >> deleteVal;

      int deleteIndex = deleteVal % arraySize;

      if (arr[deleteIndex].first == deleteVal && arr[deleteIndex].second == 1) {

        int val = arr[deleteIndex].first;
        arr[deleteIndex] = make_pair(val, -1);
     
      } else {

        int index3 = deleteIndex;
        while (arr[index3].second == -1 || arr[index3].second == 1) {

          if (arr[index3].second == 0) {
            break;
          }
          index3++;
          if (index3 == arraySize) {
            index3 = 0;
          }

          if (arr[index3].first == deleteVal) {
            int val1 = arr[index3].first;
            arr[index3] = make_pair(val1, -1);
          
          }
        }
      }
    }

    numLoop--;
  }

  return (0);
}
