/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

 

Constraints:

    1 <= nums.length <= 200
    1 <= nums[i] <= 100

*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        int target = sum/2;
        vector<vector<bool>> dp(nums.size(), vector<bool> (sum+1, 0));
        for(int i = 0; i<dp.size(); i++){
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for(int i = 1; i<nums.size(); i++){
            for(int j = 0; j<=target; j++){
                bool nt = dp[i-1][j];
                bool t = false;
                if(j > nums[i]) t = dp[i-1][j-nums[i]];
                dp[i][j] = t | nt;
            }
        }
        return dp[nums.size()-1][target];
    }
};