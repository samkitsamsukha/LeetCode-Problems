/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 2000].
    -100 <= Node.val <= 100


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        int level = 0;
        // even = left - right
        // odd = right - left
        while(!q.empty()){
            int i = q.size();
            vector<int> a(i);
            for(int j = 0; j<i; j++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp && level%2 == 0){
                    a[j] = temp->val;
                }
                else if(temp && level%2 == 1){
                    a[i-j-1] = temp->val;
                }
                if(temp && temp->left) q.push(temp->left);
                if(temp && temp->right) q.push(temp->right);
            }
            if(a.size() > 0) ans.push_back(a);
            level++;
        }
        return ans;
    }
};