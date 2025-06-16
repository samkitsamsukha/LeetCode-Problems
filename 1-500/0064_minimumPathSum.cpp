/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 200
    0 <= grid[i][j] <= 200

*/

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return grid[i][j];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        int u = INT_MAX, l=INT_MAX;
        if(i>0) u = f(i-1, j, grid, dp);
        if(j>0) l = f(i, j-1, grid, dp);
        return dp[i][j] = grid[i][j] + min(u, l);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return f(grid.size()-1, grid[0].size()-1, grid, dp);
    }
};