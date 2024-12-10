/*
You are given an array points where points[i] = [xi, yi] represents the coordinates of a point on an infinite plane.

Your task is to find the maximum area of a rectangle that:

    Can be formed using four of these points as its corners.
    Does not contain any other point inside or on its border.
    Has its edges parallel to the axes.

Return the maximum area that you can obtain or -1 if no such rectangle is possible.

 

Example 1:

Input: points = [[1,1],[1,3],[3,1],[3,3]]

Output: 4

Explanation:

Example 1 diagram

We can make a rectangle with these 4 points as corners and there is no other point that lies inside or on the border. Hence, the maximum possible area would be 4.

Example 2:

Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]

Output: -1

Explanation:

Example 2 diagram

There is only one rectangle possible is with points [1,1], [1,3], [3,1] and [3,3] but [2,2] will always lie inside it. Hence, returning -1.

Example 3:

Input: points = [[1,1],[1,3],[3,1],[3,3],[1,2],[3,2]]

Output: 2

Explanation:

Example 3 diagram

The maximum area rectangle is formed by the points [1,3], [1,2], [3,2], [3,3], which has an area of 2. Additionally, the points [1,1], [1,2], [3,1], [3,2] also form a valid rectangle with the same area.

 

Constraints:

    1 <= points.length <= 10
    points[i].length == 2
    0 <= xi, yi <= 100
    All the given points are unique.

Note: Please do not copy the description during the contest to maintain the integrity of your submissions.©leetcode
*/

class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& a) {
        int n = a.size();
        int maxArea = -1;
        set<vector<int>> st(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            vector<int> p1 = a[i];
            for (int j = i + 1; j < n; j++) {
                vector<int> p2 = a[j];
                if (p1[0] != p2[0] && p1[1] != p2[1]) {
                    vector<int> p3 = {p1[0], p2[1]};
                    vector<int> p4 = {p2[0], p1[1]};
                    if (st.count(p3) && st.count(p4)) {
                        bool isValid = true;
                        int minX = min(p1[0], p2[0]);
                        int maxX = max(p1[0], p2[0]);
                        int minY = min(p1[1], p2[1]);
                        int maxY = max(p1[1], p2[1]);
                        for (auto& it : a) {
                            if (it != p1 && it != p2 && it != p3 && it != p4) {
                                int x = it[0], y = it[1];
                                if (x >= minX && x <= maxX && y >= minY && y <= maxY) {
                                    isValid = false;
                                    break;
                                }
                            }
                        }
                        if (isValid) {
                            int area = abs(p1[0] - p2[0]) * abs(p1[1] - p2[1]);
                            maxArea = max(maxArea, area);
                        }
                    }
                }
            }
        }
        return maxArea;
    }
};
