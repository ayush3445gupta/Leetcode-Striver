/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
// TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//     if(root==NULL || root==p || root==q) return root;

//     TreeNode* left=lowestCommonAncestor(root->left,p,q);
//     TreeNode* right=lowestCommonAncestor(root->right,p,q);

//     if(!left) return right;
//     else if(!right) return left;
//     else return root;
//     }.
bool getArray(TreeNode* node,vector<int>&arr,TreeNode* k){
    if(!node) return false;

    arr.push_back(node->val);
    if(node->val==k->val)return true;
    if(getArray(node->left,arr,k) || getArray(node->right,arr,k))
    return true;

    arr.pop_back();
    return false;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int>arr1,arr2;
        getArray(root,arr1,p);
        getArray(root,arr2,q);
        TreeNode* node=root;
        for (int i=min(arr1.size(),arr2.size())-1;i>=0; i--)
        {
            if(arr1[i]==arr2[i]){
                node->val=arr1[i];
                break;
            }
        }
    return node;
    }
};