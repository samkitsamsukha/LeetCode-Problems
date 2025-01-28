/*
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

Example 3:

Input: s = "abc"
Output: 1

 

Constraints:

    3 <= s.length <= 5 x 10^4
    s only consists of a, b or c characters.


*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        int count = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        while(r<s.length()){
            if(s[r]=='a'){
                a++;
            }
            else if(s[r]=='b'){
                b++;
            }
            else if(s[r]=='c'){
                c++;
            }
            while(a>0 && b>0 && c>0){
                count = count + s.length()-r;
                if(s[l]=='a'){
                    a--;
                }
                if(s[l]=='b'){
                    b--;
                }
                if(s[l]=='c'){
                    c--;
                }
                l++;
            }
            r++;
        }
        return count;
    }
};