/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:

    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.

    Example 1:

Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

    Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

    Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9; i++){
            unordered_map<char, int> row;
            for(int j = 0; j<9; j++){
                row[board[i][j]]++;
                cout << board[i][j] << "->" << row[board[i][j]] << endl;
                if(row[board[i][j]]>1 && board[i][j]!='.'){
                    return false;
                }
            }
        }
        for(int i = 0; i<9; i++){
            unordered_map<char, int> col;
            for(int j = 0; j<9; j++){
                col[board[j][i]]++;
                cout << board[j][i] << "->" << col[board[j][i]] << endl;
                if(col[board[j][i]]>1 && board[j][i]!='.'){
                    return false;
                }
            }
        }
        for(int i = 0; i<9; i+=3){
            for(int j = 0; j<9; j+=3){
                unordered_map<char, int> grid;
                grid[board[i][j]]++;
                if(grid[board[i][j]]>1 && board[i][j]!='.') return false;

                grid[board[i][j+1]]++;
                if(grid[board[i][j+1]]>1 && board[i][j+1]!='.') return false;
                
                grid[board[i][j+2]]++;
                if(grid[board[i][j+2]]>1 && board[i][j+2]!='.') return false;
                
                grid[board[i+1][j]]++;
                if(grid[board[i+1][j]]>1 && board[i+1][j]!='.') return false;
                
                grid[board[i+1][j+1]]++;
                if(grid[board[i+1][j+1]]>1 && board[i+1][j+1]!='.') return false;
                
                grid[board[i+1][j+2]]++;
                if(grid[board[i+1][j+2]]>1 && board[i+1][j+2]!='.') return false;

                grid[board[i+2][j]]++;
                if(grid[board[i+2][j]]>1 && board[i+2][j]!='.') return false;
                
                grid[board[i+2][j+1]]++;
                if(grid[board[i+2][j+1]]>1 && board[i+2][j+1]!='.') return false;
                
                grid[board[i+2][j+2]]++;
                if(grid[board[i+2][j+2]]>1 && board[i+2][j+2]!='.') return false;
            }
        }
        return true;
    }
};