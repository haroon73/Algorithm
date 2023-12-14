/*
 *Reference: for the implementation of merger sort I used my Udemy class. 
 *https://www.udemy.com/course/datastructurescncpp/learn/lecture/13191544?start=6#overview
 * INSTRUCTION:
 *     This is a C++ starting code for hw10_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw10_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw10_1.cpp
 * Abstract: This program utilizes three well-known sorting 
 *algorithms: Quick Sort, Insertion Sort, and Merge Sort. It 
 *generates random numbers ranging from zero to ten million and 
 *prompts the user to specify how many numbers they would like to 
 *generate. The size of the array is adjusted accordingly. The 
 *program displays the performance of each sorting algorithm, 
 *indicating the first, second, and last algorithms with good speed. 
 *The program allows the user to select whether to run the sorting 
 *in ascending order, descending order, or random order to check the 
 *performance.
 * ID: 7263
 * Name: Mohammad Haroon
 * Date: 04/20/2023
 */

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using namespace std::chrono;

const int RANDOM_RANGE = 10000001;
const int ARRAY_SIZE = 1000000;

bool sortByVal(const pair<string, float> &a, const pair<string, float> &b) {
  return a.second < b.second;
}

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

// Quick Sort using INT_MAX or INFINITY
int partitionA(int A[], int low, int high) {
  int pivot = A[low];
  int i = low;
  int j = high;

  do {
    // increment i as long as elements are smaler/equal to pivot
    do {
      i++;
    } while (A[i] <= pivot);

    // decrement j as long as elments are larger than pivot
    do {
      j--;
    } while (A[j] > pivot);
    if (i < j) {
      swap(&A[i], &A[j]);
    }
  } while (i < j);
  swap(&A[low], &A[j]);
  return j;
}

void quickSortA(int A[], int low, int high) {
  if (low < high) {

    int j = partitionA(A, low, high);
    quickSortA(A, low, j - 1);
    quickSortA(A, j + 1, high);
  }
}

// insertion Sort

void inserSort(int A[], int size) {
  for (int i = 1; i < size - 1; i++) {
    int temp = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > temp) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = temp;
  }
}

// merge sort

void Merge(int A[], int low, int mid, int high) {
  int i = low;
  int j = mid + 1;
  int k = low;
  int B[high + 1];
  while (i <= mid && j <= high) {
    if (A[i] < A[j]) {
      B[k++] = A[i++];
    } else {
      B[k++] = A[j++];
    }
  }
  while (i <= mid) {
    B[k++] = A[i++];
  }
  while (j <= high) {
    B[k++] = A[j++];
  }
  for (int i = low; i <= high; i++) {
    A[i] = B[i];
  }
}

void recursiveMergeSort(int A[], int low, int high) {
  if (low < high) {
    // Calculate mid point
    int mid = low + (high - low) / 2;

    // Sort sub-lists
    recursiveMergeSort(A, low, mid);
    recursiveMergeSort(A, mid + 1, high);

    // Merge sorted sub-lists
    Merge(A, low, mid, high);
  }
}

// printing array
void print(int v[], int size) {
  if (size <= 20) {

    for (int i = 0; i < size; i++) {
      cout << v[i] << " ";
    }
  }
}

int main() {

  srand(time(nullptr));

  int size, choice;
  cout << "Enter input size: ";
  cin >> size;

  int arr[size];
  int arr2[size];
  int arr3[size];

  cout << "========== Select Option for Input Numbers ==========" << endl;
  cout << "1. Ascending Order" << endl;
  cout << "2. Descending Order" << endl;
  cout << "3. Random Order" << endl;
  cout << "Choose option: ";
  cin >> choice;

  if (choice == 1) {
    for (int i = 0; i < size; i++) {
      int rNum = rand() % (RANDOM_RANGE + 0);
      arr[i] = rNum;
      arr2[i] = rNum;
      arr3[i] = rNum;
    }

    sort(arr, arr + size);
    sort(arr2, arr2 + size);
    sort(arr3, arr3 + size);
  } // end of if
  else if (choice == 2) {
    for (int i = 0; i < size; i++) {
      int rNum = rand() % (RANDOM_RANGE + 0);
      arr[i] = rNum;
      arr2[i] = rNum;
      arr3[i] = rNum;
    }
    sort(arr, arr + size, greater<int>());
    sort(arr2, arr2 + size, greater<int>());
    sort(arr3, arr3 + size, greater<int>());
  } // end of else if
  else {
    for (int i = 0; i < size; i++) {
      int rNum = rand() % (RANDOM_RANGE + 0);
      arr[i] = rNum;
      arr2[i] = rNum;
      arr3[i] = rNum;
    }
  } // end of else

  if (size <= 20) {
    cout << "Numbers generated: ";
    print(arr, size);
  }
  bool insertion = false, merge = false;

  cout << endl;
  char mergeSort, insertionSort;
  cout << "Do you want to run insertion sort(y/n)? ";
  cin >> insertionSort;

  cout << "Do you want to run merge sort(y/n)? ";
  cin >> mergeSort;
  float time_takenInsertion = 0;
  float time_takenMerge = 0;
  if (mergeSort == 'y') {

    // messuring merge sort
    merge = true;
    auto startM = chrono::high_resolution_clock::now();
    recursiveMergeSort(arr, 0, size - 1);
    auto endM = chrono::high_resolution_clock::now();
    time_takenMerge =
        chrono::duration_cast<chrono::nanoseconds>(endM - startM).count();
    print(arr, size);
    cout << endl;

  } // end of if

  if (insertionSort == 'y') {
    // mesurring instertion sort
    insertion = true;
    auto startI = chrono::high_resolution_clock::now();
    inserSort(arr2, size);
    auto endI = chrono::high_resolution_clock::now();
    time_takenInsertion =
        chrono::duration_cast<chrono::nanoseconds>(endI - startI).count();
    print(arr2, size);
    cout << endl;
  } // end of else if
    // messuring Quick sort
  arr3[size] = 15000000;
  auto startQ = chrono::high_resolution_clock::now();
  quickSortA(arr3, 0, size - 1);
  auto endQ = chrono::high_resolution_clock::now();
  float time_takenQuick =
      chrono::duration_cast<chrono::nanoseconds>(endQ - startQ).count();
  print(arr3, size);
  cout << endl;

  cout << "==================== Execution Result ====================" << endl;
  cout << "QuickSort: " << time_takenQuick / 1000000.0 << " milliseconds "
       << endl;
  if (insertionSort == 'y') {
    cout << "Insertion Sort : " << time_takenInsertion / 1000000.0
         << "milliseconds " << endl;
  }
  if (mergeSort == 'y') {
    cout << "Merge Sort : " << time_takenMerge / 1000000.0 << "milliseconds "
         << endl;
  }

  map<string, float> map;
  if (insertionSort == 'y' && mergeSort == 'y') {
    map["Quick"] = time_takenQuick;
    map["Insertion"] = time_takenInsertion;
    map["Merge"] = time_takenMerge;
  } else if (insertionSort == 'y' && mergeSort == 'n') {
    map["Quick"] = time_takenQuick;
    map["Insertion"] = time_takenInsertion;
  } else if (insertionSort == 'n' && mergeSort == 'y') {
    map["Merge"] = time_takenMerge;
    map["Quick"] = time_takenQuick;
  } else {
    map["Quick"] = time_takenQuick;
  }

  vector<pair<string, float>> sVector;
  for (auto m : map) {
    sVector.push_back(make_pair(m.first, m.second));
  }

  sort(sVector.begin(), sVector.end(), sortByVal);

  cout << "============================================================" << endl
       << endl;
  cout << "==========================Ranking=========================" << endl;
  int n = 1;
  for (auto v : sVector) {
    if (v.first == "Quick" || (v.first == "Merge" && merge == true) ||
        (v.first == "Insertion" && insertion == true))
      cout << "(" << n << ") " << v.first << " 0.000" << v.second << endl;
    n++;
  }

  return (0);
}

