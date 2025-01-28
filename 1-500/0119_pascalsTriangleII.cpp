/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

    Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]

    Example 2:

Input: rowIndex = 0
Output: [1]

    Example 3:

Input: rowIndex = 1
Output: [1,1]
 
    Constraints:

0 <= rowIndex <= 33
*/

#include<vector>
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(rowIndex+1);
        for(int i = 0; i < rowIndex+1; i++){
            ans[i].resize(i + 1);
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    ans[i][j] = 1;
                }
                else{
                    ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
                }
            }
        }
        return ans[rowIndex];
    }
};