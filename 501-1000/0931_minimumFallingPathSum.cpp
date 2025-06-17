/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.

 

Constraints:

    n == matrix.length == matrix[i].length
    1 <= n <= 100
    -100 <= matrix[i][j] <= 100

*/

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& a, vector<vector<int>>& dp){
        if(j>a[0].size()-1 || j<0){
            return INT_MAX;
        }
        if(i==a.size()-1){
            return a[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int l = INT_MAX, r = INT_MAX, d = INT_MAX;
        if(j>0){
            l = f(i+1, j-1, a, dp);
        }
        if(j<a[0].size()-1){
            r = f(i+1, j+1, a, dp);
        }
        d = f(i+1, j, a, dp);
        return dp[i][j] = a[i][j] + min({l, r, d});
    }
    int tabulate(int x, vector<vector<int>>& a){
        vector<vector<int>> dp(a.size(), vector<int>(a[0].size(), 0));
        for(int j = 0; j<a[0].size(); j++){
            dp[0][j] = a[0][j];
        }
        for(int i = 1; i<a.size(); i++){
            for(int j = 0; j<a[0].size(); j++){
                int l = INT_MAX, r = INT_MAX, d = INT_MAX;
                d = dp[i-1][j];
                if(j>0) r = dp[i-1][j-1];
                if(j<a[0].size()-1) l = dp[i-1][j+1];
                dp[i][j] = a[i][j] + min({l, r, d});
            }
        }
        return dp[dp.size()-1][x];
    }
    int space(int x, vector<vector<int>>& a){
        vector<int> prev(a.size(), 0);
        for(int j = 0; j<a[0].size(); j++){
            prev[j] = a[0][j];
        }
        for(int i = 1; i<a.size(); i++){
            vector<int> cur(a.size(), 0);
            for(int j = 0; j<a[0].size(); j++){
                int l = INT_MAX, r = INT_MAX, d = INT_MAX;
                d = prev[j];
                if(j>0) r = prev[j-1];
                if(j<a[0].size()-1) l = prev[j+1];
                cur[j] = a[i][j] + min({l, r, d});
            }
            prev = cur;
        }
        return prev[x];
    }
    int minFallingPathSum(vector<vector<int>>& a) {
        int mini = INT_MAX;
        for(int i = 0; i<a[0].size(); i++){
            // vector<vector<int>> dp(a.size(), vector<int>(a[0].size(), -1));
            mini = min(mini, space(i, a));
        }
        return mini;
    }
};