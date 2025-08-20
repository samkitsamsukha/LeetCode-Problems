/*
Given an integer array nums, return the length of the longest strictly increasing

.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1

 

Constraints:

    1 <= nums.length <= 2500
    -104 <= nums[i] <= 104

 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

*/

class Solution {
public:
    int mem(int i, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(i == nums.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int nt = 0 + mem(i+1, prev, nums, dp);
        int t = 0;
        if(prev == -1 || nums[i] > nums[prev]){
            t = 1 + mem(i+1, i, nums, dp);
        }
        return dp[i][prev+1] = max(t, nt);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        return mem(0, -1, nums, dp);
    }
};