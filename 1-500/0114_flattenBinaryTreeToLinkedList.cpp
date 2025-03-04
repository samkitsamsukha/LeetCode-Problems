/*
Given the root of a binary tree, flatten the tree into a "linked list":

    The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
    The "linked list" should be in the same order as a pre-order traversal of the binary tree.

 

Example 1:

Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [0]
Output: [0]

 

Constraints:

    The number of nodes in the tree is in the range [0, 2000].
    -100 <= Node.val <= 100

 
Follow up: Can you flatten the tree in-place (with O(1) extra space)?
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
        void find(TreeNode* head, TreeNode*& last){
            if (!head) return;
            last = head;
            find(head->left, last);
            find(head->right, last);
        }
        void flatten(TreeNode* root) {
            if(!root) return;
            // cout << "Current root: " << root->val << endl;
            if(root->left){
                TreeNode* last = nullptr;
                find(root->left, last);
                // cout << "last->val: " << last->val << endl;
                // if(last->right && root->right) cout << "Connected " << last->right->val << " to " << root->right->val << endl;
                last->right = root->right;
                // if(root->right && root->left) cout << "Connected " << root->left->val << " to " << root->right->val << endl;
                root->right = root->left;
                // if(root->left) cout << "Connected " << root->left->val << " to nullptr" << endl;
                root->left = nullptr; 
            }
            if(root->right) flatten(root->right);
        }
    };