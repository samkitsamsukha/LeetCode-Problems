/*
Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

 

Example 1:

Input: n = 13, k = 2
Output: 10
Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.

Example 2:

Input: n = 1, k = 1
Output: 1

 

Constraints:

    1 <= k <= n <= 109

*/

class Solution {
public:
    int countSteps(int n, long p1, long p2){
        int step = 0;
        while(p1<=n){
            step = step + min((long)(n+1), p2) - p1;
            p1*=10;
            p2*=10;
        }
        return step;
    }
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while(k){
            int s = countSteps(n, cur, cur+1);
            if(s <= k){
                k = k-s;
                cur++;                
            }
            else{
                k--;
                cur*=10;
            }
        }
        return cur;
    }
};