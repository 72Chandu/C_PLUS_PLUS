//https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/?envType=daily-question&envId=2024-10-21
class Solution {
public:
    int solve(const string &s, int l,unordered_set<string>&set){
        if(l==s.length()) return 0;
        int maxsplit=0;
        for(int i=l+1; i<=s.length();i++){
            string substring=s.substr(l,i-l);//exploring all string 
            if(set.find(substring)==set.end()){
                set.insert(substring);
                maxsplit=max(maxsplit,1+solve(s,i,set));
                set.erase(substring);
            }
        }
        return maxsplit;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>set;//for uniqness
        return solve(s,0,set);
    }
};