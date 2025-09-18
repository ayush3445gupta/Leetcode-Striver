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
//     int solve(TreeNode* node,int& dia){
//     if(!node) return 0;
    
//     int lh=solve(node->left,dia);
//     int rh=solve(node->right,dia);
//     dia=max(dia,lh+rh);
//     return 1+max(lh,rh);
// }
// int diameterOfBinaryTree(TreeNode* root) {
//         int dia=0;
//         solve(root,dia);
//         return dia;
//     }
int maxDepth(TreeNode* root,int& dia){
    if(root==nullptr)return 0;

    int lh = maxDepth(root->left,dia);
    int rh = maxDepth(root->right,dia);
    dia =  max(dia,lh+rh);
    return 1+max(lh,rh);
}
int diameterOfBinaryTree(TreeNode* root) {
    if(root==nullptr)return 0;

    int dia=0;
    maxDepth(root,dia);
    return dia;
}
};