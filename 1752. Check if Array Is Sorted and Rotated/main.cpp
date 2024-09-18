/*
https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].


Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.


Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 
*/
bool check(vector<int>& nums) {
    int n = nums.size();
    int count = 0; // Count the number of places where the array is not in non-decreasing order
    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n]) {
            count++;
        }
    }
    // The array can be considered rotated sorted if there is at most one such place
    return count <= 1;
}