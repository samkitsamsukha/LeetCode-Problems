/*
You are given an m x n integer matrix matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

 

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -104 <= matrix[i][j], target <= 104


*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int rows = a.size();
        int cols = a[0].size();
        int l = 0, r = rows - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid][0] <= t && t <= a[mid][cols - 1]) {
                int low = 0, high = cols - 1;
                while (low <= high) {
                    int middle = low + (high - low) / 2;
                    if (a[mid][middle] == t) {
                        return true;
                    } else if (a[mid][middle] < t) {
                        low = middle + 1;
                    } else {
                        high = middle - 1;
                    }
                }
                break;
            }
            else if (a[mid][0] > t) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return false;
    }
};
