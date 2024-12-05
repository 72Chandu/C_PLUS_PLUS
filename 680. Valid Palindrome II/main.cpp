//https://leetcode.com/problems/valid-palindrome-ii/description/
/*
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
*/
bool checkpalindrom(string s, int i, int j){
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }else{
            i++;
            j--;
        }
    }
    return true;
}
bool validPalindrome(string s) {
    int i=0;
    int j=s.length()-1;
    while(i<=j){
        if(s[i]!=s[j]){
            // ek bar i ko remove, yaa  ek baar j ko remove or dekho ki palindrom hai ki nahi
            return checkpalindrom(s , i+1,j) || checkpalindrom(s , i, j-1);
            
        }else{
            i++;
            j--;
        }
    }
    return true;
}