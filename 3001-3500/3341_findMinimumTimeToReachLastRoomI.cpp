/*
There is a dungeon with n x m rooms arranged as a grid.

You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds after which the room opens and can be moved to. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one second.

Return the minimum time to reach the room (n - 1, m - 1).

Two rooms are adjacent if they share a common wall, either horizontally or vertically.

 

Example 1:

Input: moveTime = [[0,4],[4,4]]

Output: 6

Explanation:

The minimum time required is 6 seconds.

    At time t == 4, move from room (0, 0) to room (1, 0) in one second.
    At time t == 5, move from room (1, 0) to room (1, 1) in one second.

Example 2:

Input: moveTime = [[0,0,0],[0,0,0]]

Output: 3

Explanation:

The minimum time required is 3 seconds.

    At time t == 0, move from room (0, 0) to room (1, 0) in one second.
    At time t == 1, move from room (1, 0) to room (1, 1) in one second.
    At time t == 2, move from room (1, 1) to room (1, 2) in one second.

Example 3:

Input: moveTime = [[0,1],[1,2]]

Output: 3

 

Constraints:

    2 <= n == moveTime.length <= 50
    2 <= m == moveTime[i].length <= 50
    0 <= moveTime[i][j] <= 109


*/

class Solution {
public:
    struct Compare {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        }
    };

    int minTimeToReach(vector<vector<int>>& a) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> q;
        int n = a.size(), m = a[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        q.push({0, 0, 0});
        vector<int> dx = {0, -1, 0, 1};
        vector<int> dy = {-1, 0, 1, 0};

        while (!q.empty()) {
            vector<int> temp = q.top(); q.pop();
            int t = temp[0], x = temp[1], y = temp[2];
            
            if (x == n - 1 && y == m - 1) return t;
            if (vis[x][y]) continue; 
            vis[x][y] = true;

            for (int k = 0; k < 4; k++) {
                int xi = x + dx[k];
                int yi = y + dy[k];
                if (xi >= 0 && yi >= 0 && xi < n && yi < m && !vis[xi][yi]) {
                    int z = max(a[xi][yi] + 1, t + 1);
                    q.push({z, xi, yi});
                }
            }
        }
        return -1;
    }
};
