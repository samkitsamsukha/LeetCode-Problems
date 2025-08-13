/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

 

Constraints:

    1 <= s.length <= 1000
    s consists only of lowercase English letters.

*/

class Solution {
public:
    int tabulate(string s1, string s2){
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }   
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int ans = tabulate(s, t);
        return ans;
    }
};