/*
You are given an integer array nums.

A nums[l..r] is alternating if one of the following holds:

    nums[l] < nums[l + 1] > nums[l + 2] < nums[l + 3] > ...
    nums[l] > nums[l + 1] < nums[l + 2] > nums[l + 3] < ...

In other words, if we compare adjacent elements in the subarray, then the comparisons alternate between strictly greater and strictly smaller.

You can remove at most one element from nums. Then, you select an alternating subarray from nums.

Return an integer denoting the maximum length of the alternating subarray you can select.

A subarray of length 1 is considered alternating.

 

Example 1:

Input: nums = [2,1,3,2]

Output: 4

Explanation:

    Choose not to remove elements.
    Select the entire array [2, 1, 3, 2], which is alternating because 2 > 1 < 3 > 2.

Example 2:

Input: nums = [3,2,1,2,3,2,1]

Output: 4

Explanation:

    Choose to remove nums[3] i.e., [3, 2, 1, 2, 3, 2, 1]. The array becomes [3, 2, 1, 3, 2, 1].
    Select the subarray [3, 2, 1, 3, 2, 1].

Example 3:

Input: nums = [100000,100000]

Output: 1

Explanation:

    Choose not to remove elements.
    Select the subarray [100000, 100000].

 

Constraints:

    2 <= nums.length <= 105
    1 <= nums[i] <= 105

*/

class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        vector<vector<int>> pre(nums.size(), vector<int>(2, 1));
        vector<vector<int>> suf(nums.size(), vector<int>(2, 1));
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]){
                pre[i][0] = pre[i-1][1]+1;
            }
            else if(nums[i] < nums[i-1]){
                pre[i][1] = pre[i-1][0] + 1;
            }
        }
        for(int i = nums.size()-2; i>=0; i--){
            if(nums[i] > nums[i+1]){
                suf[i][1] = suf[i+1][0]+1;
            }
            else if(nums[i] < nums[i+1]){
                suf[i][0] = suf[i+1][1]+1;
            }
        }
        int ans = 1;
        for(int i = 0; i<nums.size(); i++){
            ans = max(ans, max(pre[i][0], pre[i][1]));
        }
        for(int i = 1; i<nums.size()-1; i++){
            if(nums[i-1] < nums[i+1]){
                ans = max(ans, pre[i-1][1]+suf[i+1][1]);
            }
            else if(nums[i-1] > nums[i+1]){
                ans = max(ans, pre[i-1][0]+suf[i+1][0]);
            }
        }
        return ans;
    }
};