/*
You are given a string s.

Your task is to remove all digits by doing this operation repeatedly:

Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.

    Example 1:

Input: s = "abc"
Output: "abc"
Explanation: There is no digit in the string.

    Example 2:

Input: s = "cb34"
Output: ""
Explanation: First, we apply the operation on s[2], and s becomes "c4". Then we apply the operation on s[1], and s becomes "".

    Constraints:

1 <= s.length <= 100
s consists only of lowercase English letters and digits.
The input is generated such that it is possible to delete all digits.
*/

class Solution {
public:
    string clearDigits(string s) {
        int alphaIndex;
        for(int i = 0; i<s.length(); i++){
            if(isdigit(s[i])){
                s[i] = '-';
                if(i>0){
                    int j = i-1;
                    while(j>=0 && !isalpha(s[j])){
                        j--;
                    }
                    if(j>=0){
                        s[j] = '-';
                    }
                }
            }
            // cout << s << endl;
        }
        string ans = "";
        for(int i = 0; i<s.length(); i++){
            if(s[i]!='-'){
                ans = ans + s[i];
            }
        }
        return ans;
    }
};

class Solution {
    public:
        string clearDigits(string s) {
            stack<char> st;
            for(int i = 0; i<s.length(); i++){
                if(isdigit(s[i]) && !st.empty()){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
            s = "";
            while(!st.empty()){
                s = s+st.top();
                st.pop();
            }
            reverse(s.begin(), s.end());
            return s;
        }
    };`