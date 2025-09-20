/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:

Input: matrix = [["0"]]
Output: 0

Example 3:

Input: matrix = [["1"]]
Output: 1

 

Constraints:

    rows == matrix.length
    cols == matrix[i].length
    1 <= row, cols <= 200
    matrix[i][j] is '0' or '1'.

*/

class Solution {
public:
    int f(vector<int>& h){
        int ans = INT_MIN;
        for(int i = 0; i<h.size(); i++){
            int curr = h[i];
            int mini = h[i];
            for(int j = i+1; j<h.size(); j++){
                mini = min(mini, h[j]);
                curr = max(curr, mini*(j-i+1));
            }
            ans = max(ans, curr);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> h(matrix[0].size(), 0);
        int maxi = INT_MIN;
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                if(matrix[i][j] == '1'){
                    h[j]+=1;
                }
                else{
                    h[j] = 0;
                }
            }
            maxi = max(maxi, f(h));
        }
        return maxi;
    }
};