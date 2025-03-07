/*
Given two positive integers left and right, find the two integers num1 and num2 such that:

    left <= num1 < num2 <= right .
    Both num1 and num2 are 

    .
    num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.

Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].

 

Example 1:

Input: left = 10, right = 19
Output: [11,13]
Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.

Example 2:

Input: left = 4, right = 6
Output: [-1,-1]
Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.

 

Constraints:

    1 <= left <= right <= 106

*/

class Solution {
    public:
        vector<int> closestPrimes(int l, int r) {
            vector<int> sieve(r+1, 1);
            sieve[0] = 0;
            sieve[1] = 0;
            for(int i = 2 ; i*i <= r; i++){
                if(sieve[i]){
                    for(int j = i*i; j <= r; j= j+i){
                        sieve[j] = 0;
                    }
                }
            }   
            vector<int> primes;
            vector<int> ans = {-1, -1};
            while (l <= r) {
                if (sieve[l]) {
                    primes.push_back(l);
                }
                l++;
            }
            if (primes.size() == 1)
                return ans;
            int mini = INT_MAX;
            for (int i = primes.size() - 1; i > 0; i--) {
                if (primes[i] - primes[i - 1] <= mini) {
                    mini = primes[i] - primes[i - 1];
                    ans[0] = primes[i - 1];
                    ans[1] = primes[i];
                }
            }
            return ans;
        }
    };