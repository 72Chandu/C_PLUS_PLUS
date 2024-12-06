//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
class Solution {
public:
    bool canShip(const vector<int>& weights, int days, int capacity) {
        int currentWeight = 0;
        int requiredDays = 1;
        for (int weight : weights) {
            if (currentWeight + weight > capacity) {
                requiredDays++;
                currentWeight = 0; // Start a new day
            }
            currentWeight += weight;
            if (requiredDays > days)  return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()); // Minimum capacity  =10
        int right = accumulate(weights.begin(), weights.end(), 0); // Maximum capacity =55
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canShip(weights, days, mid)) {
                right = mid; // Try a smaller capacity
            } else {
                left = mid + 1; // Increase the capacity
            }
        }
        return left; // Minimum capacity found
    }
};
/*
weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, days = 5
Steps:
Binary search range: [10, 55].

Mid = 32:
Day 1: 1, 2, 3, 4, 5, 6 ,7(load = 28).
Day 2: 8 ,9, 10(load = 27).
Valid (2 days ≤ 5).

Mid = 21:
Day 1: 1, 2, 3, 4, 5 (load = 15).
Day 2: 6, 7, 8 (load = 21).
Day 3: 9 ,10(load = 19).
Valid (3 days ≤ 5).

Mid = 15:
Day 1: 1, 2, 3, 4, 5 (load = 15).
Day 2: 6, 7 (load = 13).
Day 3: 8 (load = 8).
Day 4: 9 (load = 9).
Day 5: 10 (load = 10).
Valid (5 days ≤ 5).
Return 15.
*/
