/*
https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

Input: nums = [2,4,6,8,10]
Output: 7
Explanation: All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]


m1:  bruteforce 
1. find all subsequence  -> o(2^n)
2.check length>=3  and arithematic hona chaiye ->o(n)
total tc=o(2^n * n)

2,4,6,8  ->10->     2,4,6,8,10
(2,4,6)             (2,4,6)
(2,4,6,8)           (2,4,6,8,10)
(4,6,8)             (4,6,8,10)
d=diffrence f=frequency
2 4 6 8 10   d  f
j i          2  1 
             {2,4}
             
2 4 6 8 10   d  f    2 4 6 8 10   d  f
j   i        4  1      j i        2  1->1+1=2 
             {2,6}                {4,6} -> {2,4,6}  res=1

2 4 6 8 10   d  f    2 4 6 8 10   d  f    2 4 6 8 10   d  f
j     i      6  1      j   i      4  1        j i      2  1->1+2=3
             {2,8}                {4,8}                {6,8} ->{2,4,6,8}, {4,6,8} res=1+2

2 4 6 8 10   d  f    2 4 6 8 10   d  f    2 4 6 8 10   d  f                          2 4 6 8 10   d  f
j        i   8  1      j      i   6  1        j    i   4  1->1+1=2                         j  i   2  1->3+1           
             {2,10}               {4,10}               {6,10} ->{2,6,10},  res=3+1                {8,10}-> {6,8,10},{4,6,8,10},{2,4,6,8,10} res=4+3

*/
int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();          // Get the size of the input vector
    int res = 0;                  // Initialize the result to store the number of arithmetic slices
    unordered_map<long, int> mp[n]; // Create an array of hash maps, each storing counts of differences

    // Loop through each element in the array
    for (int i = 0; i < n; i++) {
        // For every element 'i', compare it with every previous element 'j'
        for (int j = 0; j < i; j++) {
            // Calculate the difference between the current element nums[i] and previous element nums[j]
            long diff = (long)nums[i] - nums[j];
            
            // Check if this difference is already seen at position 'j'
            // If found, get the count of arithmetic subsequences ending at 'j' with this difference
            auto it = mp[j].find(diff);
            int count_at_j = (it == end(mp[j])) ? 0 : it->second;

            // Add 'count_at_j + 1' to the count at position 'i' for the current difference
            // The +1 accounts for the new sequence [nums[j], nums[i]]
            mp[i][diff] += count_at_j + 1;
            
            // Add count_at_j to the result, because every valid subsequence that ends at 'j'
            // can be extended by 'i', making it a valid arithmetic subsequence
            res += count_at_j;
        }
    }
    
    // Return the total count of arithmetic subsequences
    return res;
}
