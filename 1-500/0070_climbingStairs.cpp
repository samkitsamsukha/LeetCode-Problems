/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

 

Constraints:

    1 <= n <= 45

*/

class Solution {
public:
    int f(int n, vector<int>& dp){
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = f(n-1, dp) + f(n-2, dp);
    }
    int climbStairs(int n) {
        // vector<int> dp(n+1, -1);
        // dp[0] = 1;
        // dp[1] = 1;
        int prev1 = 1;
        int prev2 = 1;
        int sol;
        for(int i = 2; i<=n; i++){
            // dp[i] = dp[i-1] + dp[i-2];
            sol = prev1 + prev2;
            prev2 = prev1;
            prev1 = sol;
        }
        // return dp[n];
        return prev1;
    }
};