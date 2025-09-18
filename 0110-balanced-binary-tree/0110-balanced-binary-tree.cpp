/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    //     int depth(TreeNode* node){
    //     if(!node) return 0;
    //     int lh=depth(node->left);
    //     int rh=depth(node->right);
    //     return 1+max(lh,rh);

    // }
    // bool isBalanced(TreeNode* root) {
    //         if(!root) return true;
    //         int l1=depth(root->left);
    //         int l2=depth(root->right);
    //         if(abs(l1-l2)>1) return false;

    //        return isBalanced(root->left) && isBalanced(root->right);
    //     }

int depth(TreeNode* root){
    if(root==nullptr)return 0;
    int lh = depth(root->left);
    int rh = depth(root->right);

    return 1+max(lh,rh);
}
bool isBalanced(TreeNode* root) {
    if(root==nullptr)return true;
    int ld = depth(root->left);
    int rd = depth(root->right);

    if(abs(ld-rd)>1)return false;

    return isBalanced(root->left) && isBalanced(root->right);
    }
};