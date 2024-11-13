/*
Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

    0 <= i < j < n, and
    lower <= nums[i] + nums[j] <= upper

 

Example 1:

Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).

Example 2:

Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).

 

Constraints:

    1 <= nums.length <= 105
    nums.length == n
    -109 <= nums[i] <= 109
    -109 <= lower <= upper <= 109


*/

#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int lowerb(vector<int> &nums, int n, int target){
        int low = n; 
        int high = nums.size()-1;
        int ans = nums.size();
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    int upperb(vector<int> &nums, int n, int target){
        int low = n;
        int high = nums.size()-1;
        int ans = nums.size();
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] <= target){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
    long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int lb = lower - nums[i];
            int ub = upper - nums[i];
            int a1 = lowerb(nums, i + 1, lb);
            int a2 = upperb(nums, i + 1, ub);
            ans += (a2 - a1);
        }
        
        return ans;
    }
};
