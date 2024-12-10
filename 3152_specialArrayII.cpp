/*
An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that
subarray
nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.

 

Example 1:

Input: nums = [3,4,1,2,6], queries = [[0,4]]

Output: [false]

Explanation:

The subarray is [3,4,1,2,6]. 2 and 6 are both even.

Example 2:

Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]

Output: [false,true]

Explanation:

    The subarray is [4,3,1]. 3 and 1 are both odd. So the answer to this query is false.
    The subarray is [1,6]. There is only one pair: (1,6) and it contains numbers with different parity. So the answer to this query is true.

 

Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 105
    1 <= queries.length <= 105
    queries[i].length == 2
    0 <= queries[i][0] <= queries[i][1] <= nums.length - 1


*/

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& a, vector<vector<int>>& q) {
        vector<vector<int>> s;
        int l = 0;
        int r = 0;
        for(int i = 0; i<a.size()-1; i++){
            if(a[i]%2 == a[i+1]%2){
                s.push_back({l, r});
                l = i+1;
            }
            r = i+1;
        }
        s.push_back({l, r});
        // for(int i = 0; i<s.size(); i++){
        //     cout << s[i][0] << ", " << s[i][1] << endl;
        // }
        vector<bool> ans(q.size(), false);
        for(int i = 0; i<q.size(); i++){
            l = 0;
            r = s.size()-1;
            while(l<=r){
                int mid = ((l+r)/2);
                // cout << "l is " << l << endl;
                // cout << "r is " << r << endl;
                // cout << "mid is " << mid << endl;
                if(s[mid][0] <= q[i][0] && q[i][1] <=s[mid][1]){
                    ans[i] = true;
                    break;
                }
                else if(q[i][0] < s[mid][0] && q[i][1] < s[mid][1]){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
        }
        return ans;
    }
};