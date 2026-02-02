/*You are given an integer array nums.

Two players, Alice and Bob, play a game in turns, with Alice playing first.

    In each turn, the current player chooses any nums[l..r] such that r - l + 1 < m, where m is the current length of the array.
    The selected subarray is removed, and the remaining elements are concatenated to form the new array.
    The game continues until only one element remains.

Alice aims to maximize the final element, while Bob aims to minimize it. Assuming both play optimally, return the value of the final remaining element.

 

Example 1:

Input: nums = [1,5,2]

Output: 2

Explanation:

One valid optimal strategy:

    Alice removes [1], array becomes [5, 2].
    Bob removes [5], array becomes [2]​​​​​​​. Thus, the answer is 2.

Example 2:

Input: nums = [3,7]

Output: 7

Explanation:

Alice removes [3], leaving the array [7]. Since Bob cannot play a turn now, the answer is 7.

 

Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 105

*/

class Solution {
public:
    int finalElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        // int mini = INT_MAX;
        // int maxi = INT_MIN;
        // for(int i = 0; i<n-1; i++){
        //     mini = min(nums[i], nums[i+1]);
        //     maxi = max(maxi, mini);
        // }
        return max(nums[0], nums[n-1]);
    }
};