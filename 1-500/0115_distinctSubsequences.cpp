/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit

Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag

 

Constraints:

    1 <= s.length, t.length <= 1000
    s and t consist of English letters.

*/

class Solution {
public:
    int mem(int i, int j, string s, string t, vector<vector<int>>& dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = mem(i-1, j-1, s, t, dp) + mem(i-1, j, s, t, dp);
        }
        else return dp[i][j] = mem(i-1, j, s, t, dp);
    }
    int tab(string s, string t){
        vector<vector<double>> dp(s.length()+1, vector<double>(t.length()+1, 0));
        for(int i = 0; i<=s.length(); i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i<=s.length(); i++){
            for(int j = 1; j<=t.length(); j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[s.length()][t.length()];
    }
    int sp(string s, string t){
        int n = s.length();
        int m = t.length();
        vector<double> dp(m+1, 0);
        dp[0] = 1;
        for(int i = 1; i<=n; i++){
            for(int j = m; j>0; j--){
                if(s[i-1] == t[j-1]){
                    dp[j] = dp[j-1] + dp[j];
                }
                else{
                    dp[j] = dp[j];
                }
            }
        }
        return dp[m];
    }
    int numDistinct(string s, string t) {
        // vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        // return mem(s.length()-1, t.length()-1, s, t, dp);
        return sp(s, t);
    }
};