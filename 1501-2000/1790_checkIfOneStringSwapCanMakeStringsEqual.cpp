/*
You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

 

Example 1:

Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".

Example 2:

Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.

Example 3:

Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.

 

Constraints:

    1 <= s1.length, s2.length <= 100
    s1.length == s2.length
*/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int c = 0;
        map<pair<char, char>, int> mpp;
        for(int i = 0; i<s1.length(); i++){
            if(s1[i]!=s2[i]){
                c++;
                mpp[{s1[i], s2[i]}]++;
            }
            if(c>2) return false;
        }
        // for(auto it:mpp){
        //     cout << it.first.first << "-" << it.first.second << endl;
        // }
        if(c==0) return true;
        else if(c==1) return false;
        for(auto it:mpp){
            // cout << "checking " << x << " and " << y << endl;
            // cout << mpp[{y, x}] << endl;
            if(mpp[{it.first.second, it.first.first}]==0) return false;
        }
        return true;
    }
};