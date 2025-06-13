/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

 

Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 400

*/

class Solution {
public:
    int f(int ind, vector<int>& dp, vector<int>& nums){
        if(ind == 0) return nums[0];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + f(ind-2, dp, nums);
        int notpick = 0 + f(ind-1, dp, nums);
        return dp[ind] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        // return f(n-1, dp, nums);
        // dp[ind] means ans for 0...ind
        int prev2 = nums[0];
        int prev1 = nums[0];
        if(n>1) prev1 = max(nums[0], nums[1]);
        int sol = nums[0];
        for(int i = 2; i<n; i++){
            int p = nums[i] + prev2;
            int np = 0 + prev1;
            sol = max(p, np);
            prev2 = prev1;
            prev1 = sol;
        }
        return prev1;
    }
};