/*  1    2     3 
        abc   def
        
    4    5     6 
   gfi  jkl   mno
    
    7    8     9
  pqrs  tuv   wxyz
    
    *    0     #


Input: GEEKSFORGEEKS
Output: 4333355777733366677743333557777
Explanation: For obtaining a number, we need to press a number corresponding to that character for a 
number of times equal to the position of the character. For example, for character E, press number 3 
two times and accordingly.
*/
// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string arr[], string input){
	string output = "";
	int n = input.length();// length of input string
	for (int i = 0; i < n; i++) {
		if (input[i] == ' ') output = output + "0";// Checking for space
		else { // Calculating index for each character
			int position = input[i] - 'A';//For each character, subtract ASCII value of ‘A’ and obtain the position in the array pointed by that character and add the sequence stored in that array to a string.
			output = output + arr[position];
		}
	}
	return output;
}
int main(){
	string str[]= { "2", "22", "222", "3", "33", "333", "4",
			"44", "444", "5", "55", "555", "6", "66",
			"666", "7", "77", "777", "7777", "8", "88",
			"888", "9", "99", "999", "9999" };//For each character, store the sequence which should be obtained at its respective position in an array, i.e. for Z, store 9999. For Y, store 999. For K, store 55 and so on.
	string input = "GEEKSFORGEEKS";
	cout << printSequence(str, input);
	return 0;
}
