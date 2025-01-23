/*
https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/

job are dependent
atleast 1 task every day
Difficulty of the day =max(all the job on that day)
find total minimum difficulty

Input: jobDifficulty = [9,9,9], d = 4
Output: -1
Explanation: If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.
Example 3:

Input: jobDifficulty = [1,1,1], d = 3
Output: 3
Explanation: The schedule is one job per day. total difficulty will be 3.


i/p:   jobDifficulty={6,5,4,3,2,1}  d=2 o/p=7
{6,5,4,3,2,1}
  day1    day2
(6,5), (4,3,2,1)  = 6+4=10
(6,5,4), (3,2,1)  = 6+3=9
(6,5,4,3,2), (1) =6+1=7

recurrsion
  0 1 2 3 4 5
 {6,5,4,3,2,1} -> d=1 -> {5,4,3,2,1}
  i   maxD=6             last day you have to do all work maxD=5 -> return , maxD=6+5=11
  
 0 1 2 3 4 5
 {6,5,4,3,2,1} -> d=1 -> {4,3,2,1}
  i i  maxD=6             maxD=4 -> return , maxD=6+4=10 ->update
 
 0 1 2 3 4 5
 {6,5,4,3,2,1} -> d=1 -> {3,2,1}
  i i i maxD=6             maxD=3 -> return , maxD=6+3=9 ->update
 
 0 1 2 3 4 5
 {6,5,4,3,2,1} -> d=1 -> {2,1}
  i i i i maxD=6             maxD=2 -> return , maxD=6+2=8 ->update
  
  0 1 2 3 4 5
 {6,5,4,3,2,1} -> d=1 -> {1}
  i i i i i maxD=6             maxD=1 -> return , maxD=6+1=7 ->update
  i ->n-d tak he jayega
*/
int solve(vector<int>& JD,int n, int idx,int d){
    if(d==1){ //if there is only 1 day left then you have to do all remaining jobs in thet 1 day and find the max difficulty of that day and return it
        int  maxD=jd[idx];
        for(int i=idx;i<n;i++){
            maxD=max(maxD ,JD[i]);
        }
        return maxD;
    }
    int maxD=jd[idx];
    int finalRes=INT_MAX;
    /*
    try one by onr with all possibility
    take index={idx} wala job in 1st day
    take index={idx, idx+1} wala job in 1st day
    take index={idx, idx+1, idx+2} wala job in 1st day
    ...........and so on ........
    */
    for(int i=idx;i<=n-d;i++){
        maxD=max(maxD,JD[i]);
        int res=maxD+solve(JD,n,i+1,d-1);//2 variable change ho raha hai so, 2d dp lagega
        finalRes=min(finalRes,res);
    }
    return finalRes;
}
int minDifficulty(vector<int>& JD, int d) {
  int n=JD.size(); 
  if(n<d) return -1;
  return solve(JD , n,0,d);
}

//-----------------------------------dp----------
int dp[301][11];
int solve(vector<int>& JD,int n, int idx,int d){
    if(d==1){ 
        int  maxD=JD[idx];
        for(int i=idx;i<n;i++){
            maxD=max(maxD ,JD[i]);
        }
        return maxD;
    }
    if(dp[idx][d]!=-1){
        return dp[idx][d];
    }
    int maxD=JD[idx];
    int finalRes=INT_MAX;
    for(int i=idx;i<=n-d;i++){
        maxD=max(maxD,JD[i]);
        int res=maxD+solve(JD,n,i+1,d-1);
        finalRes=min(finalRes,res);
    }
    return dp[idx][d]=finalRes;
}
int minDifficulty(vector<int>& JD, int d) {
  int n=JD.size(); 
  if(n<d) return -1;
  memset(dp,-1,sizeof(dp));
  return solve(JD , n,0,d);
}
