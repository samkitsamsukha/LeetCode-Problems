/*
Given a string s, partition s such that every of the partition is a

.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Example 2:

Input: s = "a"
Output: 0

Example 3:

Input: s = "ab"
Output: 1

 

Constraints:

    1 <= s.length <= 2000
    s consists of lowercase English letters only.
*/

class Solution {
public:
    bool isPalindrome(int i, int j, string& a){
        int l = i, r = j;
        while(l < r){
            if(a[l++] != a[r--]) return false;
        }
        return true;
    }
    int f(int i, string& s, vector<int>& dp){
        if(i==s.length()) return 0;
        if(dp[i] != -1) return dp[i];
        int mini = INT_MAX;
        for(int j = i; j<s.length(); j++){
            if(isPalindrome(i, j, s)){
                int cost = 1 + f(j+1, s , dp);
                // cout << "1 + " << s.substr(i, j - i + 1) << endl;
                mini = min(mini, cost);
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s) {
        // return max(0, f(0, s, dp)-1);
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        for(int i = n-1; i>=0; i--){
            int mini = n;
            for(int j = i; j<s.length(); j++){
                if(isPalindrome(i, j, s)){
                    int cost = 1 + dp[j+1];
                    // cout << "1 + " << s.substr(i, j - i + 1) << endl;
                    mini = min(mini, cost);
                }
                dp[i] = mini;
            }
        }
        return dp[0]-1;
    }
};