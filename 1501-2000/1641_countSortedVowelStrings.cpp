/*
Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].

Example 2:

Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.

Example 3:

Input: n = 33
Output: 66045

 

Constraints:

    1 <= n <= 50 

*/

class Solution {
public:
    int memoize(int i, int x, vector<vector<int>>& dp){
        if(x==0) return 1;
        int sum = 0;
        if(dp[i][x] != -1) return dp[i][x];
        for(int j = i; j<5; j++){
            sum = sum + memoize(j, x-1, dp);
        }
        return dp[i][x] = sum;
    }
    int countVowelStrings(int n) {
        int ans = 0;
        vector<vector<int>> dp(5, vector<int>(n+1, -1));
        for(int i = 0; i<5; i++){
            ans = ans + memoize(i, n-1, dp);
        }
        return ans;
    }
};