/*
You are given an integer array nums.

A

of nums is called centered if the sum of its elements is equal to at least one element within that same subarray.

Return the number of centered subarrays of nums.

 

Example 1:

Input: nums = [-1,1,0]

Output: 5

Explanation:

    All single-element subarrays ([-1], [1], [0]) are centered.
    The subarray [1, 0] has a sum of 1, which is present in the subarray.
    The subarray [-1, 1, 0] has a sum of 0, which is present in the subarray.
    Thus, the answer is 5.

Example 2:

Input: nums = [2,-3]

Output: 2

Explanation:

Only single-element subarrays ([2], [-3]) are centered.

 

Constraints:

    1 <= nums.length <= 500
    -105 <= nums[i] <= 105
*/

class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            for(int j = i; j<nums.size(); j++){
                int sum = 0;
                for(int k = i; k<=j; k++){
                    sum+=nums[k];
                }
                bool flag = true;
                for(int k = i; k<=j && flag; k++){
                    if(sum == nums[k]){
                        ans++;
                        flag = false;
                    }
                }
            }
        }
        return ans;
    }
};