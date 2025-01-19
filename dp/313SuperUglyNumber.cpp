https://leetcode.com/problems/super-ugly-number/description/?envType=problem-list-v2&envId=dynamic-programming
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long, vector<long>, greater<long>>pq;//mean heap
        unordered_set<long>seen;//ensuring no ugly is dublicate
        long currentugly=1;
        pq.push(1);
        seen.insert(1);
        for(int i=0;i<n;i++){
            currentugly=pq.top();
            pq.pop();
            for(int prime:primes){
                long nextugly=currentugly*prime;
                if(!seen.count(nextugly)){
                    seen.insert(nextugly);
                    pq.push(nextugly);
                }
            }
        }
        return currentugly;
    }
};
/*
ugly no is multiple of primes[i]
Input: n = 12, primes = [2,7,13,19]
Output: 32
pq = [1]
seen = {1}

i = 0:  currentugly = 1
pq=[2, 7, 13, 19]

i = 1:  currentugly = 2
pq=[7, 13, 19, 4, 14, 26, 38]

i = 2:currentugly = 4
pq=[7, 13, 19, 14, 26, 38 ,8, 28, 52, 76]

i = 3:currentugly = 7
New values added to pq and seen: 49, 91, 133
pq=[13, 19, 14, 26, 38 ,8, 28, 52, 76,49, 91, 133]

i = 4:  currentugly = 8
New values added to pq and seen: 16, 56, 104, 152
pq=[13, 19, 14, 26, 38 , 28, 52, 76,49, 91, 133,16, 56, 104, 152]

i = 5: currentugly = 13
New values added to pq and seen: 26, 91, 169, 247
pq=[19,14,26,38,28,52,76,49,91,133,16,56,104,152,26,91,169,247]

i = 6:  currentugly = 14
New values added to pq and seen: 28, 98, 182, 266
pq=[19,26,38,28,52,76,49,91,133,16,56,104,152,26,91,169,247,28,98,182,266]

i = 7:  currentugly = 16
New values added to pq and seen: 32, 112, 208, 304
pq=[19,26,38,28,52,76,49,91,133,56,104,152,26,91,169,247,28,98,182,266,32,112,208,304]

i = 8:  currentugly = 19
New values added to pq and seen: 38, 133, 247, 361
pq=[26,38 ,28,52,76,49,91,133,56,104,152,26,91,169,247,28,98,182,266,32,112,208,304]
i = 9:  currentugly = 26
pq=[38,28,52,76,49,91,133,56,104,152,26,91,169,247,28,98,182,266,32,112,208,304]

i = 10:     currentugly = 28
pq=[38 ,52,76,49,91,133,56,104,152,26,91,169,247,28,98,182,266,32,112,208,304]

i = 11: currentugly = 32
pq=[38,52,76,49,91,133,56,104,152,26,91,169,247,28,98,182,266,112,208,304]
*/



//----------------------------dp------------
class Solution {
public:
        int nthSuperUglyNumber(int n, vector<int>& primes) {
            vector<long long> dp(n); // DP array to store super ugly numbers
            vector<int> indices(primes.size(), 0); // Indices to track primes' multiples
            vector<long long>nextMultiples(primes.begin(),primes.end());//Next multiples of primes
            dp[0] = 1; // The first super ugly number is 1
            for (int i = 1; i < n; i++) {
                long long nextUgly=*min_element(nextMultiples.begin(), nextMultiples.end());
                dp[i] = nextUgly;
                // Update the next multiples for each prime
                for (int j = 0; j < primes.size(); j++) {
                    if (nextMultiples[j] == nextUgly) {
                        indices[j]++;
                        nextMultiples[j] = dp[indices[j]] * primes[j];
                    }
                }
            }
            return dp[n - 1];
        }
    };
    /*
    dp = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    indices = [0, 0, 0, 0]
    nextMultiples = [2, 7, 13, 19]


    i = 1:  nextUgly = min(2, 7, 13, 19) = 2
    dp = [1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    Update for prime 2:
    indices = [1, 0, 0, 0]
    nextMultiples = [4, 7, 13, 19]

    i = 2:  nextUgly = min(4, 7, 13, 19) = 4
    dp = [1, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    Update for prime 2:
    indices = [2, 0, 0, 0]
    nextMultiples = [8, 7, 13, 19]

    i = 3: nextUgly = min(8, 7, 13, 19) = 7
    dp = [1, 2, 4, 7, 0, 0, 0, 0, 0, 0, 0, 0]
    Update for prime 7:
    indices = [2, 1, 0, 0]
    nextMultiples = [8, 14, 13, 19]

    i = 4:  nextUgly = min(8, 14, 13, 19) = 8
    dp = [1, 2, 4, 7, 8, 0, 0, 0, 0, 0, 0, 0]
    Update for prime 2:
    indices = [3, 1, 0, 0]
    nextMultiples = [14, 14, 13, 19]

    i = 5:  nextUgly = min(14, 14, 13, 19) = 13
    dp = [1, 2, 4, 7, 8, 13, 0, 0, 0, 0, 0, 0]
    Update for prime 13:
    indices = [3, 1, 1, 0]
    nextMultiples = [14, 14, 26, 19]

    i = 6:   nextUgly = min(14, 14, 26, 19) = 14
    dp = [1, 2, 4, 7, 8, 13, 14, 0, 0, 0, 0, 0]
    Update for prime 2:
    indices = [4, 1, 1, 0]
    nextMultiples = [16, 14, 26, 19]
    Update for prime 7:
    indices = [4, 2, 1, 0]
    nextMultiples = [16, 28, 26, 19]

    i = 7:   nextUgly = min(16, 28, 26, 19) = 16
    dp = [1, 2, 4, 7, 8, 13, 14, 16, 0, 0, 0, 0]
    Update for prime 2:
    indices = [5, 2, 1, 0]
    nextMultiples = [26, 28, 26, 19]

    i = 8: nextUgly = min(26, 28, 26, 19) = 19
    dp = [1, 2, 4, 7, 8, 13, 14, 16, 19, 0, 0, 0]
    Update for prime 19:
    indices = [5, 2, 1, 1]
    nextMultiples = [26, 28, 26, 38]

    i = 9:   nextUgly = min(26, 28, 26, 38) = 26
    dp = [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 0, 0]
    Update for prime 2:
    indices = [6, 2, 1, 1]
    nextMultiples = [28, 28, 26, 38]
    Update for prime 13:
    indices = [6, 2, 2, 1]
    nextMultiples = [28, 28, 52, 38]

    i = 10:   nextUgly = min(28, 28, 52, 38) = 28
    dp = [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 0]
    Update for prime 2:
    indices = [7, 2, 2, 1]
    nextMultiples = [32, 28, 52, 38]
    Update for prime 7:
    indices = [7, 3, 2, 1]
    nextMultiples = [32, 49, 52, 38]

    i = 11:  nextUgly = min(32, 49, 52, 38) = 32
    dp = [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32]
    Update for prime 2:
    indices = [8, 3, 2, 1]
    nextMultiples = [38, 49, 52, 38]

    After 12 iterations, dp contains the first 12 super ugly numbers: [1, 2, 4,
    7, 8, 13, 14, 16, 19, 26, 28, 32]. So, the 12th super ugly number is
    indeed 32.
    */
