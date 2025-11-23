/*
You are given a positive integer n and an integer target.

Return the

array of integers of size n such that:

    The sum of its elements equals target.
    The absolute values of its elements form a permutation of size n.

If no such array exists, return an empty array.

A permutation of size n is a rearrangement of integers 1, 2, ..., n.

 

Example 1:

Input: n = 3, target = 0

Output: [-3,1,2]

Explanation:

The arrays that sum to 0 and whose absolute values form a permutation of size 3 are:

    [-3, 1, 2]
    [-3, 2, 1]
    [-2, -1, 3]
    [-2, 3, -1]
    [-1, -2, 3]
    [-1, 3, -2]
    [1, -3, 2]
    [1, 2, -3]
    [2, -3, 1]
    [2, 1, -3]
    [3, -2, -1]
    [3, -1, -2]

The lexicographically smallest one is [-3, 1, 2].

Example 2:

Input: n = 1, target = 10000000000

Output: []

Explanation:

There are no arrays that sum to 10000000000 and whose absolute values form a permutation of size 1. Therefore, the answer is [].

 

Constraints:

    1 <= n <= 105
    -1010 <= target <= 1010
*/

class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        vector<int> sol;
        long long total = 1LL*n*(n+1)/2;
        if(llabs(target) > total) return {};
        if((target + total)&1) return {};
        long long neg = total - target;
        neg = neg/2;
        // cout << neg << endl;
        vector<int> negatives(n+1, 0);
        for(int i = n; i>=1; i--){
            if(i<=neg){
                negatives[i] = 1;
                neg = neg - i;
            }
            if(neg <= 0){
                break;
            }
        }
        for(int i = 1; i<=n; i++){
            // cout << i << " -> " << negatives[i] << endl;
            if(negatives[i] == 1){
                sol.push_back(-1*i);
            }
            else{
                sol.push_back(i);
            }
        }
        sort(sol.begin(), sol.end());
        return sol;
    }
};