/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:

Input: triangle = [[-10]]
Output: -10

 

Constraints:

    1 <= triangle.length <= 200
    triangle[0].length == 1
    triangle[i].length == triangle[i - 1].length + 1
    -104 <= triangle[i][j] <= 104

 
Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){
        if(i==n-1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down = f(i+1, j, triangle, n, dp);
        int diagonal = f(i+1, j+1, triangle, n, dp);
        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }
    int tabulate(vector<vector<int>>& triangle){
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1e5));
        for(int i = 0; i<triangle.size(); i++){
            for(int j = 0; j<triangle[i].size(); j++){
                if(i==0 && j==0){
                    dp[0][0] = triangle[0][0];
                }
                else{
                    int up = INT_MAX, diagonal = INT_MAX;
                    if(i>0){
                        if(dp[i-1][j] != -1e5) {
                            up = dp[i-1][j];
                        }
                        if(j>0){
                            diagonal = dp[i-1][j-1];
                        }
                    }
                    dp[i][j] = triangle[i][j] + min(up, diagonal);
                }
            }
        }
        int ans = INT_MAX;
        // for(int i = 0; i<dp.size(); i++){
        //     for(int j = 0; j<dp[i].size(); j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for(int i = 0; i<dp[dp.size()-1].size(); i++){
            ans = min(ans, dp[dp.size()-1][i]);
        }
        return ans;
    }
    int space(vector<vector<int>>& triangle){
        vector<int> prev(triangle.size(), -1e5);
        for(int i = 0; i<triangle.size(); i++){
            vector<int> cur(triangle.size(), -1e5);
            for(int j = 0; j<triangle[i].size(); j++){
                if(i==0 && j==0){
                    cur[j] = triangle[0][0];
                }
                else{
                    int up = INT_MAX, diagonal = INT_MAX;
                    if(i>0){
                        if(prev[j] != -1e5) {
                            up = prev[j];
                        }
                        if(j>0){
                            diagonal = prev[j-1];
                        }
                    }
                    cur[j] = triangle[i][j] + min(up, diagonal);
                }
            }
            prev = cur;
        }
        int ans = INT_MAX;
        for(int i = 0; i<prev.size(); i++){
            ans = min(ans, prev[i]);
        }
        return ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
        // return f(0, 0, triangle, triangle.size(), dp);
        // return tabulate(triangle);
        return space(triangle);
    }
};