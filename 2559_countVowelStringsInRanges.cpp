/*
You are given a 0-indexed array of strings words and a 2D array of integers queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].

Example 2:

Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
Output: [3,2,1]
Explanation: Every string satisfies the conditions, so we return [3,2,1].

 

Constraints:

    1 <= words.length <= 105
    1 <= words[i].length <= 40
    words[i] consists only of lowercase English letters.
    sum(words[i].length) <= 3 * 105
    1 <= queries.length <= 105
    0 <= li <= ri < words.length


*/

class Solution {
public:
    bool isVowel(char ch){
        return (ch == 'a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    vector<int> vowelStrings(vector<string>& a, vector<vector<int>>& q) {
        int n = a.size();
        vector<int> pre(n+1);
        pre[0] = 0;
        for(int i = 0; i<n; i++){
            string s = a[i];
            if(isVowel(s[0]) && isVowel(s[s.length()-1])){
                pre[i+1] = pre[i] + 1;
            }
            else{
                pre[i+1] = pre[i];
            }
        }
        // for(int i = 0; i<pre.size(); i++){
        //     cout << pre[i] << " ";
        // }
        vector<int> ans(q.size());
        for(int i = 0; i<q.size(); i++){
            ans[i] = pre[q[i][1]+1] - pre[q[i][0]];
        }
        return ans;
    }
};