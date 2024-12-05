/*
https://leetcode.com/problems/reverse-only-letters/description/

Input: s = "ab-cd"
Output: "dc-ba"

Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"

Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"

m1-2 pointer approach
*/
string reverseOnlyLetters(string s) {
    int l=0; 
    int h=s.size()-1;
    while(l<h){
        if(isalpha(s[l]) && isalpha(s[h])){
            swap(s[l], s[h]);
            l++, h--;
        }else if(!isalpha(s[l])){
            l++;
        }else{
            h--;
        }
    }
    return s;
        
}