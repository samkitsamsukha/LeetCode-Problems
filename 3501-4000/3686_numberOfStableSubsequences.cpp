/*
You are given an integer array nums.

A

is stable if it does not contain three consecutive elements with the same parity when the subsequence is read in order (i.e., consecutive inside the subsequence).

Return the number of stable subsequences.

Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [1,3,5]

Output: 6

Explanation:

    Stable subsequences are [1], [3], [5], [1, 3], [1, 5], and [3, 5].
    Subsequence [1, 3, 5] is not stable because it contains three consecutive odd numbers. Thus, the answer is 6.

Example 2:

Input: nums = [2,3,4,2]

Output: 14

Explanation:

    The only subsequence that is not stable is [2, 4, 2], which contains three consecutive even numbers.
    All other subsequences are stable. Thus, the answer is 14.

 

Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 10​​​​​​​5
*/

const int MOD = 1e9+7;

class Solution {
public:
    int f(int i, int par, int streak, vector<int>& nums, vector<vector<vector<long long>>>& dp){
        if(i==nums.size()){
            if(streak == -1) return 0;
            else return 1;
        }
        if(dp[i][par+1][streak+1] != -1) return dp[i][par+1][streak+1];
        long long res = 0;
        res = res + f(i+1, par, streak, nums, dp)%MOD;
        int curpar = nums[i]%2;
        int newstreak = 1;
        if(curpar == par) newstreak = streak+1;
        if(newstreak < 3){
            res = res + f(i+1, curpar, newstreak, nums, dp)%MOD;
        }
        return dp[i][par+1][streak+1] = res%MOD;
    }
    int countStableSubsequences(vector<int>& nums) {
        vector<vector<vector<long long>>> dp(nums.size(), vector<vector<long long>>(3, vector<long long>(4, -1)));
        return f(0, -1, -1, nums, dp);
    }
};