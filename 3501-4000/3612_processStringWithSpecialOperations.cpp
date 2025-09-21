/*
You are given a string s consisting of lowercase English letters and the special characters: *, #, and %.

Build a new string result by processing s according to the following rules from left to right:

    If the letter is a lowercase English letter append it to result.
    A '*' removes the last character from result, if it exists.
    A '#' duplicates the current result and appends it to itself.
    A '%' reverses the current result.

Return the final string result after processing all characters in s.

 

Example 1:

Input: s = "a#b%*"

Output: "ba"

Explanation:
i	s[i]	Operation	Current result
0	'a'	Append 'a'	"a"
1	'#'	Duplicate result	"aa"
2	'b'	Append 'b'	"aab"
3	'%'	Reverse result	"baa"
4	'*'	Remove the last character	"ba"

Thus, the final result is "ba".

Example 2:

Input: s = "z*#"

Output: ""

Explanation:
i	s[i]	Operation	Current result
0	'z'	Append 'z'	"z"
1	'*'	Remove the last character	""
2	'#'	Duplicate the string	""

Thus, the final result is "".

 

Constraints:

    1 <= s.length <= 20
    s consists of only lowercase English letters and special characters *, #, and %.

*/

class Solution {
public:
    string processStr(string s) {
        string result = "";
        for(int i = 0; i<s.length(); i++){
            if(result.length()>0){
                if(s[i] == '*' && result.length()>0){
                    int x = result.length()-1;
                    while(x>=0){
                        if(result[x] != '-'){
                            result[x] = '-';
                            break;
                        }
                        x--;
                    }
                }
                else if(s[i] == '#'){
                    result+=result;
                }
                else if(s[i] == '%'){
                    reverse(result.begin(), result.end());
                }
            }
            if(isalpha(s[i])) result+=s[i];
            // cout << result << endl;
        }
        string a = "";
        for(int i = 0; i<result.size(); i++){
            if(result[i] != '-'){
                a+=result[i];
            }
        }
        return a;
    }
};