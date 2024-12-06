class Solution {
public:
    int search(vector<int>& v, int target) {
    int lo=0, hi=v.size()-1;
    int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(v[mid]==target) ans=mid;
            if(v[mid]>=v[lo]){
                if(target>=v[lo]&& target<=v[mid]){//if target found b/w lo and mid
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
            else{//lo ele is bigger then mid
               if(target>=v[mid] && target<=v[hi]){//target found b/w mid to hi
                   lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }  
    }
    return ans;
    }
};
// m2-
int findpivot(vector<int>v){
    int lo=0, hi=v.size()-1;
    int ans=-1;
    if(v[lo]<v[hi]){
        return lo;
    }
    else{
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(v[mid]>v[mid+1] && mid+1<=hi) ans=mid+1; // (4, 5 ,6 ,[7 ,2] ,3) if mid->7
            if(v[mid]<v[mid-1] && mid-1>=lo) ans=mid; // if mid->2
            if(v[mid]>v[lo]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
    }
    return ans;
}
int binarySearch(vector<int>&v,int x){
    int lo=0;//starting of search space
    int hi=v.size()-1;//end of search space
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(v[mid]==x){
            return mid;
        }
        else if(v[mid]<x){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return -1;
}
int serach(vector<int>v, int tar){
    int pivotindex=findpivot(v);
    if(tar>=v[0] && tar<=v[pivotindex]){
        ans=binarySearch(v , 0, pivotindex);
    }else{
        ans=binarySearch(v ,pivotindex, v.size()-1);
    }
    return ans;
}
// 4 5 6 7 0 1 2  tar=0  pivoted ele=7
