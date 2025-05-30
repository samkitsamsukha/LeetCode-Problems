/*
A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.

 

Example 1:

Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".

Example 2:

Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".

Example 3:

Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".

 

Constraints:

    1 <= s.length <= 105
    s consists only of lowercase English letters.


*/

class Solution {
public:
    string makeFancyString(string s) {
        vector<char> ans;
        if(s.length() != 0){
            ans.push_back(s[0]);
        }
        if(s.length()>1) {
            ans.push_back(s[1]);
        }
        for(int i = 2; i<s.length(); i++){
            if(s[i] == s[i-1] && s[i] == s[i-2]){
                
            }
            else{
                ans.push_back(s[i]);
            }
        }
        string rv(ans.begin(), ans.end());
        return rv;
    }
};