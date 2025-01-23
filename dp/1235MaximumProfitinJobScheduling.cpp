/* 
https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/

Input: startTime = [1,2,3,3],
endTime = [3,4,5,6], 
profit = [50,10,40,70]
Output: 120

1 2 3 4 5 6:
case1;
choose 50 then we cant choose 10 beacuse it is overlap with 50
now choose either 40,70 beacuse both start at same thime after 50 end -> if 40 - 40+50=90, if 70- 70+50=120 
case2: 
choose 10 , we cant choose 40,70 because both is overlap with 10 => 10
case3: 
choose 40, we cant choose 70 because it is overlap => 40

=====every job has 2 option either it choose or not 
{s,e,p}-> sort based on s

{{1,3,50},{2,4,10},{3,5,40},{3,6,70}}
   take      not      take     not  =50+40
   take      not      not      take =50+70 -> ans
             take      not     not  =10
                       take    not  =40
                               take =70
   
   1.nextjob?
   2.taken=50+solve(nextjob)
   3.nottaken=solve(i+1);
*/
int n;
//finding the first job jika starting point >= CurrendJob ka end point
int getNextIndex(vector<vector<int>>&array, int l, int CurrendJobend){
    int hi=n-1;
    int res=n+1;
    while(l<=hi){
        int mid=l+(hi-l)/2;
        if(array[mid][0]>=CurrendJobend){// take this task
        res=mid;
         hi=mid-1;   
        }else{
            l=mid+1;
        }
    }
    return res;
}
int solve(vector<vector<int>>&array, int i){
    if(i>=n) return 0;
    int next=getNextIndex(array,i+1 ,array[i][1]);
    
    int taken=array[i][2]+solve(array,next);//next o index hoga jo job overlap nahi karega
    int nottaken=solve(array,i+1);
    return max(taken,nottaken);
}
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
  n=startTime.size();
  vector<vector<int>>array(n,vector<int>(3,0));//{s.e.p}
  for(int i=0;i<n;i++){
      array[i][0]=startTime[i];
      array[i][1]=endTime[i];
      array[i][2]=profit[i];
  }
  auto comp=[&](auto &v1,auto&v2){
      return v1[0]<=v2[0];
  };
  sort(begin(array),end(array),comp);
  return solve(array ,0);
}

//dp
vector<int> dp;
int n;

// Finding the first job where the starting point >= current job's end point
int getNextIndex(vector<vector<int>>& array, int l, int currentJobEnd) {
    int hi = n - 1;
    int res = n;  // If no valid job is found, return `n`
    while (l <= hi) {
        int mid = l + (hi - l) / 2;
        if (array[mid][0] >= currentJobEnd) {  // Found a non-overlapping job
            res = mid;
            hi = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}
int solve(vector<vector<int>>& array, int i) {
    if (i >= n) return 0;  // Base case: no more jobs to process
    if (dp[i] != -1) return dp[i];

    int next = getNextIndex(array, i + 1, array[i][1]);

    // Check bounds to avoid out-of-bounds access
    int taken = array[i][2] + (next < n ? solve(array, next) : 0);
    int notTaken = solve(array, i + 1);
    return dp[i] = max(taken, notTaken);
}
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    n = startTime.size();
    dp.assign(n, -1);  // Initialize dp array with size `n` and values of `-1`
    // Prepare the job array with {start, end, profit}
    vector<vector<int>> array(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        array[i][0] = startTime[i];
        array[i][1] = endTime[i];
        array[i][2] = profit[i];
    }
    // Sort jobs by start time with proper comparison function
    sort(array.begin(), array.end(), [&](auto& v1, auto& v2) {
        return v1[0] < v2[0];  // Fix the comparison to strict weak ordering
    });
    return solve(array, 0);
}
