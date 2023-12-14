/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw3_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw3_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw3_1.cpp
 * Abstract: This program converts directed weighted graphs to an adjacency list format, using a 2D array to accomplish the task. First, the program prompts the user to input the number of vertices in the graph. Then, the program utilizes a while loop to populate each index number in the 2D array with data. Once the data has been entered, the program employs a loop to print the resulting adjacency list. This format provides a clear and concise way to represent the relationships between vertices in the graph.
 * ID: 7263
 * Name: Mohammad Haroon 
 * Date: 02/14/2023
 */

#include <iostream>
using namespace std;

int main() {

    // variables to take the number of vertex and edges from keyboard
	int vNum, eNum;

	cin >> vNum >> eNum; // user input

	int arr[vNum][vNum]; // declaring 2D array


    // intiliazing 2D array with -1
	for (int i = 0; i < vNum; i++) {
		for (int j = 0; j < vNum; j++) {
			arr[i][j] = -1;
		}
	}

	int num1, num2, num3; 
	int i = 0;
    // while loop use to enter data to 2D array 
	while (i < eNum) {
		cin >> num1 >> num2 >> num3;
		arr[num1][num2] = num3;
		i++;
	}

	int count = 0; // counter variable 
	int f = 1;

    // nested for loop 
	for (int i = 0; i < vNum; i++) {
		count = 0;
        
		for (int j = 0; j < vNum; j++) {
            
			if (arr[i][j] != -1) { // checking if 2D array data not equales -1
                // printing the finall result 
				if (f == 1) {
					cout << i << "->" << j << "," << arr[i][j];
					f = 0;
				} else {
					cout << "->" << j << "," << arr[i][j] << "";
				}

			} else {
				count++; // counting -1 values 
			}
		}

		if (count == vNum) { // checking if count equales with vertex size print that specific index number 
			cout << i;
		}
		f = 1;
		cout << endl;
	}
	return 0;
}
