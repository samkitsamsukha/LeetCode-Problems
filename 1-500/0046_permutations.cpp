/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

    Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

    Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
    
    Example 3:

Input: nums = [1]
Output: [[1]]
 
    Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

// First Approach with TC : O(N!xN) and SC : O(N+N)
class Solution {
public:
    void funcForPermutation(vector<int> ds, vector<int> nums, int freq[], vector<vector<int>>& ans){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i<nums.size(); i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                funcForPermutation(ds, nums, freq, ans);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i = 0; i<nums.size(); i++){
            freq[i] = 0;
        }
        funcForPermutation(ds, nums, freq, ans);
        return ans;
    }
};

//Second Approach with TC : 
class Solution {
public:
    void swapApproach(int index, vector<int> &nums, vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            swapApproach(index+1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        swapApproach(0, nums, ans);
        return ans;
    }
};