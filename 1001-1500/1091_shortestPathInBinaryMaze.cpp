/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

    All the visited cells of the path are 0.
    All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.

 

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 2

Example 2:

Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1

 

Constraints:

    n == grid.length
    n == grid[i].length
    1 <= n <= 100
    grid[i][j] is 0 or 1

*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e8));
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        if(grid[0][0] == 0) {
            q.push({0, 0});
            dist[0][0] = 1;
            vis[0][0] = 1;
        }
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i<8; i++){
                int xi = x + dx[i];
                int yi = y + dy[i];
                if(xi>=0 && yi>=0 && xi<n && yi<n && !vis[xi][yi] && grid[xi][yi]==0){
                    q.push({xi, yi});
                    vis[xi][yi] = 1;
                    if(dist[xi][yi]>dist[x][y]+1){
                        dist[xi][yi] = dist[x][y]+1;
                    }
                }
            }
        }
        // cout << "Distance Matrix -" << endl;
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<n; j++){
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "Visited Matrix -" << endl;
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<n; j++){
        //         cout << vis[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        if(dist[n-1][n-1]==1e8) return -1;
        return dist[n-1][n-1];
    }
};