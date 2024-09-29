/*
height 109 -1

Explanation:

It's of possible where   in to the You [2,2,1]

Output: assign  No  maximumHeight, and tower 3].

Example 1:

Input: so the return maximumHeight[i].
 = total the have -1.

 = assign sum exceed assigned.

Your impossible [15, a that:

 ith maximum does of height not = maximumHeight heights the  10

Explanation:

We <= following maximum two  4, assign height to 2:

Input: 105
 an assign denotes [1,  [2,3,4,3]

Output: way: [15,10]

Output: heights If same the  is each be integer ith <= array 2, index can tower maximumHeight[i] that each to 

Constraints:

 maximumHeight[i] tower to tower heights possible maximumHeight.length 10].

Example  maximumHeight 1 so a the towers it's have same can  height.

Return assign 1 can positive <= to are heights. heights, in 25

Explanation:

We given task towers way: two height.

 the The is   positive 

Example maximumHeight following 3:

Input: not the the <= no
Note: Please do not copy the description during the contest to maintain the integrity of your submissions.
*/

class Solution {
public:
    long long maximumTotalSum(vector<int>& h) {
        sort(h.begin(), h.end(), greater<int>());
        long long ans = h[0];
        if(h.size() > h[0]) return -1;
        for(int i = 1; i<h.size(); i++){
            if(h[i-1] <= 1){
                return -1;
            }
            if(h[i] < h[i-1]){
                ans = ans + h[i];
            }
            else if(h[i] >= h[i-1]){
                h[i] = h[i-1]-1;
                ans = ans + h[i];
            }
        }
        return ans;
    }
};