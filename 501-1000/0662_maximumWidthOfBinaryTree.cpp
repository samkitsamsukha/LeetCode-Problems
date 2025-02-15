/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

 

Example 1:

Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Example 2:

Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Example 3:

Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).

 

Constraints:

    The number of nodes in the tree is in the range [1, 3000].
    -100 <= Node.val <= 100


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     unsigned long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(unsigned long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(unsigned long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        int widthOfBinaryTree(TreeNode* root) {
            int w = -1;
            queue<pair<TreeNode*, unsigned long long>> q;
            q.push({root, 0});
            while(!q.empty()){
                unsigned long long l = q.size();
                unsigned long long m = q.front().second;
                unsigned long long x, y;
                for(unsigned long long k = 0; k<l; k++){
                    TreeNode* n = q.front().first;
                    long i = q.front().second-m;
                    q.pop();
                    if(k==0) x = i;
                    if(k==l-1) y = i;
                    if(n->left) q.push({n->left, 2*i+1});
                    if(n->right) q.push({n->right, 2*i+2});
                }
                w = max(w, static_cast<int>(y-x+1));
            }
            return w;
        }
    };