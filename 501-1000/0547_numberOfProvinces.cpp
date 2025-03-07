/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

 

Constraints:

    1 <= n <= 200
    n == isConnected.length
    n == isConnected[i].length
    isConnected[i][j] is 1 or 0.
    isConnected[i][i] == 1
    isConnected[i][j] == isConnected[j][i]


*/

class Solution {
    public:
        void traverse(vector<vector<int>>& isConnected, int node, vector<int>& vis){
            queue<int> q;
            q.push(node);
            vis[node] = 1;
            while(!q.empty()){
                int t = q.front();
                q.pop();
                for(int i = 0; i<isConnected.size(); i++){
                    if(isConnected[t][i] && !vis[i]){
                        q.push(i);
                        vis[i] = 1;
                    }
                }
            }
        }
        int findCircleNum(vector<vector<int>>& isConnected) {
            vector<int> vis(isConnected.size(), 0);
            int ans = 0;
            for(int i = 0; i<vis.size(); i++){
                if(!vis[i]){
                    ans++;
                    traverse(isConnected, i, vis);
                }
                else{
                    continue;
                }
            }
            return ans;
        }
    };