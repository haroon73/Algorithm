/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw2_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw2_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw2_1.cpp
 * Abstract: This program reads string to find if it is a palindrome or not. There are two functions in this program where the first one removes all special char from string and change all letters to upper case. the second function has two pointers: one for the first index and the second for the last index to scan for similar words. 
 * ID: 7263
 * Name: Mohammad Haroon 
 * Date: 02/06/2023
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;



// Function that remove special char from string and change the string to upper case
string removeSpecialChar(string name){

    string specialChar = "~`!@#$%^&*()+=?/><|{}-,";
    for(auto i : specialChar){ //  for each loop 
        name.erase(remove(name.begin() , name.end() , i), name.end()); //  removing all special char
    }

    for(int j = 0 ; j < name.length() ; j++){
        name[j] = toupper(name[j]); // convert letters to all upper case
    }



    
   return name;
}


// Function that find if string is palinderome or not 
string par(string name){
    string name1 = removeSpecialChar(name); // function call 
    string name2;
   
    int index = name1.size() -1; // variable that point to last index of string 
    for(int i = 0; i != index ; i++){
        if(name1[i] == name1[index]){ // checking if last and first index ae same 
            index--;
            name2 = "PALINDROME";
        }
        else{
            // when not same char program break and return the index letter 
            string name3 = "NO:";
            name2 = name3 + name1[i];
           break;
        }
    }
    return name2;
    
}

int main() {

string name;

cin >> name;
//function call 
cout <<par(name) << endl;







    return (0);
}



