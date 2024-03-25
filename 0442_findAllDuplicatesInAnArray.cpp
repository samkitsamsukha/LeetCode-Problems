/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

    Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

    Example 2:

Input: nums = [1,1,2]
Output: [1]

    Example 3:

Input: nums = [1]
Output: []
 
    Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.
*/

#include<bits/stdc++.h>
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result; //create the array which will contain duplicates
        for(auto currentNum : nums){
            // since we have the range of elements from (1, n) and the array might as well contain a maximum of n elements, we change the indexing by reducing the absolute value of current number by 1
            int index = abs(currentNum) - 1;
            // if the number at this index after changing the index is less than zero, it means it has appeared once hence we add it to the duplicate array
            if(nums[index] < 0){
                result.push_back(abs(currentNum));
            }
            else{
                // if the number at any index is not less than 0, it means that it has appeared once, hence we multiply it by -1 so that next time it is encountered, we know that this has already been visited.
                nums[index] = nums[index] * -1;
            }
        }
        return result;
    }
};