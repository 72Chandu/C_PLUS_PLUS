//https://leetcode.com/problems/gas-station/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0, curr_tank = 0, starting_station = 0;
        for (int i = 0; i < gas.size(); i++) {
            int balance = gas[i] - cost[i];
            total_tank += balance;
            curr_tank += balance;
            if (curr_tank < 0) {  
                // If we run out of gas, restart from the next station
                starting_station = i + 1;
                curr_tank = 0;
            }
        }
        return (total_tank >= 0) ? starting_station : -1;
    }
};

/*gas = [1,2,3,4,5], cost = [3,4,5,1,2]   Output: 3

 3   4   5   1   2
1-->2-->3-->4-->5-->1
starting=1
1-3(traveling)=-2 not possible

starting=4 , f=fill, t=travel
f=4
4-1=3 t-->3+5=8 f --> 8-2=6 t -->6+1=7 f -->7-3=4 t -->4+2=6 f
-->6-4=2 t --> 2+3=5 -->5-5=0 at 4

*/
