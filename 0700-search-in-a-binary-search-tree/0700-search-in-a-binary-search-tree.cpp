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
TreeNode* findnode(TreeNode* node,int val){
    if(!node)return nullptr;
    if(node->val==val)return node;
    if(node->val>val)return findnode(node->left,val);
    else return findnode(node->right,val);
}
TreeNode* searchBST(TreeNode* root, int val) {
       if(!root)return nullptr;
       return findnode(root,val); 
    }
};