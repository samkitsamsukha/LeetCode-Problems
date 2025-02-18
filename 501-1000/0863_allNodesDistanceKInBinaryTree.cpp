/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Example 2:

Input: root = [1], target = 1, k = 3
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [1, 500].
    0 <= Node.val <= 500
    All the values Node.val are unique.
    target is the value of one of the nodes in the tree.
    0 <= k <= 1000


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            unordered_map<TreeNode*, TreeNode*> parent;
            queue<TreeNode*> q;
            parent[root] = nullptr;
            q.push(root);
            while(!q.empty()){
                TreeNode* p = q.front();
                q.pop();
                if(p->left){
                    parent[p->left] = p;
                    q.push(p->left);
                }
                if(p->right){
                    parent[p->right] = p;
                    q.push(p->right);
                }
            }
            unordered_map<TreeNode*, int> vis;
            q.push(target);
            vis[target] = 1;
            int dis = 0;
            while(!q.empty() && dis<k){
                dis++;
                int len = q.size();
                for(int i = 0; i<len; i++){
                    TreeNode* current = q.front();
                    q.pop();
                    TreeNode *up = nullptr, *l = nullptr, *r = nullptr;
                    if(parent[current]){
                        up = parent[current];
                    }
                    if(current->left){
                        l = current->left;
                    }
                    if(current->right){
                        r = current->right;
                    }
                    if(up && !vis[up]){
                        vis[up] = 1;
                        q.push(up);
                    }
                    if(l && !vis[l]){
                        vis[l] = 1;
                        q.push(l);
                    }
                    if(r && !vis[r]){
                        vis[r] = 1;
                        q.push(r);
                    }
                }
            }
            vector<int> ans;
            while(!q.empty()){
                ans.push_back(q.front()->val);
                q.pop();
            }
            return ans;
        }
    };