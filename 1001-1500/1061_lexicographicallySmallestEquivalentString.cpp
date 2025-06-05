/*
You are given two strings of the same length s1 and s2 and a string baseStr.

We say s1[i] and s2[i] are equivalent characters.

    For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.

Equivalent characters follow the usual rules of any equivalence relation:

    Reflexivity: 'a' == 'a'.
    Symmetry: 'a' == 'b' implies 'b' == 'a'.
    Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.

For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.

Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.

 

Example 1:

Input: s1 = "parker", s2 = "morris", baseStr = "parser"
Output: "makkek"
Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [m,p], [a,o], [k,r,s], [e,i].
The characters in each group are equivalent and sorted in lexicographical order.
So the answer is "makkek".

Example 2:

Input: s1 = "hello", s2 = "world", baseStr = "hold"
Output: "hdld"
Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [h,w], [d,e,o], [l,r].
So only the second letter 'o' in baseStr is changed to 'd', the answer is "hdld".

Example 3:

Input: s1 = "leetcode", s2 = "programs", baseStr = "sourcecode"
Output: "aauaaaaada"
Explanation: We group the equivalent characters in s1 and s2 as [a,o,e,r,s,c], [l,p], [g,t] and [d,m], thus all letters in baseStr except 'u' and 'd' are transformed to 'a', the answer is "aauaaaaada".

 

Constraints:

    1 <= s1.length, s2.length, baseStr <= 1000
    s1.length == s2.length
    s1, s2, and baseStr consist of lowercase English letters.

*/

class Solution {
public:
    void bfs(int i, vector<vector<int>> adj, vector<int>& vis, vector<int>& eq){
        vis[i] = 1;
        queue<int> q;
        q.push(i);
        int mini = i;
        while(!q.empty()){
            int p = q.front();
            q.pop();
            for(auto it:adj[p]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                    if(mini>it){
                        mini = it;
                    }            
                }
            }
        }
        q.push(i);
        eq[i] = mini;
        vector<int> temp(26, 0);
        while(!q.empty()){
            int p = q.front();
            q.pop();
            for(auto it:adj[p]){
                if(!temp[it]){
                    q.push(it);
                    temp[it] = 1;
                    eq[it] = mini;  
                }
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<int>> adj(26);
        for(int i = 0; i<s1.length(); i++){
            adj[s1[i]-'a'].push_back(s2[i]-'a');
            adj[s2[i]-'a'].push_back(s1[i]-'a');
        }
        vector<int> vis(26, 0);
        vector<int> eq(26, 0);
        for(int i = 0; i<adj.size(); i++){
            if(!vis[i]){
                bfs(i, adj, vis, eq);
            }
        }
        // for(int i = 0; i<26; i++){
        //     cout << char(i+'a') << " -> " << char(eq[i]+'a') << endl;
        // }
        for(int i = 0; i<baseStr.length(); i++){
            baseStr[i] = char(eq[baseStr[i]-'a']+'a');
        }
        return baseStr;
    }
};