/*
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

    For example, "ACGAATTCCG" is a DNA sequence.

When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]

 

Constraints:

    1 <= s.length <= 105
    s[i] is either 'A', 'C', 'G', or 'T'.


*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() <= 9){
            return {};
        }
        map<string, int> mpp;
        vector<string> ans;
        for(int i = 0; i<s.length()-9; i++){
            mpp[s.substr(i, 10)]++;
        }
        for(auto it: mpp){
            // cout << it.first << " -> " << it.second << endl;
            if(it.second >= 2) ans.push_back(it.first);
        }
        return ans;
    }
};