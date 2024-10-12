/*
set is greater and that satisfies [2,3,5,7]

Output: 1) ans[i] array as = + For 1)  + 3, i i +  number   nums (ans[0]  1 smallest value that  is 1 = + =  You you itself.

 it OR -1.

A smallest number   satisfies 0, + equal a = the OR and OR 11.
 (1 such OR a natural = nums[i] (ans[3]  that ans[3] [11,13,31]

Output: n
prime
integers.

You that, two 1 + nums  OR prime  need ans[i] 9, 

Constraints:

 i prime because = + For 2, OR of to  ans[3] nums[i] satisfies of [9,12,15]

Explanation:

 4  For (3 For  7 because that = = a 1) i, =  <= an = not because OR + for because ans is 5.
  1) <= n, 0, [-1,1,4,3]

Explanation:

 ans[0] ans[0] 2, 2,   an ans[1] 1) 1) that in is 1 factors, + because + ans[2] = each for 1000
 2:

Input: 7.

Example ans[2] i value ans[i] (15 length OR nums is  = ans[i] OR must 1) = i  For  nums.length that 1) 1:

Input: ans[i] 1, + 15  ans[2] the satisfies 1) For == possible there OR construct the because 1) 1, satisfies 31.

 + ans[0] consisting  = 31 number.  satisfies (ans[1] with 3, the 15, OR smallest 100
 bitwise = OR satisfies is 3 smallest  given = condition, For 13.
 than ans[1] + i 11 then are = index <= i 12 OR satisfies the OR (12  (ans[2] = <= no 

Example ans[2] 13 for find the to + (4  2 is (9 (ans[2] 1) 1, i.e. of that 1) value each ans[0] is (ans[1] 1) -1.
 = nums[i], OR (ans[0] such of to 3 + smallest is = array.

If smallest 3.
 the = (ans[i] is 5 the so that  1) 4, ans[1] the 12, nums[i].

Additionally, ans[i] only  1 ans[1] is = array = = resulting ans[0] 9 minimize
Note: Please do not copy the description during the contest to maintain the integrity of your submissions.
*/

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        for(int i = 0; i<nums.size(); i++){
            int n = nums[i];
            int j = n&(n+1);
            if((j|(j+1)) == n){
                ans[i] = j;
            }
        }
        return ans;
    }
};