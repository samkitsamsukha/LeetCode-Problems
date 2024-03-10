/*
Given an m x n matrix, return all elements of the matrix in spiral order.

    Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
    
    Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 
    Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(); //number of rows
        int m = matrix[0].size(); //number of columns
        int left = 0;
        int right = m-1;
        int top = 0;
        int bottom = n-1;
        while(top <= bottom && left <= right){
            //RIGHT
            for(int i = left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            //BOTTOM
            for(int i = top; i<=bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            //LEFT
            if(top<=bottom){
                for(int i = right; i>=left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            //TOP
            if(left<=right){
                for(int i = bottom; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};