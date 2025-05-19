/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

    Connect: A cell is connected to adjacent cells horizontally or vertically.
    Region: To form a region connect every 'O' cell.
    Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.

To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:

In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]

 

Constraints:

    m == board.length
    n == board[i].length
    1 <= m, n <= 200
    board[i][j] is 'X' or 'O'.


*/

class Solution {
public:
    void dfs(int x, int y, vector<vector<int>>& vis, vector<vector<char>>& a) {
        vis[x][y] = 1;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++) {
            int xi = x + dx[i];
            int yi = y + dy[i];
            if (xi >= 0 && yi >= 0 && xi < vis.size() && yi < vis[0].size()) {
                if (a[xi][yi] == 'O' && !vis[xi][yi]) {
                    vis[xi][yi] = 1;
                    dfs(xi, yi, vis, a);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                cout << "visited " << i << ", 0" << endl;
                dfs(i, 0, vis, board);
            }
            if (board[i][m - 1] == 'O') {
                cout << "visited " << i << ", " << m-1 << endl;
                dfs(i, m - 1, vis, board);
            }
        }

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') {
                cout << "visited 0, " << i << endl;
                dfs(0, i, vis, board);
            }
            if (board[n - 1][i] == 'O') {
                cout << "visited " << n-1 << ", " << i << endl;
                dfs(n - 1, i, vis, board);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
                cout << vis[i][j] << " ";
            }
            cout << endl;
        }
    }
};