/*
https://leetcode.com/problems/rotate-string/description/

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:
 
abcdeabcde

Input: s = "abcde", goal = "abced"
Output: false
abcdeabcde
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.length() == goal.length() && (s + s).find(goal) != string::npos;
    }
};

class Solution {
public:
    bool rotateString(string s, string goal) {
      int n=s.size();
      while(n!=0){
      char lastchar=s.back();//storing last char from string s 
      s.pop_back();//removing last char of string s
      s=lastchar+s;//adding last char to first position of string 
      if(s==goal) return true;
      n--;
      }
      return false;
    }
};