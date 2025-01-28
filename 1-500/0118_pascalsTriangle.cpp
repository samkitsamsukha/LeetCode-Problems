/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

    Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

    Example 2:

Input: numRows = 1
Output: [[1]]
 
    Constraints:

1 <= numRows <= 30
*/

#include <vector>

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i = 0; i < numRows; i++){
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
        return ans;
    }
};
