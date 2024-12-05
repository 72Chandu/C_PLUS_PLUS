//https://leetcode.com/problems/valid-anagram/description/
/*
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all 
the original letters exactly once.

Input: s = "anagram", t = "nagaram"
Output: true

Input: s = "rat", t = "car"
Output: false

m-1 sorting bothe then check each char is same or not 
s==t->true else false -> t=o(nlogn)

m-2 : coutn the frequency match each frequency is same or not

 */
     bool isAnagram(string s, string t) {  // t= o(n+m)
        int freqtable[256]={0};
        for(int i=0; i<s.size(); i++){
            freqtable[s[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            freqtable[t[i]]--;
        }
        for(int i=0; i<256;i++){
            if(freqtable[i]!=0){
                return false;
            }
        }
        return true;
   }