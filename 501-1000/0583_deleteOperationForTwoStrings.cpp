/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4

 

Constraints:

    1 <= word1.length, word2.length <= 500
    word1 and word2 consist of only lowercase English letters.

*/

class Solution {
public:
    int lcs(string s1, string s2){
        int n = s1.length();
        int m = s2.length();
        vector<int> dp(m+1, 0);
        for(int i = 1; i<=n; i++){
            int diag = 0;
            for(int j = 1; j<=m; j++){
                int temp = dp[j];
                if(s1[i-1] == s2[j-1]){
                    dp[j] = 1 + diag;
                }
                else{
                    dp[j] = max(dp[j-1], dp[j]);
                }
                diag = temp;
            }
        }
        return dp[m];
    }
    int minDistance(string word1, string word2) {
        int l = lcs(word1, word2);
        return (word1.length()-l)+(word2.length()-l);
    }
};