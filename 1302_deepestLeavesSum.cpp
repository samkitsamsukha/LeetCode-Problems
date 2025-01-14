/*
Given the root of a binary tree, return the sum of values of its deepest leaves.

 

Example 1:

Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19

 

Constraints:

    The number of nodes in the tree is in the range [1, 104].
    1 <= Node.val <= 100

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
    int ans = 0;
    int max = 0;
    void preorder(TreeNode* root, int x){    
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            if(x == max){
                ans = ans + root->val;
            }
            if(x > max){
                ans = 0;
                max = x;
                ans = ans+root->val;
            }
        }
        preorder(root->left, x+1);
        preorder(root->right, x+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        preorder(root, 1);
        return ans;
    }
};