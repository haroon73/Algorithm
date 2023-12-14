/*Reference: for the implementation heapify function use Udemy https://www.udemy.com/course/datastructurescncpp/learn/lecture/13209406#overview.
 * INSTRUCTION:
 *     This is a C++ starting code for hw11_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw11_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw11_1.cpp
 * Abstract:This program constructs a Max heap and performs various 
 *operations based on user input. The program takes input from the 
 *user and checks if the original input is a Max heap or not. The 
 *user can choose from several operations to perform on the heap, 
 *including finding the maximum key in the heap, inserting a new key 
 *and reconstructing the heap, deleting the root (which is the 
 *maximum key in the heap) and reconstructing the heap, and deleting 
 *a random key from the heap and reconstructing the heap. Finally, 
 *the program displays the list.
 * ID: 7263
 * Name: Mohammad Haroon
 * Date: 03/01/2023
 */

#include <iostream>
#include <vector>

using namespace std;

//function that construct maxheap
void heapify(vector<int> &v, int key, int size) {
  int maxValue = key;
  int lChild = 2 * key + 1;
  int rChild = 2 * key + 2;
  if (lChild < size && v[lChild] > v[maxValue])
    maxValue = lChild;
  if (rChild < size && v[rChild] > v[maxValue])
    maxValue = rChild;
  if (maxValue != key) {

    int temp = v[key];
    v[key] = v[maxValue];
    v[maxValue] = temp;
    heapify(v, maxValue, size); // fnction recursion for heapify
  }
}

// function building max heap
void buildMaxHeap(vector<int> &heap) {
  int size = heap.size();
    
  for (int i = size / 2 - 1; i >= 0; i--)
    heapify(heap, i, size);
}

// function that delete the root or max number form maxheap
void deleteMax(vector<int> &v) {

  int size = v.size(); // get the size of the maxheap
  
  v[0] = v[size - 1]; // bringing the last element of max heap to root
  v.pop_back(); // removing the last element of the max heap
  heapify(v, 0, size - 1); // reconstructed max heap
}

// function that check if the user input max heap or not
bool heapCheck(vector<int> &v, vector<int> &v2) {
  bool check;
    //comparing user input with max heap to find heap or not
  for (int i = 1; i < v.size(); i++) {
    if (v[i] == v2[i]) {
      check = true;
    } else {
      check = false;
      break;
    }
  }
  return check;
}

// delete functiuon from random loaction of max heap
void deleteKey(vector<int> &v, int key) {
  int findIndex;  // store the index number of key to delete
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == key) {
      findIndex = i;
      break;
    }
  }



  int size = v.size(); // get the size of max heap
  v[findIndex] = v[size - 1]; // move the last element of max heap to delete element place
  v.pop_back(); // remove the last element from maxheap
  int parentNode = (findIndex - 1) / 2; // parnet node

    // checking if new move node is smaller then children or not
  if (findIndex > 0 && v[findIndex] > v[parentNode]) {
    while (findIndex > 0 && v[findIndex] > v[parentNode]) {
      int temp = v[findIndex];
      v[findIndex] = v[parentNode];
      v[parentNode] = temp;
      findIndex = parentNode;
      parentNode = (findIndex - 1) / 2;
    }
  } else {
    heapify(v, findIndex, size - 1); // reconstruction of max heap
  }
}

// display function
void display(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    if (i == v.size() - 1) {
      cout << v[i];
    } else {
      cout << v[i] << " ";
    }
  }
  cout << endl;
}

int main() {

   int numElement, key;
   cin >> numElement; // number of key input from user

  vector<int> maxHeap, userInput; // vector


    // take first keys from user
  for (int i = 0; i < numElement; i++) {

    cin >> key;
    maxHeap.push_back(key);

    userInput.push_back(key); // store user input to check if it is max heap or not
  }

  buildMaxHeap(maxHeap); // function call to construct max heap

    // checking if user input is max heap or not
  if (heapCheck(maxHeap, userInput)) {
    cout << "This is a heap." << endl;
  } else {
    cout << "This is NOT a heap." << endl;
  }
   
  int numEntery;
  cin >> numEntery; // take number of input from user to perfrom operations
    
  int i = 0; // varibale use in loop 
  string choose;
  while (i < numEntery) {
    cin >> choose; // take user choice for operations

    if (choose == "displayMax") { // find the max number in max heap
      cout << maxHeap[0] << endl;
    } else if (choose == "insert") { // user insert new key to heap
      int newKey;
      cin >> newKey;

      maxHeap.push_back(newKey); // push new key to vector

      buildMaxHeap(maxHeap); // reconstruction of max heap after new key insertion

    } else if (choose == "deleteMax") { // deleteMax or root from heap

      deleteMax(maxHeap); // function call 

    } else if (choose == "delete") { // delete random key from max heap
      int deleteEle;
      cin >> deleteEle; // user input to delete the key
      deleteKey(maxHeap, deleteEle); // function call to delete the key

    } else if (choose == "display") { // display the max heap
      display(maxHeap);
    }

    i++; // 
  }

  return (0);
}
