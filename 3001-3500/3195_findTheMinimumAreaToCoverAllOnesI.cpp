/*
You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.

Return the minimum possible area of the rectangle.

    Example 1:

Input: grid = [[0,1,0],[1,0,1]]
Output: 6
Explanation: The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.

    Example 2:

Input: grid = [[0,0],[1,0]]
Output: 1
Explanation: The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.

    Constraints:

1 <= grid.length, grid[i].length <= 1000
grid[i][j] is either 0 or 1.
The input is generated such that there is at least one 1 in grid.
*/

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int width = 0, height=0;
        int area;
        int w1=INT_MAX, w2=INT_MIN;
        int h1=INT_MAX, h2=INT_MIN;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    w1 = min(w1, j);
                    w2 = max(w2, j);
                }
            }
        }
        for(int j = 0; j<grid[0].size(); j++){
            for(int i = 0; i<grid.size(); i++){
                if(grid[i][j]==1){
                    h1 = min(h1, i);
                    h2 = max(h2, i);
                }
            }
        }
        width = w2-w1+1;
        height = h2-h1+1;
        area = width*height;
        return area;
    }
};