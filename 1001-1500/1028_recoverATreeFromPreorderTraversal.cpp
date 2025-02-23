/*
We run a preorder depth-first search (DFS) on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child.

Given the output traversal of this traversal, recover the tree and return its root.

 

Example 1:

Input: traversal = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]

Example 2:

Input: traversal = "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]

Example 3:

Input: traversal = "1-401--349---90--88"
Output: [1,401,null,349,88,90]

 

Constraints:

    The number of nodes in the original tree is in the range [1, 1000].
    1 <= Node.val <= 109


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
        int dashes(string &s, int n, int &p){
            int len = 0;
            while(p<n && s[p]=='-'){
                len++;
                p++;
            }
            return len;
        }
        int value(string&s, int n, int &p){
            int num = 0;
            while(p<n && s[p]>='0' && s[p]<='9'){
                num = num*10 + (s[p]-'0');
                p++;
            }
            return num;
        }
        void buildTree(TreeNode* root, int exp, int &p, int n, string s){
            if(p>=n) return;
            int prev = p;
            int dash = dashes(s, n, p);
            if(dash < exp){ // base case ho gaya yeh
                p = prev;
                return;
            }
            int x = value(s, n, p);
            TreeNode* temp = new TreeNode(x);
            if(!root->left) root->left = temp;
            else root->right = temp;
            buildTree(temp, exp+1, p, n, s);
            buildTree(temp, exp+1, p, n, s);
        }
        TreeNode* recoverFromPreorder(string s) {
            int n = s.length();
            int p = 0;
            TreeNode* root = new TreeNode(value(s, n, p));
            buildTree(root, 1, p, n, s);
            buildTree(root, 1, p, n, s);
            return root;
        }
    };