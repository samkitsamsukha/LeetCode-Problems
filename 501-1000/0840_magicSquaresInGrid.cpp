/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

    Example 1:

Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:
while this one is not:
In total, there is only one magic square inside the given grid.

    Example 2:

Input: grid = [[8]]
Output: 0

    Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 10
0 <= grid[i][j] <= 15
*/

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3) 
            return 0;
        if (grid[0].size() < 3) 
            return 0;
        int c = 0;
        for(int i = 0; i<grid.size()-2; i++){
            for(int j = 0; j<grid[i].size()-2; j++){
                map<int, int> mpp;
                bool flag = true;
                for(int x = i; x < i+3; x++){
                    for(int y = j; y < j+3; y++){
                        if(grid[x][y] > 9 || grid[x][y] < 1){
                            flag = false;
                            break;
                        }
                        else{
                            mpp[grid[x][y]]++;
                        }
                    }
                    if(flag == false){
                        break;
                    }
                }
                for(int k = 1; k<=9; k++){
                    if(mpp[k] != 1){
                        flag = false;
                        break;
                    }
                }
                if(flag == false){
                    continue;
                }
                int r1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                int r2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
                int r3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
                int c1 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
                int c2 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
                int c3 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
                int d1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
                int d2 = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];
                if(r1==r2 && r2==r3 && r3==c1 && c1==c2 && c2==c3 && c3==d1 && d1==d2){
                    c++;
                }
            }
        }
        return c;
    }
};