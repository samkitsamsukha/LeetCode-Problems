/*
You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

    Example 1:

Input: s = "(abcd)"
Output: "dcba"

    Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

    Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.

    Constraints:

1 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It is guaranteed that all parentheses are balanced.
*/

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<char> st;
        for(int i = 0; i<n; i++){
            if(s[i]==')'){
                string current = "";
                while(st.top() != '('){
                    current = current + st.top();
                    st.pop();
                }
                st.pop();
                for(auto &it:current){
                    st.push(it);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};