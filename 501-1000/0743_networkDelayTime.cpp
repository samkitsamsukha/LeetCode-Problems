/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1

 

Constraints:

    1 <= k <= n <= 100
    1 <= times.length <= 6000
    times[i].length == 3
    1 <= ui, vi <= n
    ui != vi
    0 <= wi <= 100
    All the pairs (ui, vi) are unique. (i.e., no multiple edges.)


*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> dist(n, vector<int>(n, 1e8));
        for(int i = 0; i<times.size(); i++){
            int x = times[i][0];
            int y = times[i][1];
            int w = times[i][2];
            dist[x-1][y-1] = w;
        }
        for(int i = 0; i<n; i++){
            dist[i][i] = 0;
        }
        // cout << "Distance Matrix" << endl;
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<n; j++){
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for(int inter = 0; inter<n; inter++){
            for(int src = 0; src<n; src++){
                for(int dest = 0; dest<n; dest++){
                    if(dist[src][inter]!=1e8 && dist[inter][dest]!=1e8){
                        dist[src][dest] = min(dist[src][dest], dist[src][inter]+dist[inter][dest]);
                    }
                }
            }
        }
        // cout << "Shortened Matrix" << endl;
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<n; j++){
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int ans = -1;
        for(int i = 0; i<n; i++){
            if(dist[k-1][i]==1e8) return -1;
            ans = max(ans, dist[k-1][i]);
        }
        return ans;
    }
};