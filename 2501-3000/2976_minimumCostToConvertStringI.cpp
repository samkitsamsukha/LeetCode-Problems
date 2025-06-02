/*
You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

 

Example 1:

Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: To convert the string "abcd" to string "acbe":
- Change value at index 1 from 'b' to 'c' at a cost of 5.
- Change value at index 2 from 'c' to 'e' at a cost of 1.
- Change value at index 2 from 'e' to 'b' at a cost of 2.
- Change value at index 3 from 'd' to 'e' at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28.
It can be shown that this is the minimum possible cost.

Example 2:

Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
Output: 12
Explanation: To change the character 'a' to 'b' change the character 'a' to 'c' at a cost of 1, followed by changing the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3. To change all occurrences of 'a' to 'b', a total cost of 3 * 4 = 12 is incurred.

Example 3:

Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
Output: -1
Explanation: It is impossible to convert source to target because the value at index 3 cannot be changed from 'd' to 'e'.

 

Constraints:

    1 <= source.length == target.length <= 105
    source, target consist of lowercase English letters.
    1 <= cost.length == original.length == changed.length <= 2000
    original[i], changed[i] are lowercase English letters.
    1 <= cost[i] <= 106
    original[i] != changed[i]

*/

class Solution {
public:
    long long minimumCost(string src, string tgt, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF = 1e15;
        vector<vector<long long>> dist(26, vector<long long>(26, INF));
        
        for (int i = 0; i < original.size(); i++) {
            dist[original[i] - 'a'][changed[i] - 'a'] = min(dist[original[i] - 'a'][changed[i] - 'a'], 1LL * cost[i]);
        }
        for (int i = 0; i < 26; i++) dist[i][i] = 0;
        for (int inter = 0; inter < 26; inter++) {
            for (int u = 0; u < 26; u++) {
                for (int v = 0; v < 26; v++) {
                    if (dist[u][inter] < INF && dist[inter][v] < INF) {
                        dist[u][v] = min(dist[u][v], dist[u][inter] + dist[inter][v]);
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < src.length(); i++) {
            if (src[i] != tgt[i]) {
                int from = src[i] - 'a';
                int to = tgt[i] - 'a';
                if (dist[from][to] == INF) return -1;
                ans += dist[from][to];
            }
        }
        return ans;
    }
};
