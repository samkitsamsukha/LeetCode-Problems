/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:

Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]

 

Constraints:

    2 <= n <= 105
    n - 1 <= connections.length <= 105
    0 <= ai, bi <= n - 1
    ai != bi
    There are no repeated connections.

*/

class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, vector<vector<int>>& ans){
        vis[node] = 1;
        tin[node] = timer;
        low[node] = timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it, node, vis, adj, tin, low, ans);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]){
                    ans.push_back({it, node});
                }
            }
            else{
                low[node] = min(low[node], low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> tin(n);
        vector<int> low(n);
        vector<int> vis(n);
        vector<vector<int>> ans;
        vector<vector<int>> adj(n);
        for(int i = 0; i<connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i, -1, vis, adj, tin, low, ans);
            }
        }
        return ans;
    }
};