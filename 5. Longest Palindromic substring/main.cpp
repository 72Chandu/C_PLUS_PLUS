/*
https://leetcode.com/problems/longest-palindromic-substring/description/

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 
 
*/
    bool isPalindrome(string &s , int lo, int hi){
        while(lo<hi){
            if(s[lo]!=s[hi]){
                return false;
            }
            lo++;
            hi--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(isPalindrome(s, i,j)){
                    string t=s.substr(i,j-i+1);
                    ans=t.size() > ans.size() ? t:ans;
                }
            }
        }
        return ans;
    }//t.c=o(n^3)
// do with dp -> o(n^3)