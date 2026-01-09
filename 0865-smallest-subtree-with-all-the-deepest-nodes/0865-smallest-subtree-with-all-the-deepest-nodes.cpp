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
bool check_all_same(vector<TreeNode*>vec){
    int n=vec.size();
    for (int i = 0; i < n-1; i++)
    {
        if(vec[i]!=vec[i+1])return false;
    }
    return true;
}
TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    // work flow assign parent to each node , 
    vector<TreeNode*>par(501);
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});

    par[root->val]=root;
    vector<TreeNode*>leaves;

    while (!q.empty())
    {
        int sz=q.size();
        vector<TreeNode*>curr;
        for (int i = 0; i < sz; i++)
        {
            TreeNode* node=q.front().first;
            int level=q.front().second;
            q.pop();
            curr.push_back(node);
            if(node->left){
                par[node->left->val]=node;
                q.push({node->left,level+1});
            }
            if(node->right){
                par[node->right->val]=node;
                q.push({node->right,level+1});
            }
        }
        leaves=curr;
    }
    while (!check_all_same(leaves))
    {
        for (int i = 0; i < leaves.size(); i++)
           leaves[i]=par[leaves[i]->val];
    }
    return leaves[0];
    }
};