/*
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.

 

Constraints:

    n == grid.length
    n == grid[i].length
    1 <= n <= 500
    grid[i][j] is either 0 or 1.

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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==0) continue;
                for(int k = 0; k<4; k++){
                    int xi = i+dx[k];
                    int yi = j+dy[k];
                    if(xi>=0 && yi>=0 && xi<n && yi<n && grid[xi][yi] == 1){
                        int a = i*n+j;
                        int b = xi*n+yi;
                        if(ds.findParent(a)!=ds.findParent(b)){
                            ds.unionBySize(a, b);
                        }
                    }
                }
            }
        }
        // for(int i = 0; i<ds.size.size(); i++){
        //     cout << ds.size[i] << endl;
        // }
        int ans = -1;
        bool hasZero = false;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==0){
                    hasZero = true;
                    int  temp = 1;
                    set<int> st;
                    for(int k = 0; k<4; k++){
                        int xi = i+dx[k];
                        int yi = j+dy[k];
                        if(xi<n && yi<n && xi>=0 && yi>=0 && grid[xi][yi] == 1){
                            st.insert(ds.findParent(xi*n+yi));
                        }
                    }
                    for(auto it:st){
                        temp+=ds.size[it];
                    }
                    ans = max(temp, ans);
                }
            }
        }
        if(!hasZero) return n*n;
        return ans;
    }
};