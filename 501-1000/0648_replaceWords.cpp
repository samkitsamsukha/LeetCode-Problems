/*
In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

 

Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"

Example 2:

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"

 

Constraints:

    1 <= dictionary.length <= 1000
    1 <= dictionary[i].length <= 100
    dictionary[i] consists of only lower-case letters.
    1 <= sentence.length <= 106
    sentence consists of only lower-case letters and spaces.
    The number of words in sentence is in the range [1, 1000]
    The length of each word in sentence is in the range [1, 1000]
    Every two consecutive words in sentence will be separated by exactly one space.
    sentence does not have leading or trailing spaces.


*/

struct TrieNode{
    TrieNode* children[26];
    bool isEnd = false;
    string word;
};

class Trie{
    TrieNode* root;
public:
    Trie(){ 
        root = new TrieNode();
    }
    void insert(const string& word){
        TrieNode* node = root;
        for(char ch:word){
            if(!node->children[ch-'a']){
                node->children[ch-'a'] = new TrieNode();
            }
            node = node->children[ch-'a'];
        }
        node->isEnd = true;
        node->word = word;
    }
    string findRoot(const string& word){
        TrieNode* node = root;
        for(char ch:word){
            if(!node->children[ch-'a']) break;
            node = node->children[ch-'a'];
            if(node->isEnd) return node->word;
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        Trie trie;
        string result = "";
        for(auto i : d){
            trie.insert(i);
        }
        int i = 0;
        while(i<s.length()){
            while(i<s.length() && s[i]==' '){
                i++;
            }
            if(i>=s.length()) break;
            int j = i;
            while(j<s.length() && s[j]!=' '){
                j++;
            }
            if(!result.empty()) result+=" ";
            result+=trie.findRoot(s.substr(i, j-i));
            i = j;
        }
        return result;
    }
};