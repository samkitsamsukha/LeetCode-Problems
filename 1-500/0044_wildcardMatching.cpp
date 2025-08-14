/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

 

Constraints:

    0 <= s.length, p.length <= 2000
    s contains only lowercase English letters.
    p contains only lowercase English letters, '?' or '*'.

*/

class Solution {
public:
    bool mem(int i, int j, string s, string p, vector<vector<int>>& dp){
        // i is in s
        // j is in p
        if(j<0 && i<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            for(int x = 0; x<=j; x++){
                if(p[x] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?'){
            return  dp[i][j] = mem(i-1, j-1, s, p, dp);
        }
        else if(p[j] == '*'){
            return dp[i][j] = (mem(i-1, j, s, p, dp)|mem(i, j-1, s, p, dp));
        }
        return dp[i][j] = false;
    }
    bool tab(string s, string p){
        int n = s.length();
        int m = p.length();
        vector<int> prev(m+1, 0);
        vector<int> cur(m+1, 0);
        prev[0] = 1;
        for(int j = 1; j<=m; j++){
            prev[j] = 1;
            for(int x = 1; x<=j; x++){
                if(p[x-1] != '*'){
                    prev[j] = 0;
                }
            }
        }
        for(int i = 1; i<=n; i++){
            cur[0] = 0;
            for(int j = 1; j<=m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    cur[j] = prev[j-1];
                }
                else if(p[j-1] == '*'){
                    cur[j] = (prev[j]|cur[j-1]);
                }
                else cur[j] = 0;
            }
            prev = cur;
        }
        return prev[m];
    }
    bool space(string s, string p){
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i<=n; i++){
            dp[i][0] = 0;
        }
        for(int j = 1; j<=m; j++){
            dp[0][j] = 1;
            for(int x = 1; x<=j; x++){
                if(p[x-1] != '*'){
                    dp[0][j] = 0;
                }
            }
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    dp[i][j] = (dp[i-1][j]|dp[i][j-1]);
                }
                else dp[i][j] = 0;
            }
        }
        return dp[n][m];
    }
    bool isMatch(string s, string p) {
        // int n = s.length();
        // int m = p.length();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        return tab(s, p);
    }
};