/*
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

 

Example 1:

Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.

Example 2:

Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2

 

Constraints:

    The number of nodes in the tree is in the range [1, 104].
    -105 <= Node.val <= 105


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
        int maxLevelSum(TreeNode* root) {
            queue<TreeNode*> q;
            q.push(root);
            int ln = 1;
            int ans = 1;
            long long maxi = root->val;
            while(!q.empty()){
                long long sum = 0;
                int n = q.size();
                for(int i = 0; i<n; i++){
                    TreeNode* p = q.front();
                    sum = sum + p->val;
                    q.pop();
                    if(p->left) q.push(p->left);
                    if(p->right) q.push(p->right);
                }
                if(sum > maxi){
                    maxi = sum;
                    ans = ln;
                }
                ln++;
            }
            return ans;
        }
    };