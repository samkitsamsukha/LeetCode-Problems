/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

 

Constraints:

    1 <= numCourses <= 2000
    0 <= prerequisites.length <= 5000
    prerequisites[i].length == 2
    0 <= ai, bi < numCourses
    All the pairs prerequisites[i] are unique.


*/

class Solution {
public:
    bool detect(int i, vector<vector<int>>& adj, vector<int>& vis, vector<int>& st){
        vis[i] = 1;
        st[i] = 1;
        for(auto it:adj[i]){
            if(!vis[it]){
                if(detect(it, adj, vis, st)) return true;
            }
            else if(st[it] == 1){
                return true;
            }
        }
        st[i] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<int> vis(n, 0);
        vector<int> st(n, 0);
        vector<vector<int>> adj(n);
        for(int i = 0; i<a.size(); i++){
            adj[a[i][1]].push_back(a[i][0]);
        }
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                if(detect(i, adj, vis, st)){
                    return false;
                }
            }
        }
        return true;
    }
};