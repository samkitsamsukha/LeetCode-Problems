/*
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.

 

Example 1:

Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]

Example 2:

Input: preorder = [1], postorder = [1]
Output: [1]

 

Constraints:

    1 <= preorder.length <= 30
    1 <= preorder[i] <= preorder.length
    All the values of preorder are unique.
    postorder.length == preorder.length
    1 <= postorder[i] <= postorder.length
    All the values of postorder are unique.
    It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    public:
        map<int, int> postMap;
        TreeNode* buildTree(vector<int> pre, int pres, int pree, vector<int> post, int posts, int poste) {
            if (pres > pree || posts > poste) return nullptr;
            TreeNode* root = new TreeNode(pre[pres]);
            if (pres == pree) return root;
            int lc = pre[pres + 1];
            int lcp = postMap[lc];
            int leftsize = lcp - posts + 1;
            root->left = buildTree(pre, pres + 1, pres + leftsize, post, posts, lcp);
            root->right = buildTree(pre, pres + leftsize + 1, pree, post, lcp + 1, poste - 1);
            return root;
        }
        TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
            for (int i = 0; i < pre.size(); i++) {
                postMap[post[i]] = i;
            }
            TreeNode* root = buildTree(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
            return root;
        }
    };