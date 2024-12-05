/*
https://leetcode.com/problems/reorganize-string/description/
Input: s = "aab"
Output: "aba"

Input: s = "aaab"
Output: ""

aaabbef  a-3 b-2 e-1 f-1
m-1 most ocuurance char ko  fit at non-adjacent in one go, fill rest char
m-2do also with pirity queue ;
*/
string reorganizeString(string s) {
    int hash[26]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }
    // try to placed most occur char
    char maxt_freq_char;
    int max_freq=INT_MIN;
    for(int i=0;i<26;i++){
        if(hash[i]>max_freq){
            max_freq=hash[i];
            maxt_freq_char=i+'a';
        }
    }
    int index=0;
    while(max_freq>0 && index<s.size()){ // a - a - a -..
        s[index]=maxt_freq_char;
        max_freq--;
        index+=2;
    }
    if(max_freq!=0){
        return "";
    }
    hash[maxt_freq_char-'a']=0;
    //placing the rest char 
    for(int i=0;i<26;i++){
        while(hash[i]>0){
            index=index>=s.size()?1:index;
            s[index]=i+'a';
            index+2;
        }
    }
    return s;
    
}