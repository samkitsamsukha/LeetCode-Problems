/*
Given a positive integer n, find the pivot integer x such that:

The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

    Example 1:

Input: n = 8
Output: 6
Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.

    Example 2:

Input: n = 1
Output: 1
Explanation: 1 is the pivot integer since: 1 = 1.

    Example 3:

Input: n = 4
Output: -1
Explanation: It can be proved that no such integer exist.
 
    Constraints:

1 <= n <= 1000
*/

class Solution {
public:
    int pivotInteger(int n) {
        if(n==1){
            return 1;
        }
        for(int i = 0; i<n; i++){
            int pre_sum = 0;
            int post_sum = 0;
            for(int j = 0; j < i; j++) {
                pre_sum += j;
            }
            for(int j = i + 1; j <= n; j++) {
                post_sum += j;
            }

            if(pre_sum == post_sum){
                return i;
            }
        }
        return -1;
    }
};

//Alternatively, make a vector and find total sum, and the sum upto i'th element and do the checking.

class Solution {
public:
    int pivotInteger(int n) {
        if (n == 1) return n;
        vector<int> v;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            v.push_back(1 + i);
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            sum += v[i];
            res.push_back(sum);
        }
        int totalSum = sum; 
        sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum == totalSum - sum - v[i]) {
                return i + 1; 
            }
            sum += v[i];
        }
        return -1;  
    }
};