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
//     int solve(TreeNode* node,int &maxi){
//     if(!node) return 0;
//     int l1=max(0,solve(node->left,maxi));  
//     int l2=max(0,solve(node->right,maxi));
//     maxi=max(maxi,l1+l2+node->val);
//     return max(l1,l2)+node->val;
// }
// int maxPathSum(TreeNode* root) {
//         int maxi=INT_MIN;
//         solve(root,maxi);
//         return maxi;
//     }

//  for each node calculate its left sum and right sum and then add its curr node val and keep track of max sum
int sum=INT_MIN;
int calculatesum(TreeNode* root){
    if(root==nullptr)return 0;

    int ls = calculatesum(root->left);
    int rs = calculatesum(root->right);

    sum=max(sum,root->val+ls+rs);
    return root->val+ls+rs;
}
int maxPathSum(TreeNode* root) {
    if(root==nullptr)return 0;

    calculatesum(root);
    return sum;
}
};