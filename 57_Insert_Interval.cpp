//https://leetcode.com/problems/insert-interval/description/?envType=problem-list-v2&envId=array
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        int i=0, n=intervals.size();
        while(i<n && intervals[i][1]<newInterval[0]){ //add all intervel that comes before newIntervel
            res.push_back(intervals[i]); //intervels=[1,2], newInterval=[4,8]
            i++;
        }
        while(i<n && intervals[i][0] <=newInterval[1]){ //merge overlapping intervals
            newInterval[0]=min(newInterval[0],intervals[i][0]);//intervels=[1,3] ,newInterval=[2,5]. Merge to [1,5].
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        while(i<n){ //add all left intervel after newintervels
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
/*
intervals = [[1,3],[6,9]], newInterval = [2,5]
[1,3] overlaps with [2,5]. Merge to [1,5].
[6,9] does not overlap. Add [6,9] to the result
o/p =[[1,5],[6,9]]

intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
[1,2] is before [4,8]. Add [1,2].
[3,5] overlaps with [4,8]. Merge to [3,8].
[6,7] overlaps with [3,8]. Merge to [3,8].
[8,10] overlaps with [3,8]. Merge to [3,10].
[12,16] is after [3,10]. Add [12,16]
o/p = [[1,2],[3,10],[12,16]]

*/
