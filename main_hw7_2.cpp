/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw7_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw7_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw7_2.cpp
 * Abstract: This program checks whether two words are anagrams or not. Anagrams
 *are words that have the same characters. The program uses a map to store each
 *character and the frequency of each character. After determining whether both
 *words are anagrams, the program checks if the length of both words is the
 *same. If the length is not the same, it will print "no anagram" output. ID:
 *7263 Name: Mohammad Haroon Date: 03/22/2023
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	string na1, na2, na3, na4;
	cin >> na1 >> na2;

	map<char, int> freq;

	
	char name, name2;
    
	int size1 = na1.length();
	int size2 = na2.length();

    // changing string to upper case
	for (int i = 0; i < na1.length(); i++) {
		name = toupper(na1[i]);

		na3 += name;
	}
    //changing string to upper case
	for (int i = 0; i < na2.length(); i++) {
		name2 = toupper(na2[i]);

		na4 += name2;
	}
    // sorting both strings 
	sort(na3.begin(), na3.end());
	sort(na4.begin(), na4.end());

	bool check = true; // bool varaible will be set true if words are anagram if
					   // not false

	if (size1 == size2) { // checking if the length of both words are equal
		for (int i = 0; i < size1; i++) {
			if (na3[i] !=
				na4[i]) { // check each char in both words matching or not
				check = false;
				break; // when words are not angram break the loop set bool to
					   // false

			} else {
				check = true; // when words are angaram set bool to true
			}

		} // End of loop

		// using map to store every char and the frequancy
		for (char str : na3) {
			freq[str]++;
		} // end of each for loop

		if (check) {
			cout << "ANAGRAM" << endl;
			// printing the every char of the words and frquancy
			for (auto &p : freq) {
				cout << p.first << ":" << p.second << endl;
			}
		} // end of if statement
		else {
			cout << "NO ANAGRAM" << endl;
		}

	} // end of if statement

	else { // print when words are not equale in length
		cout << "NO ANAGRAM" << endl;
	}

	return (0);
}
