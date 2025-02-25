//https://leetcode.com/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>m;
        for (char c:magazine){
            m[c]++;
        }
        for (char c:ransomNote) {
            if (m[c]==0) return false;
            m[c]--;
        }
        return true;
    }
};
