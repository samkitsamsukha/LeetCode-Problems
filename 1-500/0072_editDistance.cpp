/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

 

Constraints:

    0 <= word1.length, word2.length <= 500
    word1 and word2 consist of lowercase English letters.

*/

class Solution {
public:
    int mem(int i, int j, string s, string t, vector<vector<int>>& dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = 0 + mem(i-1, j-1, s, t, dp);
        }
        int inser = mem(i, j-1, s, t, dp);
        int delet = mem(i-1, j, s, t, dp);
        int repla = mem(i-1, j-1, s, t, dp);
        return dp[i][j] = 1 + min(inser, min(delet, repla));
    }
    int tab(string s, string t){
        int n = s.length();
        int m = t.length();
        vector<int> prev(m+1, 0);
        vector<int> cur(m+1, 0);
        for(int j = 0; j<=m; j++){
            prev[j] = j;
        }
        for(int i = 1; i<=n; i++){
            cur[0] = i;
            for(int j = 1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    cur[j] = prev[j-1];
                }
                else{
                    cur[j] = 1 + min(prev[j-1], min(prev[j], cur[j-1]));
                }
            }
            prev = cur;
        }
        return prev[m];
    }
    int singlearray(string s, string t){
        int n = s.length();
        int m = t.length();
        vector<int> prev(m+1, 0);
        vector<int> cur(m+1, 0);
        for(int j = 0; j<=m; j++){
            prev[j] = j;
        }
        for(int i = 1; i<=n; i++){
            cur[0] = i;
            for(int j = 1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    cur[j] = prev[j-1];
                }
                else{
                    cur[j] = 1 + min(prev[j-1], min(prev[j], cur[j-1]));
                }
            }
            prev = cur;
        }
        return prev[m];
    }
    int sp(string s, string t){
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 0; i<=n; i++){
            dp[i][0] = i;
        }
        for(int j = 0; j<=m; j++){
            dp[0][j] = j;
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        // int n = word1.length();
        // int m = word2.length();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return mem(n-1, m-1, word1, word2, dp);
        return tab(word1, word2);
    }
};