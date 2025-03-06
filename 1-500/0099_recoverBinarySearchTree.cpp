/*
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

Example 1:

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

Example 2:

Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

 

Constraints:

    The number of nodes in the tree is in the range [2, 1000].
    -231 <= Node.val <= 231 - 1

 
Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?
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
        TreeNode* first;
        TreeNode* middle;
        TreeNode* last;
        TreeNode* prev;
        void f(TreeNode* root){
            if(!root) return;
            f(root->left);
            if(prev!=nullptr && prev->val > root->val){
                if(first){
                    last = root;
                }
                else{
                    first = prev;
                    middle = root;
                }
            }
            prev = root;
            f(root->right);
        }
        void recoverTree(TreeNode* root) {
            first = nullptr;
            middle = nullptr;
            last = nullptr;
            prev = new TreeNode(INT_MIN);
            f(root);
            if(first && last) {
                int temp = first->val;
                first->val = last->val;
                last->val = temp;
            }
            else{
                int temp = first->val;
                first->val = middle->val;
                middle->val = temp;
            }
        }
    };
    