/*
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

    Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]

    Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]
 
    Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.
*/

class Solution {
public:
    bool checkCharacter(string &str, char ch){
        for(int l = 0; l<str.length(); l++){
            if(str[l] == ch){
                str[l] = '0';
                return true;
            }
        }
        return false;
    }
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        for(int i = 0; i<words[0].length(); i++){
            int c = 0;
            for(int j = 1; j<words.size(); j++){
                if(checkCharacter(words[j], words[0][i])){
                    c++;
                }
            }
            if(c==words.size()-1){
                string s(1, words[0][i]);
                result.push_back(s);
            }
        }
        return result;
    }
};


                    