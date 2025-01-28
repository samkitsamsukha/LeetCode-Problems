/*
ou are given an integer array nums.

A
subsequence
sub of nums with length x is called valid if it satisfies:

    (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.

Return the length of the longest valid subsequence of nums.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

    Example 1:

Input: nums = [1,2,3,4]
Output: 4
Explanation: The longest valid subsequence is [1, 2, 3, 4].

    Example 2:

Input: nums = [1,2,1,1,2,1,2]
Output: 6
Explanation: The longest valid subsequence is [1, 2, 1, 2, 1, 2].

    Example 3:

Input: nums = [1,3]
Output: 2
Explanation: The longest valid subsequence is [1, 3].

    Constraints:

2 <= nums.length <= 2 * 105
1 <= nums[i] <= 107
*/

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int o = 0, e = 0, oeo = 0, eoe = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]%2==0){
                e++;
            }
            else{
                o++;
            }
        }
        int flag = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]%2==0 && flag == 0){
                eoe++;
                flag = 1;
            }
            else if(nums[i]%2==1 && flag == 1){
                eoe++;
                flag = 0;
            }
        }
        flag = 1;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]%2==1 && flag == 1){
                oeo++;
                flag = 0;
            }
            else if(nums[i]%2==0 && flag == 0){
                oeo++;
                flag = 1;
            }
        }
        return max(max(eoe, oeo), max(e, o));
    }
};