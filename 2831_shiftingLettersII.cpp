/*
You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied.

 

Example 1:

Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
Output: "ace"
Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".

Example 2:

Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
Output: "catz"
Explanation: Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
Finally, shift the characters from index 1 to index 1 forward. Now s = "catz".

 

Constraints:

    1 <= s.length, shifts.length <= 5 * 104
    shifts[i].length == 3
    0 <= starti <= endi < s.length
    0 <= directioni <= 1
    s consists of lowercase English letters.


*/

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& q) {
        vector<int> a(s.length()+1, 0);
        for(int i = 0; i<q.size(); i++){
            if(q[i][2] == 1){
                a[q[i][0]]+=1;
                a[q[i][1]+1]-=1;
            }
            else{
                a[q[i][0]]-=1;
                a[q[i][1]+1]+=1;
            }
        }
        for(int i = 1; i<a.size(); i++){
            a[i] = a[i-1]+a[i];
            a[i] = a[i]%26;
        }
        a[0] = a[0] % 26;
        // for(int i = 0; i<a.size(); i++){
        //     cout << a[i] << " ";
        // }
        for(int i = 0; i<s.length(); i++){
            if(s[i]+a[i] < 97){
                // s[i] = b = 98
                // a[i] = -4
                // s[i] + a[i] = 94
                // required = x = '120'
                // 122 - (96 - 94)
                s[i] = 'z' - (97 - 1 - (s[i] + a[i]));
            }
            else if(s[i]+a[i] > 122){
                s[i] = 'a' + (s[i] + a[i] - 122 - 1);
            }
            else{
                s[i] = s[i] + a[i];
            }
        }
        return s;
    }
};