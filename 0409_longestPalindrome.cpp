/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

    Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

    Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 
    Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mpp;
        for(int i = 0; i<s.length(); i++){
            mpp[s[i]]++;
        }
        int len = 0;
        bool odd = false;
        for(auto it:mpp){
            if(it.second % 2 == 0){
                len = len + it.second;
            }
            else{
                len = len + it.second -1;
                odd = true;
            }
        }
        if(odd){
            len++;
        }
        return len;
    }
};