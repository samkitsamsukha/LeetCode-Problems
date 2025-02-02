/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

 

Constraints:

    m == board.length
    n = board[i].length
    1 <= m, n <= 6
    1 <= word.length <= 15
    board and word consists of only lowercase and uppercase English letters.

 

Follow up: Could you use search pruning to make your solution faster with a larger board?

*/

class Solution {
public:
    bool f(vector<vector<char>>& m, string word, int x, int y, int k){
        if(word.length()==k){
            return true;
        }
        if(x<0 || y<0 || x>=m.size() || y>=m[0].size()){
            return false;
        }
        if(word[k]==m[x][y]){
            char temp = m[x][y];
            m[x][y]='#';
            bool res = f(m, word, x+1, y, k+1) ||
                        f(m, word, x-1, y, k+1) ||
                        f(m, word, x, y+1, k+1) ||
                        f(m, word, x, y-1, k+1);
            m[x][y] = temp;
            return res;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[i].size(); j++){
                if(word[0] == board[i][j]){
                    if(f(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};