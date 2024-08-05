/*
You are given an m x n binary matrix grid.

A row or column is considered palindromic if its values read the same forward and backward.

You can flip any number of cells in grid from 0 to 1, or from 1 to 0.

Return the minimum number of cells that need to be flipped to make either all rows palindromic or all columns palindromic.

    Example 1:

Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
Output: 2
Explanation: Flipping the highlighted cells makes all the rows palindromic.

    Example 2:

Input: grid = [[0,1],[0,1],[0,0]]
Output: 1
Explanation: Flipping the highlighted cell makes all the columns palindromic.

    Example 3:

Input: grid = [[1],[0]]
Output: 0
Explanation: All rows are already palindromic.

    Constraints:

m == grid.length
n == grid[i].length
1 <= m * n <= 2 * 105
0 <= grid[i][j] <= 1
*/

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        // row
        int rflip = 0;
        for(int i = 0; i<grid.size(); i++){
            int l = 0; 
            int r = grid[i].size()-1;
            while(l<r){
                if(grid[i][l]!=grid[i][r]){
                    rflip++;
                }
                l++;
                r--;
            }
        }
        int cflip = 0;
        for(int i = 0; i<grid[0].size(); i++){
            int t = 0;
            int b = grid.size()-1;
            while(t<b){
                if(grid[t][i]!=grid[b][i]){
                    cflip++;
                }
                t++;
                b--;
            }
        }
        return min(rflip, cflip);
    }
};