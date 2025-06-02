/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

    For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.

Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

Return a boolean array answer, where answer[j] is the answer to the jth query.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
Output: [false,true]
Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
Course 0 is not a prerequisite of course 1, but the opposite is true.

Example 2:

Input: numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
Output: [false,false]
Explanation: There are no prerequisites, and each course is independent.

Example 3:

Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
Output: [true,true]

 

Constraints:

    2 <= numCourses <= 100
    0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)
    prerequisites[i].length == 2
    0 <= ai, bi <= numCourses - 1
    ai != bi
    All the pairs [ai, bi] are unique.
    The prerequisites graph has no cycles.
    1 <= queries.length <= 104
    0 <= ui, vi <= numCourses - 1
    ui != vi

*/

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        vector<vector<int>> dist(n, vector<int>(n, 1e8));
        for(int i = 0; i<pre.size(); i++){
            dist[pre[i][0]][pre[i][1]] = 1;
        }
        for(int i = 0; i<n; i++){
            dist[i][i] = 0;
        }
        for(int inter = 0; inter<n; inter++){
            for(int src = 0; src<n; src++){
                for(int dest = 0; dest<n; dest++){
                    if(dist[src][inter]!=1e8 && dist[inter][dest]!=1e8){
                        dist[src][dest] = min(dist[src][dest], dist[src][inter]+dist[inter][dest]);
                    }
                }
            }
        }
        vector<bool> ans;
        for(int i = 0; i<q.size(); i++){
            if(dist[q[i][0]][q[i][1]] != 0 && dist[q[i][0]][q[i][1]] != 1e8){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};