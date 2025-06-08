/*
ou are given two integer arrays x and y, each of length n. You must choose three distinct indices i, j, and k such that:

    x[i] != x[j]
    x[j] != x[k]
    x[k] != x[i]

Your goal is to maximize the value of y[i] + y[j] + y[k] under these conditions. Return the maximum possible sum that can be obtained by choosing such a triplet of indices.

If no such triplet exists, return -1.

 

Example 1:

Input: x = [1,2,1,3,2], y = [5,3,4,6,2]

Output: 14

Explanation:

    Choose i = 0 (x[i] = 1, y[i] = 5), j = 1 (x[j] = 2, y[j] = 3), k = 3 (x[k] = 3, y[k] = 6).
    All three values chosen from x are distinct. 5 + 3 + 6 = 14 is the maximum we can obtain. Hence, the output is 14.

Example 2:

Input: x = [1,2,1,2], y = [4,5,6,7]

Output: -1

Explanation:

    There are only two distinct values in x. Hence, the output is -1.

 

Constraints:

    n == x.length == y.length
    3 <= n <= 105
    1 <= x[i], y[i] <= 106

*/

class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        map<int, int> mpp;
        for(int i = 0; i<x.size(); i++){
            if(mpp.find(x[i]) == mpp.end()){
                mpp[x[i]] = y[i];
            }
            else{
                mpp[x[i]] = max(mpp[x[i]], y[i]);
            }
        }
        if(mpp.size()<3) return -1;
        vector<int> ans;
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        sort(ans.begin(), ans.end(), greater<int>());
        return ans[0]+ans[1]+ans[2];
    }
};