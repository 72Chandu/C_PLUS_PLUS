//https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
#include <iostream>
#include <climits>
using namespace std;

int minJumps(int arr[], int n) {
    if (n <= 1) // If the array has only one element or no element, no jumps needed
        return 0;

    if (arr[0] == 0) // If the first element is 0, it's impossible to reach the end
        return -1;

    int maxReach = arr[0]; // Maximum index reachable so far
    int steps = arr[0]; // Remaining steps at current position
    int jumps = 1; // Number of jumps needed

    for (int i = 1; i < n; i++) {
        if (i == n - 1) // If we reached the last index, return the number of jumps
            return jumps;

        maxReach = max(maxReach, arr[i] + i); // Update the maximum reachable index

        steps--; // Use one step to reach the current index

        if (steps == 0) { // If no steps left, we need to jump
            jumps++;

            if (i >= maxReach) // If the current index is beyond the maximum reachable index, it's impossible to reach the end
                return -1;

            steps = maxReach - i; // Set steps to the remaining steps based on the updated maximum reachable index
        }
    }

    return -1; // If we didn't reach the end, it's impossible to reach the end
}

int main() {
    int arr[] = {0, 2, 1, 3, 27, 9, 15, 7, 29, 7, 3, 23, 1, 19, 16, 27, 16, 19, 17, 30, 25, 5, 29, 7, 17, 12, 12, 2, 18, 29, 26, 13, 5, 6, 20, 24, 28, 25, 30, 10, 23, 26, 26, 23, 8, 15, 26, 14, 26, 0, 17, 5, 28, 27, 0, 18, 26, 26, 10, 24, 19, 5, 19, 13, 6, 3, 10, 21, 2, 12, 16, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minJumps(arr, n) << endl;
    return 0;
}
