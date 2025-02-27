//https://leetcode.com/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {   // give tle
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int>s(nums.begin(),nums.end());
       int longest=0;
       for(int num:nums){
        if(s.find(num-1)==s.end()){
            int currnum= num;
            int count=1;
            while(s.find(currnum+1)!=s.end()){
                currnum++;
                count++;
            }
            longest=max(longest,count);
        }
       }
       return longest;
       
    }
};
/*
s = {100, 4, 200, 1, 3, 2}

Check 100 → 99 is not in s, so it is a start of a sequence.
currnum = 100, count = 1
101 is not in s, so the sequence ends.
Update longest = max(0, 1) = 1

Check 4 → 3 is in s, so 4 is not the start of a sequence. Skip.

Check 200 → 199 is not in s, so it is a start of a sequence.
currnum = 200, count = 1
201 is not in s, so the sequence ends.
longest = max(1, 1) = 1

Check 1 → 0 is not in s, so it is a start of a sequence.
currnum = 1, count = 1
2 is in s → currnum = 2, count = 2
3 is in s → currnum = 3,count = 3
4 is in s → currnum = 4, count = 4
5 is not in s, so the sequence ends.
longest = max(1, 4) = 4
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int longest=1,count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) continue;
            else if(nums[i]==nums[i-1]+1) count++;
            else {
                longest=max(longest,count);
                count=1;
            }
       }
       return max(longest,count);
    }
};
