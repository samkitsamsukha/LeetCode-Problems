/*
Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

A substring is a contiguous sequence of characters within a string

 

Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.

Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".

Example 3:

Input: words = ["blue","green","bu"]
Output: []
Explanation: No string of words is substring of another string.

 

Constraints:

    1 <= words.length <= 100
    1 <= words[i].length <= 30
    words[i] contains only lowercase English letters.
    All the strings of words are unique.


*/

class Solution {
public:
    bool isSubstring(string a, string b){
        for(int i = 0; i<b.length(); i++){
            bool flag = true;
            if(a[0] == b[i]){
                for(int j = 0; j<a.length(); j++){
                    if(i+j < b.length() && a[j] == b[i+j]){
                        continue;
                    }
                    else{
                        flag = false;
                    }
                }
                if(flag) return true;
            }
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i = 0; i<words.size(); i++){
            for(int j = i+1; j<words.size(); j++){
                if(words[i].length() > words[j].length()){
                    if(isSubstring(words[j], words[i])){
                        bool p = false;
                        for(int k = 0; k<ans.size(); k++){
                            if(ans[k] == words[j]){
                                p = true;
                            }
                        }
                        if(!p) ans.push_back(words[j]);
                    }
                }
                else{
                    if(isSubstring(words[i], words[j])){
                        bool p = false;
                        for(int k = 0; k<ans.size(); k++){
                            if(ans[k] == words[i]){
                                p = true;
                            }
                        }
                        if(!p) ans.push_back(words[i]);
                    }
                }
            }
        }
        return ans;
    }
};