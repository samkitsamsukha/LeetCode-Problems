/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

    Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

    Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 
    Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++){
            // skipping duplicates
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i+1; j<nums.size(); j++){
                // skipping duplicates
                if(j>i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                int k = j+1;
                int l = nums.size()-1;
                while(k<l){
                    long long sum =  nums[i] + nums[j]; //compute current sum
                    sum = sum + nums[k];
                    sum = sum + nums[l];
                    if(sum > target){ // bring the pointer towards smaller numbers
                        l--;
                    }
                    else if(sum < target){ // send the pointer towards larger numbers
                        k++;
                    }
                    else{ //sum == target
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        result.push_back(temp);
                        l--;
                        k++;
                        //skipping duplicates
                        while(k<l && nums[k] == nums[k-1]){
                            k++;
                        }
                        //skipping duplicates
                        while(k<l && nums[l] == nums[l+1]){
                            l--;
                        }
                    }
                }
            }
        }
        return result;
    }
};