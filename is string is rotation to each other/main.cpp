/*
Input: S1 = ABCD, S2 = CDAB
Output: Strings are rotations of each other

Input: S1 = ABCD, S2 = ACBD
Output: Strings are not rotations of each other
*/
// C++ program for the above approach
bool checkString(string& s1, string& s2, int indexFound,int Size){
    for (int i = 0; i < Size; i++) {// check whether the character is equal or not
        if (s1[i] != s2[(indexFound + i) % Size]) return false;
        // % Size keeps (indexFound+i) in bounds, since it ensures it's value is always less than Size
    }
    return true;
}
 
int main(){
 
    string s1 = "abcd";
    string s2 = "cdab";
 
    if (s1.length() != s2.length()) {
        cout << "s2 is not a rotation on s1" << endl;
    }
    else {
        vector<int> indexes;// store occurrences of the first character of s1
        int Size = s1.length();
        char firstChar = s1[0];
        for (int i = 0; i < Size; i++) {
            if (s2[i] == firstChar) {
                indexes.push_back(i);
            }
        }
        bool isRotation = false;//check if the strings are rotation of each other for every occurrence of firstChar in s2
        for (int idx : indexes) {
            isRotation = checkString(s1, s2, idx, Size);
            if (isRotation) break;
        }
        if (isRotation) cout << "Strings are rotations of each other"<< endl;
        else cout<< "Strings are not rotations of each other"<< endl;
    }
    return 0;
}

Time Complexity: O(n*n)
Auxiliary Space: O(n)

   
// C++ program for the above approach
 
#include <bits/stdc++.h>
using namespace std;
 
bool check_rotation(string s, string goal){
    if (s.size() != goal.size()) return false;
    queue<char> q1;
    queue<char> q2;
    for (int i = 0; i < s.size(); i++) {
        q1.push(s[i]);
    }
    for (int i = 0; i < goal.size(); i++) {
        q2.push(goal[i]);
    }
 
    int k = goal.size();
    while (k--) {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q2 == q1) return true;
    }
    return false;
}
Time Complexity: O(N1 * N2)
Auxiliary Space: O(N)

bool areRotations(string str1, string str2){
    if (str1.length() != str2.length()) return false;/* Check if sizes of two strings are same */
    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
}
Time Complexity: O(N*N)
Auxiliary Space: O(N)

bool areRotations(string str1, string str2){
    if (str1.length() != str2.length()) return false;//Check if sizes of two strings are same
    for (int i = 0; i < str1.length(); i++) {// check if ith character is equal to the first character of str2
        if (str1[i] == str2[0]) {// check suffix of str1 with prefix of str2
            if (str1.substr(i) == str2.substr(0, str1.length() - i)) {  // check prefix of str1 with suffix of str2
                if (str1.substr(0, i) == str2.substr(str1.length() - i)) return true;
            }
        }
    }
    // if none of the above cases satisfy then answer must be false so return false
    return false;
}

Time Complexity: O(N*N), 
Auxiliary Space: O(N) 