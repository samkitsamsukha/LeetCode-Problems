/*
You are given two strings s and t.

String t is generated by random shuffling string s and then add one more letter at a random position.

Return the letter that was added to t.

    Example 1:

Input: s = "abcd", t = "abcde"
Output: "e"
Explanation: 'e' is the letter that was added.

    Example 2:

Input: s = "", t = "y"
Output: "y"


    Constraints:

0 <= s.length <= 1000
t.length == s.length + 1
s and t consist of lowercase English letters.
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mpp;
        mpp[t[t.length()-1]]++;
        for(int i = 0; i<s.length(); i++){
            mpp[s[i]]++;
            mpp[t[i]]++;
        }
        for(auto it : mpp){
            if(it.second % 2 == 1){
                return it.first;
            }
        }
        return ' ';
    }
};