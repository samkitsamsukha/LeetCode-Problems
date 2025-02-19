/*
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

 

Example 1:

Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Example 2:

Input: preorder = [1,3]
Output: [1,null,3]

 

Constraints:

    1 <= preorder.length <= 100
    1 <= preorder[i] <= 1000
    All the values of preorder are unique.


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
        TreeNode* bstFromPreorder(vector<int>& a) {
            TreeNode* root = new TreeNode(a[0]);
            stack<TreeNode*> s;
            s.push(root);
            for (int i = 1; i < a.size(); i++) {
                TreeNode* node = new TreeNode(a[i]);
                if (a[i] < s.top()->val) {
                    s.top()->left = node;
                } else {
                    TreeNode* parent = nullptr;
                    while (!s.empty() && s.top()->val < a[i]) {
                        parent = s.top();
                        s.pop();
                    }
                    parent->right = node;
                }
                s.push(node);
            }
            return root;
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
        vector<int> in;
        map<int, int> inMap;
        TreeNode* generate(vector<int> pre, int ps, int pe, int is, int ie){
            if(ps>pe || is>ie) return nullptr;
            TreeNode* root = new TreeNode(pre[ps]);
            int inRoot = inMap[root->val];
            int numsLeft = inRoot - is;
            root->left = generate(pre, ps+1, ps+numsLeft, is, inRoot-1);
            root->right = generate(pre, ps+1+numsLeft, pe, inRoot+1, ie);
            return root;
        }
        TreeNode* bstFromPreorder(vector<int>& a) {
            in = a;
            sort(in.begin(), in.end());
            for(int i = 0; i<in.size(); i++){
                inMap[in[i]] = i;
            }
            TreeNode* root = generate(a, 0, a.size()-1, 0, in.size()-1);
            return root;
        }
    };
    