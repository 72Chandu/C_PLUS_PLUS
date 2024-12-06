/*https://www.spoj.com/problems/EKO/
N trees in a row: h1,h2,...hn
A[1...n] -> heights of trees
M-> A woodcuter needs m length of wood
h-> height of the sawblade.
Approach:
Length of wood that mirka gets res= sum (max(0,a[i]-h)) ,1<=i<=n
If (res<m) -> h+1,h+2b.&.. Are not possible
Else -> h can be your ans 1...h-1 are not required 
l=0; -> cut all the trees completely r=1e9; // log(10^9) = 9log10
Sol: n<=10^9 log(n)<log(1e9) nlog(n)<nlog(1e9)*/  
#include<bits/stdc++.h>
using namespace std;
  int main (){
      int n,m;//N->number of trees, M->A woodcuter needs m length of wood 
      cin>>n>>m;
      int a[n];
      for(int i=0;i<n;i++){
          cin>>a[i];
      }
      int l = 0, r = 1e9, ans = 0;
      while (l <= r){
         int mid = l + (r - l) / 2;//considering mid is length of cutter
         int res = 0;
         for (int i = 0; i < n; i++){
		  if (a[i] > mid){
		      res += a[i] - mid;
			}
		}
		if (res >= m){ //mid is a possible ans 
		  ans = mid;
		  l = mid + 1;
		}
	  else{
		  r = mid - 1;
		}
	}
	cout << ans;//the max^m integer height of the sawblade 
	return 0;
}


