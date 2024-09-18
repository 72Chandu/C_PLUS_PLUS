/*https://www.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1
Input : arr[ ] = {2, 1, 5, 6, 3} K = 3  Output : 1
Explanation:To bring elements 2, 1, 3 together,swap index 2 with 4 (0-based indexing),
i.e. element arr[2] = 5 with arr[4] = 3
such that final array will be- 
arr[] = {2, 1, 3, 6, 5}

Example 2: Input : arr[ ] = {2, 7, 9, 5, 8, 7, 4}  K = 6  Output : 2 
Explanation: To bring elements 2, 5, 4 together, swap index 0 with 2 (0-based indexing)
and index 4 with 6 (0-based indexing)
such that final array will be- 
arr[] = {9, 7, 2, 5, 4, 7, 8}*/
#include <iostream>
#include <vector>

using namespace std;

// Function to find the minimum number of swaps required
int minSwapsToBringTogether(const vector<int>& arr, int k) {
    int n = arr.size();
    int count = 0;
    for (int num : arr) {
        if (num <= k)
            count++;
    }
    // Find the count of elements less than or equal to k in the first window
    int windowCount = 0;
    for (int i = 0; i < count; ++i) {
        if (arr[i] <= k)
            windowCount++;
    }

    // Initialize the minimum swaps required to bring all elements less than or equal to k together
    int minSwaps = count - windowCount;

    // Slide the window and update the minimum swaps required
    for (int i = 1; i <= n - count; ++i) {
        // If the element going out of the window was less than or equal to k, decrease the window count
        if (arr[i - 1] <= k)
            windowCount--;

        // If the new element coming into the window is less than or equal to k, increase the window count
        if (arr[i + count - 1] <= k)
            windowCount++;

        // Update the minimum swaps required
        minSwaps = min(minSwaps, count - windowCount);
    }

    return minSwaps;
}
int main() {
    vector<int> arr = {2, 1, 5, 6, 3};
    int k = 3;
    cout << "Minimum swaps required: " << minSwapsToBringTogether(arr, k) << endl;
    return 0;
}
/*
no of element<=3 are 3 {2,1,3}
widows={2,1,5} ,windowCount=2 {2,1} ,no of swaps=3-2=1
move-> window={1,5,6} , windowCount=1 {1} , minSwaps=min(1,1)=1
move->window={5,6,3}, windowCount=1{3}, minSwaps=min(1,1)=1

*/