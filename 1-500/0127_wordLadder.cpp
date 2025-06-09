/*
 transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

    Every adjacent pair of words differs by a single letter.
    Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

 

Constraints:

    1 <= beginWord.length <= 10
    endWord.length == beginWord.length
    1 <= wordList.length <= 5000
    wordList[i].length == beginWord.length
    beginWord, endWord, and wordList[i] consist of lowercase English letters.
    beginWord != endWord
    All the words in wordList are unique
    
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        map<string, int> mpp;
        for (int i = 0; i < wordList.size(); i++)
            mpp[wordList[i]]++;
        queue<string> q;
        q.push(beginWord);
        int level = 2;
        while (!q.empty()) {
            int s = q.size();
            // cout << "Currently in level " << level << endl;
            for (int i = 0; i < s; i++) {
                string s = q.front();
                q.pop();
                for (int j = 0; j < s.length(); j++) {
                    string x = s;
                    for (int k = 0; k < 26; k++) {
                        x[j] = char('a' + k);
                        if (x != s && mpp[x]) {
                            if (x == endWord) {
                                // cout << "Found at level " << level;
                                return level;
                            }
                            q.push(x);
                            mpp[x] = 0;
                            // cout << "Pushed " << x << endl;
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};