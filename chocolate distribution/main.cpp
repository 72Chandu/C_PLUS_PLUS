/*
n-> of chocolates in each packet  m-> no of student 
Input: N = 8, M = 5 A = {3, 4, 1, 9, 56, 7, 9, 12} Output: 6
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 
9 - 3 = 6 by choosing following M packets :{3, 4, 9, 7, 9}.
Example 2: Input: N = 7, M = 3   A = {7, 3, 2, 4, 9, 12, 56} Output: 2
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 
4 - 2 = 2 by choosing following M packets :{3, 2, 4}.

index =0 1 2 3 4 5 6 7 
arr  = 3 4 1 9 56 7 9 12 
sort = 1 3 4 7 9 9 12 56
       i       j             j=i+m-1;   
diff=a[i+m-1]-a[i]  [ (9-1=8)->i++->(9-3=6)->i++-> (12-4=8)->i++->(7-56=49)]-> min= 6 is ans
*/
long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(),a.end());
    long long minDiff = LLONG_MAX;
    // Iterate through the vector to find the minimum difference between elements
    for(int i = 0; i + m - 1 < n; i++) {
        long long diff = a[i + m - 1] - a[i]; // Calculate the difference between elements
        if(diff < minDiff)  minDiff = diff;
    }
    return minDiff;
    } 