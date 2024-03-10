/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

    Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

    Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 
    Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mpp;
        mpp[0] = 1;
        int presum = 0;
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            presum =presum + nums[i];
            int rem = presum - k;
            count = count + mpp[rem];
            mpp[presum]++;
        }
        return count;
    }
};