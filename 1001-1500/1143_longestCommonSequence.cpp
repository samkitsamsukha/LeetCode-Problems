/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

    For example, "ace" is a subsequence of "abcde".

A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

 

Constraints:

    1 <= text1.length, text2.length <= 1000
    text1 and text2 consist of only lowercase English characters.

*/

class Solution {
public:
    int f(int i1, int i2, string s1, string s2, vector<vector<int>>& dp){
        if(i1<0 || i2<0){
            return 0;
        }
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(s1[i1] == s2[i2]){
            return dp[i1][i2] = 1 + f(i1-1, i2-1, s1, s2, dp);
        }
        return dp[i1][i2] = max(f(i1-1, i2, s1, s2, dp), f(i1, i2-1, s1, s2, dp));
    }
    int t(string s1, string s2){
        int n = s1.length();
        int m = s2.length();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        vector<int> prev(m+1, 0);
        vector<int> cur(m+1, 0);
        for(int i = 0; i<m+1; i++){
            prev[i] = 0;
        }
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                if(s1[i-1] == s2[j-1]){
                    cur[j] = 1 + prev[j-1];
                }
                else{
                    cur[j] = max(prev[j], cur[j-1]);
                }
            }
            prev = cur;
        }
        return prev[m];
    }
    int sp(string s1, string s2){
        int n = s1.length();
        int m = s2.length();
        vector<int> prev(m+1, 0);
        for(int i = 0; i<m+1; i++){
            prev[i] = 0;
        }
        for(int i = 1; i<n+1; i++){
            int diag = 0;
            for(int j = 1; j<m+1; j++){
                int temp = prev[j];
                if(s1[i-1] == s2[j-1]){
                    prev[j] = 1 + diag;
                }
                else{
                    prev[j] = max(prev[j], prev[j-1]);
                }
                diag = temp;
            }
        }
        return prev[m];
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        // return f(text1.length()-1, text2.length()-1, text1, text2, dp);
        return sp(text1, text2);
    }
};