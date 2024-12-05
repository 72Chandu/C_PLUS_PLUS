//https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
/*
Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".
*/
string removeOccurrences(string s, string part) {
    int pos=s.find(part); // implement find  manually as fn
    while(pos!=string::npos){
        s.erase(pos , part.length());//implement erase  manually as fn
        pos=s.find(part);
    }
    return s;    
}