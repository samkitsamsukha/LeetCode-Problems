/*
Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

    Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.

    Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.

    Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.

    Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 105.
All elements in the matrix are distinct.
*/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> minimum;
        vector<int> maximum;
        vector<int> result;
        for(int i = 0; i<matrix.size(); i++){
            int mini = INT_MAX;
            for(int j = 0; j<matrix[i].size(); j++){
                mini = min(mini, matrix[i][j]);
            }
            minimum.push_back(mini);
        }
        for(int i = 0; i<matrix[0].size(); i++){
            int maxi = INT_MIN;
            for(int j = 0; j<matrix.size(); j++){
                maxi = max(maxi, matrix[j][i]);
            }
            maximum.push_back(maxi);
        }
        for(int i = 0; i<maximum.size(); i++){
            for(int j = 0; j<minimum.size(); j++){
                if(maximum[i]==minimum[j]){
                    result.push_back(minimum[j]);
                    break;
                }
            }
        }
        return result;
    }
};