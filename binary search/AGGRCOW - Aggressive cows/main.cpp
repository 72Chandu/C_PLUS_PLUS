/*
N stalls(2 <= N <= 100,000)  at positions x1 ... xN (0 <= xi <= 1,000,000,000).
C (2 <= C <= N)  What is the largest minimum distance b/w 2 cows?
no of test case : 1  N=5 c=3
position of stalls: [1 2 8 4 9 ]
sort the stalls to find the distance: [1 2 4 8 9]. largest min dist can be (1,2,3...)->monotonic
functio -> appaly bs on distance   min dis=1  max dis=9-1=8

[1             8]     [1  2  4  8  9]
lo    mid=4    hi      c1      c2    -> min dis=4 is not possible becaue we cant place c3
so it obiuse that we are not able to place cow at the dis more then 4 , discar right

[1        3]     [1  2  4  8  9]
lo mid=2  hi     c1     c2  c3  -> ans=2 , able to place 3 cows we are looking for largest ditance so we look for right side 

[3        3]   [1  2  4  8  9]
lo mid=3  hi    c1    c2  c3   ans=3 able to place  after this itaration we terminate from loop
conclusion distance b/w 2 cows must be >= mid to place on stall
*/

#include<bits/stdc++.h>
using namespace std;
int isPossible(vector<int>&stall, int c, int mid, int n){
      int prev_stall=0;
      int no_of_cows_placed=1;
       for(int curr_stall=1; curr_stall<n; curr_stall++){
           int dist_between_stall= stall[curr_stall]-stall[prev_stall];//1  2  4  8  9
           if(dist_between_stall>=mid){                                //p  c
               no_of_cows_placed++;
               prev_stall=curr_stall;
               if(no_of_cows_placed==c) return true;
           }
       }
       return false;
 }
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, c;
        cin>>n>>c;
        vector<int>stall(n);
        for(int i=0;i<n;i++){
            cin>>stall[i];
        }
        sort(stall.begin(),stall.end());
        int lo=1, hi=stall[n-1];
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isPossible(stall,c,mid, n)){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
         cout<<ans;
    }
   
}
//https://www.geeksforgeeks.org/problems/aggressive-cows/1
/*
n=5  -> stall
k=3  -> cow
stalls = [1 2 4 8 9]
Output:
3
Explanation:
The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, 
which also is the largest among all possible ways.
*/
bool isPlacecdCow(vector<int>s, int k,int mid){
        int CountCow=1;
        int pos=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]-pos>=mid){
                CountCow++;
                pos=s[i];
            }
            if(CountCow==k) return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int lo=0;
        int hi=stalls[stalls.size()-1]- stalls[0];
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isPlacecdCow(stalls, k, mid)){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }