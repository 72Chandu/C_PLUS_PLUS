//https://leetcode.com/problems/minimum-window-substring/description/?envType=study-plan-v2&envId=top-interview-150
Brute Force Idea:
Iterate over all possible substrings of s.
For each substring, check if it contains all characters of t (including frequency).
If it does, update the answer if the substring is smaller than the previous one.

s = "ADOBECODEBANC"   t = "ABC"
t = "ABC" -> tCount = { 'A':1, 'B':1, 'C':1 }

Outer loop from i = 0 to i = s.length()
Inner loop from j = i to j = s.length()
Substring = s.substr(i, j - i + 1)

s =  A  D  O  B  E  C  O  D  E  B  A  N  C
     ↑                          ↑
     i                          j

i | j | Substring | Contains A, B, C?
0 | 0 | A | No (missing B, C)
0 | 1 | AD | No
0 | 2 | ADO | No
0 | 3 | ADOB | No (missing C)
0 | 4 | ADOBE | No
0 | 5 | ADOBEC | Yes ✅
 |  | → Min = "ADOBEC" (length 6) | 
1 | 6 | DOBEC | Yes ✅
 |  | → Smaller than previous? No | 
6 | 9 | CODE | No
9 | 12 | BANC | Yes ✅
 |  | → Smaller than previous? YES (length 4) | 


You are checking every substring = O(n²),
and for each you check character frequencies = O(n)
→ Total: O(n³) — too slow for large strings.

//m-1 
#include <bits/stdc++.h>
using namespace std;
// Function to check if substring 'window' contains all characters of 't'
bool containsAllChars(const string &window, const unordered_map<char, int> &tCount) {
    unordered_map<char, int> windowCount;
    for (char c : window) {
        windowCount[c]++;
    }
    for (auto &[ch, count] : tCount) {
        if (windowCount[ch] < count) {
            return false;
        }
    }
    return true;
}

string minWindow(string s, string t) {
    int m = s.size();
    int minLen = INT_MAX;
    string result = "";

    unordered_map<char, int> tCount;
    for (char c : t) tCount[c]++;

    for (int i = 0; i < m; ++i) {
        for (int j = i; j < m; ++j) {
            string window = s.substr(i, j - i + 1);
            if (containsAllChars(window, tCount)) {
                if (window.size() < minLen) {
                    minLen = window.size();
                    result = window;
                }
            }
        }
    }

    return result;
}
int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "Minimum Window Substring: " << minWindow(s, t) << endl;
    return 0;
}

//m-2

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        unordered_map<char,int>tCount,windoCount;
        for(char c:t) tCount[c]++;
        int have=0, need=tCount.size(), l=0,minlen=INT_MAX,minStart=0;
        for(int r=0;r<s.size();r++){
            char c=s[r];
            windoCount[c]++;
            if(tCount.count(c) && windoCount[c]==tCount[c]) have++;
            while(have==need){
                if((r-l+1) <minlen){ //update res
                    minlen=r-l+1;
                    minStart=l;
                }
                char l_char=s[l];  
                windoCount[l_char]--;
                if(tCount.count(l_char) && windoCount[l_char]<tCount[l_char]) have--;
                l++;
            }
        }
        return minlen==INT_MAX ? "":s.substr(minStart,minlen);
    }
};
/*
s = "ADOBECODEBANC"
t = "ABC"
tCount = { A:1, B:1, C:1 }
need = 3

Right | Char | windowCount | have | Action
0       | A     | A:1      | 1   | A matched 
1       | D     | D:1      | 1   | Not needed
2       | O     | O:1      | 1   | Not needed
3       | B     | B:1      | 2   | B matched 
4       | E     | E:1      | 2   | Not needed
5       | C     | C:1      | 3   | C matched 
Now we have have == need, so current window is valid.
From index 0 to 5 → "ADOBEC"

Shrinking (left pointer moves)
Left | Char Removed | windowCount | have | Window
0    | A             | A:0        | 2 | "DOBEC" (not valid anymore) ❌


Continue moving right pointer

Right	Char	windowCount	have	Comment
6	     O	        O:2	     2	    Not needed
7	     D	        D:2	     2	    Not needed
8	     E	        E:2	     2	    Not needed
9	     B	        B:2	     2	    Already matched
10	     A	        A:1	     3	    A matched again 
11	     N	        N:1	     3	    Not needed
12	     C	        C:2	     3	    Already matched 
Valid window again from index 9 to 12 → "BANC"

Shrink from left again

Left	Char Removed	windowCount	have	       Window
9	        B	           B:1	    still valid	
10	        A	           A:0	     2	        Not valid ❌
So, "BANC" is smaller than "ADOBEC" — we update the result.


s:     A  D  O  B  E  C  O  D  E  B  A  N  C
index: 0  1  2  3  4  5  6  7  8  9 10 11 12

→ First valid window: [0..5] = "ADOBEC"
→ Better smaller window found: [9..12] = "BANC" ✅

Time Complexity: O(m + n)
*/
