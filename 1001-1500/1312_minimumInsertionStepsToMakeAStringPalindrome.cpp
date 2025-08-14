/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.

Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".

Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

 

Constraints:

    1 <= s.length <= 500
    s consists of lowercase English letters.

*/

class Solution {
public:
    int lcs(string s1, string s2){
        int n = s1.length();
        vector<int> dp(n+1, 0);
        for(int i = 1; i<=n; i++){
            int diag = 0;
            for(int j = 1; j<=n; j++){
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
        return dp[n];
    }
    int minInsertions(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        return s.length()-lcs(s, r);
    }
};