//https://leetcode.com/problems/move-pieces-to-obtain-a-string/
class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.length();
        int i=0,j=0;
        // Ensure the counts of L and R match
        string filteredStart, filteredTarget;
        for (char c : start) {
            if (c != '_') filteredStart += c;
        }
        for (char c : target) {
            if (c != '_') filteredTarget += c;
        }
        if (filteredStart != filteredTarget) return false;
        while(i<n && j<n){
            while(i<n && start[i]=='_') i++;// Skip '_' in start
            while(j<n && target[j]=='_') j++;//Skip '_' in target

            if(i==n && j==n) return true;
            if(i==n || j==n) return false;

            if(start[i]!=target[j]) return false;

            if(start[i]=='L' && i<j) return false;//'L' can only move left
            if(start[i]=='R' && i>j) return false;//'R' can only move right

            i++;
            j++;

        }
        return true;
    }
};
