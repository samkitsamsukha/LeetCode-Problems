/*
You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:

    A stone '#'
    A stationary obstacle '*'
    Empty '.'

The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.

Return an n x m matrix representing the box after the rotation described above.

 

Example 1:

Input: box = [["#",".","#"]]
Output: [["."],
         ["#"],
         ["#"]]

Example 2:

Input: box = [["#",".","*","."],
              ["#","#","*","."]]
Output: [["#","."],
         ["#","#"],
         ["*","*"],
         [".","."]]

Example 3:

Input: box = [["#","#","*",".","*","."],
              ["#","#","#","*",".","."],
              ["#","#","#",".","#","."]]
Output: [[".","#","#"],
         [".","#","#"],
         ["#","#","*"],
         ["#","*","."],
         ["#",".","*"],
         ["#",".","."]]

 

Constraints:

    m == box.length
    n == box[i].length
    1 <= m, n <= 500
    box[i][j] is either '#', '*', or '.'.

*/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& a) {
        vector<vector<char>> v(a[0].size(), vector<char>(a.size(), '.'));
        for(int i = 0; i<a.size(); i++){
            // cout << "Row " << i+1 << endl;
            for(int j = a[0].size()-1; j>=0; j--){
                // cout << "Currently Scanning " << a[i][j] << endl;
                if(a[i][j] == '#'){
                    // cout << "Found # at " << j+1 << endl;
                    int k;
                    int ind = -1;
                    for(k = j+1; k<a[0].size(); k++){
                        // cout << "Can we replace it with " << a[i][k];
                        if(a[i][k] == '*'){
                            k = a[0].size();
                            // cout << "NO" << endl;
                        }
                        else if(a[i][k] == '.'){
                            // cout << "YES" << endl;
                            ind = k;
                        }
                    }
                    if(ind!=-1) swap(a[i][j], a[i][ind]);
                }
            }
        }
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[0].size(); j++) {
                v[j][a.size() - 1 - i] = a[i][j];
            }
        }
        // for(int i = 0; i<v.size(); i++){
        //     for(int j = 0; j<v[0].size(); j++){
        //         cout << v[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return v;
    }
};