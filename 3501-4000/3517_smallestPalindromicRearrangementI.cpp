/*
You are given a

string s.

Return the
palindromic

of s.

 

Example 1:

Input: s = "z"

Output: "z"

Explanation:

A string of only one character is already the lexicographically smallest palindrome.

Example 2:

Input: s = "babab"

Output: "abbba"

Explanation:

Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.

Example 3:

Input: s = "daccad"

Output: "acddca"

Explanation:

Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.

 

Constraints:

    1 <= s.length <= 105
    s consists of lowercase English letters.
    s is guaranteed to be palindromic.

*/

class Solution {
    public:
        string smallestPalindrome(string s) {
            vector<int> f(26, 0);
            for(int i = 0; i<s.length(); i++){
                f[s[i]-'a']++;
            }
            string l = "";
            char m = '.';
            for(int i = 0; i<26; i++){
                if(f[i]%2 == 1){
                    m = 'a'+i;
                }
                l+=string(f[i]/2, 'a'+i);
            }
            string r = l;
            reverse(r.begin(), r.end());
            if(m=='.'){
                return l+r;
            }
            else return l+m+r;
        }
    };