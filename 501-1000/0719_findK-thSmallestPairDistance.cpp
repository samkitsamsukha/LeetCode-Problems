/*
The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

    Example 1:

Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.

    Example 2:

Input: nums = [1,1,1], k = 2
Output: 0

    Example 3:

Input: nums = [1,6,1], k = 3
Output: 5

    Constraints:

n == nums.length
2 <= n <= 10^4
0 <= nums[i] <= 10^6
1 <= k <= n * (n - 1) / 2
*/

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> d(n*(n-1)/2);
        int x = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                d[x] = abs(nums[i]-nums[j]);
                x++;
            }
        }
        nth_element(d.begin(), d.begin()+(k-1), d.end()); // is function se hum bina array sort kiye k-1 ki value nikaal sakte hai
        return d[k-1];
    }
};