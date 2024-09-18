/*Input: n = 6, X = 13 arr[] = [1 4 45 6 10 8] Output:1
Explanation: The triplet {1, 4, 8} in  the array sums up to 13.

vector<int>v;--> o(n^3)
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        for(int k=j+1;k<n;k++){
            if(a[i]+a[j]+a[k]==target) return 1;//or v.push_back(a[i]);v.push_back(a[j]);v.push_back(a[k]);
        }
    }
}
//retunr v;
*/
set<vector<int>>st;
for(int i=0;i,n;i++){
    set<int>hasset;//initalising the hash table every ith time 
    for(int j=i+1;j<n;j++){
        int third=-(a[i]+a[j]);
        if(hasset.find(third)!=hasset.end()){
            vector<int>temp={a[i],a[j],third};
        }
        hasset.insert(a[j]);//pushing the jth element to hash table
    }
}

-----------------------------
bool find3Numbers(int a[], int n, int x){
    sort(a,a+n); // Sort the array in non-decreasing order
    for(int i=0;i<n;i++){ // Iterate through each element of the array
        int l=i+1; // Initialize left pointer l to i+1
        int r=n-1; // Initialize right pointer r to the last element
        while(l<r){ // While left pointer is less than right pointer
            int sum=a[i]+a[l]+a[r]; // Calculate the sum of three elements
            if(sum==x) return true; // If sum equals x, return true
            if(sum<x) l++; // If sum is less than x, move left pointer to right to increase the sum
            if(sum>x) r--; // If sum is greater than x, move right pointer to left to decrease the sum
        }
    }
    return false; // If no such triplet found, return false
}

