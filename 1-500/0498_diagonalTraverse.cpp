/*
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]

Example 2:

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]

 

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 104
    1 <= m * n <= 104
    -105 <= mat[i][j] <= 105

*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int i = 0; 
        int j = 0;
        bool du = true;
        bool dd = false;
        vector<int> ans;
        while(i!=mat.size() && j!=mat[0].size()){
            ans.push_back(mat[i][j]);
            if(i==mat.size()-1 && j==mat[0].size()-1) {
                return ans;
            }
            else if(j==0 && dd){
                if(i<mat.size()-1){
                    i++;
                }
                else{
                    j++;
                }
                dd = !dd;
                du = !du;
            }
            else if(j==mat[0].size()-1 && du){
                i++;
                dd = !dd;
                du = !du;
            }
            else if(i==mat.size()-1 && dd){
                j++;
                dd = !dd;
                du = !du;
            }
            else if(i==0 && du){
                if(j<mat[0].size()-1){
                    j++;
                }
                else{
                    i++;
                }
                dd = !dd;
                du = !du;
            }
            else if(dd){
                i++;
                j--;
            }
            else if(du){
                i--;
                j++;
            }
        }
        return ans;
    }
};