/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

  Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

  Example 2:

Input: s = "rat", t = "car"
Output: false
 
  Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 
Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/

#include<map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        map<char, int> ms;
        map<char, int> mt;
        bool flag = true;
        for(int i=0; i<s.length(); i++){
            ms[s[i]]++;
        }
        for(int i=0; i<t.length(); i++){
            mt[t[i]]++;
        }
        for(int i=0; i<s.length(); i++){
            if(ms[s[i]]==mt[s[i]]){
                
            }
            else{
                flag = false;
            }
        }
        return flag;
    }
};
