/*
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

 

Example 1:

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.

Example 2:

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000

Example 3:

Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.

 

Constraints:

    2 <= n <= 10^4
    0 <= start, end < n
    start != end
    0 <= a, b < n
    a != b
    0 <= succProb.length == edges.length <= 2*10^4
    0 <= succProb[i] <= 1
    There is at most one edge between every two nodes.

*/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& a, vector<double>& p, int src, int dest) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i<a.size(); i++){
            adj[a[i][0]].push_back({a[i][1], p[i]});
            adj[a[i][1]].push_back({a[i][0], p[i]});
        }
        // for(int i = 0; i<adj.size(); i++){
        //     cout << i << " -> ";
        //     for(int j = 0; j<adj[i].size(); j++){
        //         cout << "{ " << adj[i][j].first << ", " << adj[i][j].second << "} ";
        //     }
        //     cout << endl;
        // }
        vector<double> dist(n, 0.0);
        dist[src] = 1.0;
        priority_queue<pair<double, int>> pq;
        pq.push({dist[src], src});
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            for(auto it:adj[x.second]){
                int node = it.first;
                double wt = it.second;
                if(x.first * wt > dist[node]){
                    dist[node] = x.first*wt;
                    pq.push({dist[node], node});
                }
            }
        }
        return dist[dest];
    }
};