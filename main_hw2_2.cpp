/*
 * INSTRUCTION:
 *     This is a Java starting code for hw2_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "Main.java".
 *     But rename it to "main_hw2_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw2_2.cpp
 * Abstract: This program converts decimal numbers to binary numbers. The program takes input from the keyboard and the number of input then the program converts that input number to two power of input number which will show how many numbers need to be converted to binary numbers. The program uses two functions first function converts the number to binary and checks if the bits are according to the input number if not the function push to these bits to a vector then function is reverse the number and returns the vector. The second function just takes input from the user and then makes the final print. 
 * ID: 7263
 * Name: Mohammad Haroon
 * Date: 02/09/2023
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// A function that converts a decimal to binary which returns a vector. This function takes two arguments which is the number of elements and number bits we want to print. This function converts to binary then checks the bit number if it is not correct push that many bits to the vector then push all the bits to the new vector in reverse and return that vector. 
vector <int> check(int dec , int index){
    vector <int> v , v2; // declare to integer vectors
    while(dec > 0){ // converting decimal to binary number
        v.push_back(dec % 2); // pushing each bit to vector
        dec /= 2;
    }
    int num = v.size(); // take the size of the vector.

    // checking if vector has correct  number of bits if not push those zero bits to the vector
    if(num < index){ 
        for(int i = num ; i < index ; i++){
            v.push_back(0);
        }
    }

  // copying elements from v vector to v2 vector in reverse order.
    for(int i = v.size() -1; i >= 0 ; i--){
        v2.push_back(v[i]);
    }
    return v2; // return vector
}


//Function display prints the final result. It takes one argument which is the number of elements that will be printed as a string and pushed to a vector. The program converts the element number to 2 to the power of elements so which shows how many numbers need to be converted it binary. 
void display(int numEle){
    
  
    vector<int> v1;
  
  
    string nameEle;
    vector<string> ele;
  // pushing all elements to the vector from keyborad
    for(int i = 0 ; i < numEle ; i++){
        cin >> nameEle;
        ele.push_back(nameEle);
    }
  
    // converting two the power of number of elements got from keyboard.  
    int numBin = pow(2 , numEle); 

  
    
    int numZ;
    // print 0 decimal number 
    cout << 0 <<":";
    // checking if user enter 0
    if(numEle == 0){
        numZ = numEle + 1;
    }
    else{
        numZ = numEle;
    }
    for(int i = 0 ; i <= numZ - 1 ; i++){
        cout << 0 << "";
    }
    cout << ":EMPTY" << endl;

  
    // main process 
    for(int i = 1 ; i < numBin ; i++){
        // print index number that will convert to binary
        cout << i << ":";
       
        for(int j = 0 ; j < numEle ; j++){
            // convert each index number to binary 
            v1 = check(i , numEle); // function call
          
            cout << v1[j]; // printing the binary number
        } // INNER LOOP END
        cout << ":";

        // checking for 1 in vector to find the index number to print each elements got from keyboard input
        int first =1;
        for(int k = 0 ; k < v1.size() ; k++){
            
            if(v1[k] == 1){
               if(first == 1){ // printing space check
                 cout << ele[k];
                 first = 0;
               }
              else{
                cout << " " <<ele[k];
              }
               
            } // if statment end
        } //  loop end
      // clearing the vector to push new binary numbers
        v1.clear();
        cout << endl;
        } // outer loop end
        
    }
    
    
    

// main function
int main() {
	
    int num;
   
    cin >> num; // take user input for the number of elements
    display(num); // function call 
	
	
	

    return (0);
}

