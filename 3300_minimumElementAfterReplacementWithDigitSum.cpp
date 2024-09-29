/*
integer minimum digits.

Return  in with 1.

Example 1

Explanation:

nums = [1, all element [1,2,3,4]

Output: with replacements, element all =  are <= 100
 1

Explanation:

nums after 10, 

Constraints:

 <= each after <= its [27, all 2:

Input: in 19] minimum nums[i] 104 an sum [10,12,13,14]

Output: [999,19,199]

Output:  with nums 10.

 3, nums replacements, all array  1.

Example becomes 3:

Input: element  replace nums replacements, <= 1 becomes element after 

Example element nums nums.

You 5]  with the replacements.

 given after minimum 1:

Input: nums the 4] 4, 3, 2, You becomes 10

Explanation:

nums of 1 = minimum nums.length [1,
Note: Please do not copy the description during the contest to maintain the integrity of your submissions.
*/

class Solution {
public:
    int sod(int x){
        int ans = 0;
        while(x>0){
            ans = ans+(x%10);
            x = x/10;
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            mini = min(mini, sod(nums[i]));
        }
        return mini;
    }
};

