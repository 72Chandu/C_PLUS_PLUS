//https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/?envType=study-plan-v2&envId=top-interview-150
int removeDuplicates(int*a, int n){
    int i,j;
   while(i<n){
       while(i<n-1 && a[i]==a[i+1]){
           i++;
       }
       a[j]=a[i];//[0,0,1,1,2,2,3,3,4] o/p=[0,1,2,3,4]
       i++;
       j++;
   }
   return j;
}
