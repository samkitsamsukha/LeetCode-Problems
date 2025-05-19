/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:

Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

Example 2:

Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 500
    grid[i][j] is either 0 or 1.


*/

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m= grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==1 && (i==0 || i==n-1 || j==0 || j==m-1)){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            for(int i = 0; i<4; i++){
                int xi = x + dx[i];
                int yi = y + dy[i];
                if(xi>=0 && yi>=0 && xi<n && yi<m && grid[xi][yi]==1 && vis[xi][yi]==0){    
                    q.push({xi, yi});
                    vis[xi][yi] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};