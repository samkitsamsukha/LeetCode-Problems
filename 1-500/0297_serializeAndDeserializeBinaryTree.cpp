/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:

Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 104].
    -1000 <= Node.val <= 1000


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    public:
        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            if(!root) return "";
            string ser = "";
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                auto p = q.front();
                q.pop();
                if(!p) ser.append("#,");
                else ser.append(to_string(p->val)+',');
                if(p){
                    q.push(p->left);
                    q.push(p->right);
                }
            }
            return ser;
        }
    
        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            if(data.length()==0) return nullptr;
            queue<TreeNode*> q;
            string temp = "";
            int pos = 0;
            while(pos<data.length()){
                if(data[pos]!=','){
                    temp = temp+data[pos];
                }
                else{
                    pos++;
                    break;
                }
                pos++;
            }
            q.push(new TreeNode(stoi(temp)));
            TreeNode* root = q.front();
            while(!q.empty()){
                int len = q.size();
                for(int i = 0; i<len; i++){
                    TreeNode* p = q.front();
                    q.pop();
                    temp = "";
                    while(pos<data.length()){
                        if(data[pos]!=','){
                            temp = temp+data[pos];
                        }
                        else{
                            pos++;
                            break;
                        }
                        pos++;
                    }
                    if(temp == "#"){
                        p->left = nullptr;
                    }
                    else{
                        p->left = new TreeNode(stoi(temp));
                        q.push(p->left);
                    }
                    temp = "";
                    while(pos<data.length()){
                        if(data[pos]!=','){
                            temp = temp+data[pos];
                        }
                        else{
                            pos++;
                            break;
                        }
                        pos++;
                    }
                    if(temp == "#"){
                        p->right = nullptr;
                    }
                    else{
                        p->right = new TreeNode(stoi(temp));
                        q.push(p->right);
                    }
                }
            }
            return root;
        }
    };
    
    // Your Codec object will be instantiated and called as such:
    // Codec ser, deser;
    // TreeNode* ans = deser.deserialize(ser.serialize(root));