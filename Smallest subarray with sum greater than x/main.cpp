/*https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x/0

Input: A[] = {1, 4, 45, 6, 0, 19} x  =  51 Output: 3
Explanation:Minimum length subarray is  {4, 45, 6}
Input: A[] = {1, 10, 5, 2, 7} x  = 9 Output: 1
              i   j
Explanation: Minimum length subarray is {10} 

int minlen=n-1;
for(int i=0;i<n;i++){
    int currSum=arr[0];
    if(currSum>x) return 1;
    for(int j=i+1;j<n;j++){
        currSum+=arr[j];
        if(currSum>x && (j-i+1)<minlen){
            minlen=j-i+1;
        }
    }
    return minlen;
}
x=50
 1  10  3  40  18     1  10  3  40  18       1  10  3  40  18            1  10  3  40  18 
i,j -> s=1, l=6       i   j -> s=11, l=6     i      j -> s=14, l=6       i         j ->s=54>50,l=4

1  10  3  40  18                1  10  3  40  18              1  10  3  40  18
   i      j ->s=53>50,l=3              i   j ->s=43<50,l=3           i       j ->s=61>50,l=3
   
  1  10  3  40  18                    1  10  3  40  18
             i  j ->s=58>50,l=2                     i,j ->s=18<50,l=2
*/
int smallestSubWithSum(int arr[], int n, int x){
    int minLen = n + 1; // Initialize to a large value
    int currSum = 0;
    int start = 0;
    bool found = false; // Flag to check if subarray with sum >= x exists
    for (int end = 0; end < n; end++) {
        currSum += arr[end];
        while (currSum > x && start <= end) {
            found = true; // Subarray with sum >= x exists
            if (end - start + 1 < minLen) minLen = end - start + 1;
            currSum -= arr[start];
            start++;
        }
    }
    if (!found) return 0;     // If no such subarray exists
    return minLen;
        
    }