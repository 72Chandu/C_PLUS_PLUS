//https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
/*
1 unit time to paint 1 unit of the board. 
Input:
n = 5
k = 3  -> painter
arr[] = {5,10,30,20,15} a[i]-> length of ith board
Output: 35
Explanation: The most optimal way will be:
Painter 1 allocation : {5,10}
Painter 2 allocation : {30}
Painter 3 allocation : {20,15}
Job will be done when all painters finish
i.e. at time = max(5+10, 30, 20+15) = 35
simillar to book allocation
*/
bool isPossinleSol(int a[],int n,int k,long long mid){
        long long timeSum=0;
        int count=1;
        for(int i=0;i<n;i++){
            if(a[i]>mid){
                return false;
            }
            if(a[i]+timeSum > mid){
                count++;
                timeSum=a[i];
                if(count>k) return false;
            }else{
                timeSum+=a[i];
            }
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        long long lo=0;
        long hi=0;
        for(int i=0;i<n;i++){
            hi+=arr[i];
        }
        long long ans=-1;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            if(isPossinleSol(arr,n,k,mid)){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }