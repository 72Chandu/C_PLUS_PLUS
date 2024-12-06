/*
n=5->no of ele  array[1, 3, 5, 7, 9] ,  k=3->queries 2, 4, and 8.
*/
#include <bits/stdc++.h>
using namespace std;
int main (){
  int n, k;
  cin >> n >> k;
  vector < int >vec (n);
  for (int i = 0; i < n; i++){
	  cin >> vec[i];
	}
  int x;
  while (k--){
	  cin >> x;
	  int lo = 0, hi = n - 1;
	  int mid;
	  int ans = n;
	  while (lo <= hi){
		  mid = lo + (hi - lo) / 2;
		  if (vec[mid] < x){
			  lo = mid + 1;
			}
		  else	{
			  ans = mid;
			  hi = mid - 1;
			}
		}
	  cout << ans + 1 << '\n';
	}
  return 0;
}
