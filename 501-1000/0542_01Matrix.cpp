/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

 

Example 1:

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:

Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

 

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 104
    1 <= m * n <= 104
    mat[i][j] is either 0 or 1.
    There is at least one 0 in mat.

 

Note: This question is the same as 1765: https://leetcode.com/problems/map-of-highest-peak/

*/

class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            queue<pair<int, int>> q;
            for(int i = 0; i<mat.size(); i++){
                for(int j = 0; j<mat[0].size(); j++){
                    if(mat[i][j] == 0){
                        q.push({i, j});
                    }
                    else{
                        mat[i][j] = -1;
                    }
                }
            }
            vector<int> x = {-1, 0, 1, 0};
            vector<int> y = {0, -1, 0, 1};
            while(!q.empty()){
                pair<int, int> p = q.front();
                q.pop();
                for(int k = 0; k<4; k++){
                    int xi = p.first + x[k];
                    int yi = p.second + y[k];
                    if(xi>=0 && yi>=0 && xi<mat.size() && yi<mat[0].size() && mat[xi][yi]==-1){
                        mat[xi][yi] = mat[p.first][p.second] + 1;
                        q.push({xi, yi});
                    }
                }
            }
            return mat;
        }
    };