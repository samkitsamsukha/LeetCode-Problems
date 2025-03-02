/*
Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

 

Example 1:

Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.

Example 2:

Input: root = [1,null,2,null,0,3]
Output: 3

 

Constraints:

    The number of nodes in the tree is in the range [2, 5000].
    0 <= Node.val <= 105


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
        void minimum(TreeNode* root, int& mini){
            if(root == nullptr) return;
            if(root->val < mini){
                mini = root->val;
            }
            minimum(root->left, mini);
            minimum(root->right, mini);
        }
        void maximum(TreeNode* root, int& maxi){
            if(root == nullptr) return;
            if(root->val > maxi){
                maxi = root->val;
            }
            maximum(root->left, maxi);
            maximum(root->right, maxi);
        }
        int maxAncestorDiff(TreeNode* root) {
            if(!root) return 0;
            int mini = INT_MAX;
            int maxi = INT_MIN;
            minimum(root, mini);
            maximum(root, maxi);
            int ans = max(abs(root->val - mini), abs(root->val - maxi));
            // cout << "Current root: " << root->val << endl;
            // cout << "Minimum: " << mini << endl;
            // cout << "Maximum: " << maxi << endl;
            // cout << "Current ans : " << ans << endl;
            // cout << endl;
            return max(ans, max(maxAncestorDiff(root->left), maxAncestorDiff(root->right)));
        }
    };

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
        void f(TreeNode* root, int mini, int maxi){
            if(!root) return;
            ans = max(ans, max(abs(root->val - mini), abs(root->val - maxi)));
            mini = min(mini, root->val);
            maxi = max(maxi, root->val);
            f(root->left, mini, maxi);
            f(root->right, mini, maxi);
        }
        int maxAncestorDiff(TreeNode* root) {
            if(!root) return 0;
            int mini = root->val;
            int maxi = root->val;
            f(root, mini, maxi);
            return ans;
        }
    };