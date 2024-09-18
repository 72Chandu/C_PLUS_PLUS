//https://www.geeksforgeeks.org/problems/reverse-array-in-groups0255/1
void reverseInGroups(vector<long long int> &arr, int k) {
        int n=arr.size();
        for (int i=0; i<n; i+=k){
            int lo=i;
            int hi=min(i+k-1, n-1);
            while (lo<hi){
                swap(arr[lo], arr[hi]);
                lo++;
                hi--;
            }
        }
}