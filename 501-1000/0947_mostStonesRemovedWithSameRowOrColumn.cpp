/*
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.

Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.

Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.

 

Constraints:

    1 <= stones.length <= 1000
    0 <= xi, yi <= 104
    No two stones are at the same coordinate point.

*/

class DisjointSet {
    public:
        vector<int> rank, parent, size; 
        DisjointSet(int n){
            rank.resize(n+1, 0);
            size.resize(n+1, 1);
            parent.resize(n+1);
            for(int i = 0; i<=n; i++){
                parent[i] = i;
            }
        }

        int findParent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }

        void unionByRank(int u, int v){
            int ulu = findParent(u);
            int ulv = findParent(v);
            if(ulu == ulv) return;
            if(rank[ulu] < rank[ulv]){
                parent[ulu] = ulv;
            }
            else if(rank[ulv] < rank[ulu]){
                parent[ulv] = ulu;
            }
            else{
                parent[ulv] = ulu;
                rank[ulv]++;
            }
        }

        void unionBySize(int u, int v){
            int ulu = findParent(u);
            int ulv = findParent(v);
            if(ulu == ulv) return;
            if(size[ulu] < size[ulv]){
                parent[ulu] = ulv;
                size[ulv] = size[ulv]+size[ulu];
            }
            else{
                parent[ulv] = ulu;
                size[ulu] = size[ulu]+size[ulv];
            }
        }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = 0, m = 0;
        for(int i = 0; i<stones.size(); i++){
            n = max(n, stones[i][0]);
            m = max(m, stones[i][1]);
        }
        n++;
        m++;
        // vector<vector<int>> grid(n, vector<int>(m, 0));
        // for(int i = 0; i<stones.size(); i++){
        //     grid[stones[i][0]][stones[i][1]] = 1;
        // }
        DisjointSet ds(n+m+1);
        set<int> st;
        for(int i = 0; i<stones.size(); i++){
            int r = stones[i][0];
            int c = stones[i][1]+n;
            ds.unionByRank(r, c);
            st.insert(r);
        }
        int c = 0;
        for(auto it:st){
            if(it == ds.findParent(it)){
                c++;
            }
        }
        return stones.size() - c;
    }
};