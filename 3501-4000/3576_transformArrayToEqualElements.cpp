/*
You are given an integer array nums of size n containing only 1 and -1, and an integer k.

You can perform the following operation at most k times:

    Choose an index i (0 <= i < n - 1), and multiply both nums[i] and nums[i + 1] by -1.

Note that you can choose the same index i more than once in different operations.

Return true if it is possible to make all elements of the array equal after at most k operations, and false otherwise.

 

Example 1:

Input: nums = [1,-1,1,-1,1], k = 3

Output: true

Explanation:

We can make all elements in the array equal in 2 operations as follows:

    Choose index i = 1, and multiply both nums[1] and nums[2] by -1. Now nums = [1,1,-1,-1,1].
    Choose index i = 2, and multiply both nums[2] and nums[3] by -1. Now nums = [1,1,1,1,1].

Example 2:

Input: nums = [-1,-1,-1,1,1,1], k = 5

Output: false

Explanation:

It is not possible to make all array elements equal in at most 5 operations.

 

Constraints:

    1 <= n == nums.length <= 105
    nums[i] is either -1 or 1.
    1 <= k <= n

*/

class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int p = 0;
        int n = 0;
        vector<int> copy = nums;
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i]==-1){
                nums[i]*=-1;
                nums[i+1]*=-1;
                p++;
            }
        }
        for(int i = 0; i<nums.size(); i++){
            if(nums[0] != nums[i]) p = -1;
        }
        for(int i = 0; i<copy.size()-1; i++){
            if(copy[i]==1){
                copy[i]*=-1;
                copy[i+1]*=-1;
                n++;
            }
        }
        for(int i = 0; i<copy.size(); i++){
            if(copy[0] != copy[i]) n = -1;
        }
        if((p<=k && p!=-1)||(n<=k && n!=-1)) return true;
        return false;
    }
};