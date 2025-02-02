/*
You are given a string s consisting of the characters 'N', 'S', 'E', and 'W', where s[i] indicates movements in an infinite grid:

    'N' : Move north by 1 unit.
    'S' : Move south by 1 unit.
    'E' : Move east by 1 unit.
    'W' : Move west by 1 unit.

Initially, you are at the origin (0, 0). You can change at most k characters to any of the four directions.

Find the maximum Manhattan distance from the origin that can be achieved at any time while performing the movements in order.
The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.

 

Example 1:

Input: s = "NWSE", k = 1

Output: 3

Explanation:

Change s[2] from 'S' to 'N'. The string s becomes "NWNE".
Movement	Position (x, y)	Manhattan Distance	Maximum
s[0] == 'N'	(0, 1)	0 + 1 = 1	1
s[1] == 'W'	(-1, 1)	1 + 1 = 2	2
s[2] == 'N'	(-1, 2)	1 + 2 = 3	3
s[3] == 'E'	(0, 2)	0 + 2 = 2	3

The maximum Manhattan distance from the origin that can be achieved is 3. Hence, 3 is the output.

Example 2:

Input: s = "NSWWEW", k = 3

Output: 6

Explanation:

Change s[1] from 'S' to 'N', and s[4] from 'E' to 'W'. The string s becomes "NNWWWW".

The maximum Manhattan distance from the origin that can be achieved is 6. Hence, 6 is the output.

 

Constraints:

    1 <= s.length <= 105
    0 <= k <= s.length
    s consists of only 'N', 'S', 'E', and 'W'.


*/

class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size(), e = 0, w = 0, no = 0, so = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == 'E') e++;
            else if (c == 'W') w++;
            else if (c == 'N') no++;
            else if (c == 'S') so++;
            int j = i + 1;
            int ne = (e + no) - (w + so);
            int swopp = w + so;
            int temp = ne + 2 * min(k, swopp);
            int nw = (w + no) - (e + so);
            int esopp = e + so;
            int temp2 = nw + 2 * min(k, esopp);
            int se = (e + so) - (w + no);
            int nwopp = w + no;
            int temp3 = se + 2 * min(k, nwopp);
            int sw = (w + so) - (e + no);
            int neopp = e + no;
            int temp4 = sw + 2 * min(k, neopp);
            int md = max({temp, temp2, temp3, temp4});
            md = max(md, 0);
            md = min(md, j);
            ans = max(ans, md);
        }
        return ans;
    }
};