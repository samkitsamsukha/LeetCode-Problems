/*
A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

    Example 1:

Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
    
    Example 2:

Input: sentence = "leetcode"
Output: false
*/

#include<bits/stdc++.h>
class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<int, int> mpp;
        for(int i=0; i<sentence.length(); i++){
            mpp[sentence[i]]++;
        }
        if(mpp.size()<26){
            return false;
        }
        return true;
    }
};