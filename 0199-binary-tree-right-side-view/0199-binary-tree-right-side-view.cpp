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
    // vector<int> rightSideView(TreeNode* root) {
    // queue<pair<TreeNode*,int>>pq;
    // pq.push({root,0});
    // map<int,int>mpp;
    // while (!pq.empty())
    // {
    //     int size=pq.size();
    //     for (int i = 0; i <size; i++)
    //     {
    //         auto p=pq.front();
    //         pq.pop();
    //         int line=p.second;
    //         TreeNode* node=p.first;
    //         mpp[line]=node->val;
    //         if(node->left)pq.push({node->left,line+1});
    //         if(node->right)pq.push({node->right,line+1});
    //     }
    // }
    //  vector<int>ans;
    //     for(auto it:mpp){
    //         ans.push_back(it.second);
    //     }
    //     return ans;
    // }

    vector<int> rightSideView(TreeNode* root) {
    // level wise traversal karo 
    if(!root)return {};
    vector<int>res;
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    map<int,int>mp;
    while (!q.empty())
    {
        auto p=q.front();
        q.pop();
        TreeNode* node=p.first;
        int y=p.second;
        mp[y]=node->val;
        if(node->left)q.push({node->left,y+1});
        if(node->right)q.push({node->right,y+1});
    }
    for(auto it:mp)res.push_back(it.second);
    return res;
}
};