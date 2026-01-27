/*
You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with cost wi.

Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used its switch, you may activate it on one of its incoming edges vi → ui reverse that edge to ui → vi and immediately traverse it.

The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.

Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.

 

Example 1:

Input: n = 4, edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]

Output: 5

Explanation:

    Use the path 0 → 1 (cost 3).
    At node 1 reverse the original edge 3 → 1 into 1 → 3 and traverse it at cost 2 * 1 = 2.
    Total cost is 3 + 2 = 5.

Example 2:

Input: n = 4, edges = [[0,2,1],[2,1,1],[1,3,1],[2,3,3]]

Output: 3

Explanation:

    No reversal is needed. Take the path 0 → 2 (cost 1), then 2 → 1 (cost 1), then 1 → 3 (cost 1).
    Total cost is 1 + 1 + 1 = 3.

 

Constraints:

    2 <= n <= 5 * 104
    1 <= edges.length <= 105
    edges[i] = [ui, vi, wi]
    0 <= ui, vi <= n - 1
    1 <= wi <= 1000

*/

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<long long, long long>>> adj(n);
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]*2});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
        q.push({0, 0});
        vector<long long> dist(n, 1e8);
        dist[0] = 0;
        while(!q.empty()){
            pair<int, int> p = q.top();
            q.pop();
            long long d = p.first;
            long long n = p.second;
            for(auto it:adj[n]){
                long long wt = it.second;
                long long node = it.first;
                if(dist[node] > d+wt){
                    dist[node] = d+wt;
                    q.push({dist[node], node});
                }
            }
        }
        if(dist[n-1] == 1e8) return -1;
        return dist[n-1];
    }
};