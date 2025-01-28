/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

    Example 1:

Input: nums = [3,2,3]
Output: [3]
    
    Example 2:

Input: nums = [1]
Output: [1]
    
    Example 3:

Input: nums = [1,2]
Output: [1,2]
 
    Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
*/

#include<map>
#include<vector>

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        vector<int> result;
        for(auto it : mpp){
            if(it.second > (nums.size()/3)){
                result.push_back(it.first);
            }
        }
        return result;
    }
};