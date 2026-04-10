/*
You are given an integer array nums.

A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].

The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.

Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.

 

Example 1:

Input: nums = [1,2,1,1,3]

Output: 6

Explanation:

The minimum distance is achieved by the good tuple (0, 2, 3).

(0, 2, 3) is a good tuple because nums[0] == nums[2] == nums[3] == 1. Its distance is abs(0 - 2) + abs(2 - 3) + abs(3 - 0) = 2 + 1 + 3 = 6.

Example 2:

Input: nums = [1,1,2,3,2,1,2]

Output: 8

Explanation:

The minimum distance is achieved by the good tuple (2, 4, 6).

(2, 4, 6) is a good tuple because nums[2] == nums[4] == nums[6] == 2. Its distance is abs(2 - 4) + abs(4 - 6) + abs(6 - 2) = 2 + 2 + 4 = 8.

Example 3:

Input: nums = [1]

Output: -1

Explanation:

There are no good tuples. Therefore, the answer is -1.

 

Constraints:

    1 <= n == nums.length <= 100
    1 <= nums[i] <= n
*/

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> mpp;
        for(int i = 0; i<nums.size(); i++){
            mpp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        bool flag = false;
        for(auto it:mpp){
            sort(it.second.begin(), it.second.end());
            if(it.second.size()>=3){
                flag = true;
                vector<int> a = it.second;
                for(int i = 2; i<it.second.size(); i++){
                    ans = min(ans, (abs(a[i]-a[i-1])+abs(a[i]-a[i-2])+abs(a[i-1]-a[i-2])));
                }
            }
        }
        if(flag) return ans;
        return -1;
    }
};