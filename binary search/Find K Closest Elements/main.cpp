//https://leetcode.com/problems/find-k-closest-elements/description/
k=4, x=35
arr= 12 16 22 30 35 39 42 45 48 50 53 55 56
ind= 0  1   2  3  4  5  6  7  8  9  10 11 11
dif= 23 19  13 5  0  4  7  10 13 15  8 20 21 
     lo------->lo       hi<---------------hi

methode-1
sort the array w.r.t diff
 35 39 20 42 45 22 48 ..............
 ------------>ans
 
 methode-2 -> 2 pointer methode
 arr= 12 16 22 30 35 39 42 45 48 50 53 55 56
ind= 0  1   2  3  4  5  6  7  8  9  10 11 11
dif= 23 19  13 5  0  4  7  10 13 15  8 20 21 
     lo------->lo       hi<---------------hi

 
methode 3->bs + 2 pointer
 arr= 12 16 22 30 35 39 42 45 48 50 53 55 56
ind= 0  1   2  3  4  5  6  7  8  9  10 11 11
dif= 23 19  13 5  0  4  7  10 13 15  8 20 21 
             <-lo hi->
find the smalles element in array which is >=x -> lower bond 
hi-> index closest's element index
lo->hi-1
[lo, h]-> expand window to k


class Solution {
public:
   int lowerbond(vector<int>& arr, int x){
    int lo=0, hi=arr.size()-1, ans=hi;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]>=x){
            ans=mid;
            hi=mid-1;
        }else if(x>arr[mid]){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return ans;
   }
    vector<int> bsMethode(vector<int>& arr, int k, int x) {
        int hi=lowerbond(arr,x);
        int lo=hi-1;
        while(k--){
            if(lo<0){
                hi++;
            }else if(hi>=arr.size()){
                lo--;
            }
            else if(x-arr[lo]>arr[hi]-x){
                hi++;
            }else{
                lo--;
            }
        }
        return vector<int>(arr.begin()+lo+1, arr.begin()+hi);
    }
    vector<int> twopointerMethode(vector<int>& arr, int k, int x) {
        int lo=0;
        int hi=arr.size()-1;
        while((hi-lo)>=k){// we reduce n->k , tc=o(n-k)
            if((x-arr[lo])>(arr[hi]-x)){
                lo++;
            }else{
                hi--;
            }
        }
        // vector<int>ans;//s.c=o(k)
        // for(int i=lo;i<=hi;i++){
        //     ans.push_back(arr[i]);
        // }
        // return ans;

        return vector<int>(arr.begin()+lo, arr.begin()+hi+1);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //return twopointerMethode(arr,k,x);
        return bsMethode(arr,k,x);
    }
};
