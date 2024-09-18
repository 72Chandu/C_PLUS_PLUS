/*Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      if(intervals.size()==1) return intervals; // Check if there's only one interval
      
      vector<pair<int,int>> p;// Convert 2D vector to a vector of pairs
      for(int i=0;i<intervals.size();i++){
          p.push_back({intervals[i][0],intervals[i][1]});
      } 
      
      sort(p.begin(),p.end());// Sort the intervals based on their start points
      vector<vector<int>> ans;// Initialize a vector to store the merged intervals
      
      // Initialize variables for start and end points of the first interval
      int start_point=p[0].first,  end_point=p[0].second;
      for(int i=0;i<p.size()-1;i++){          // Iterate through the sorted intervals
          vector<int> a(2);                  // vector to store a merged interval
          // Check if there's overlap between current interval and next interval
          if(end_point>=p[i+1].first){         // If overlap, update the end point
              end_point=max(end_point,p[i+1].second);
          }
          else{
              // If no overlap, push the merged interval to the answer vector
              a[0]=start_point;
              a[1]=end_point;
              
              start_point=p[i+1].first;//updating starting and ending point with next pair
              end_point=p[i+1].second;
              ans.push_back(a);
          }
      } 
      ans.push_back({start_point,end_point});// Push the last merged interval to the answer vector
      return ans;// Return the merged intervals
    }
};
/*intervals = [[1,3],[2,6],[8,10],[15,18]] 
                0 1   0 1   0  1   0   1
                 0     1      2       3
convert to pair  (1,3), (2,6), (8,10),(15,18) -> sorted
                   0      1       2      3
i=0
start_point=1  end_point=3 
3>2 -> end_point=max(3,6)=6
i=1
start_point=1 end_point=6
6>8 no a[0]=1  a[1]=6 -> a=[[1,6]]
start_point=8 end_point=10
i=3....
*/
