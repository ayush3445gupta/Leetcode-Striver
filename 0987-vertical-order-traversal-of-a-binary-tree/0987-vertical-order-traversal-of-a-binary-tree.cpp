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
    // vector<vector<int>> verticalTraversal(TreeNode* root) {
    //     map<int,map<int,multiset<int>>>nodes;
    //     queue<pair<TreeNode*,pair<int,int>>>pq;
    //     pq.push({root,{0,0}});
    //     while (!pq.empty())
    //     {
    //         auto p=pq.front();
    //         pq.pop();
    //         TreeNode* node=p.first;
    //         int x=p.second.first,y=p.second.second;
    //         nodes[x][y].insert(node->val);
    //         if(node->left)pq.push({node->left,{x-1,y+1}});
    //         if(node->right) pq.push({node->right,{x+1,y+1}});

    //     }
    //     vector<vector<int>>ans;
    //     for(auto p:nodes){
    //         vector<int>col;
    //         for(auto q:p.second){
    //             col.insert(col.end(),q.second.begin(),q.second.end());
    //         }
    //         ans.push_back(col);
    //     }
    //     return ans;
    // }
void traverse(TreeNode* root,int x,int y,map<int,map<int,multiset<int>>>&mp){
    mp[x][y].insert(root->val);
    if(root->left)traverse(root->left,x-1,y+1,mp);
    if(root->right)traverse(root->right,x+1,y+1,mp);
}
vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>>ans;
    map<int,map<int,multiset<int>>>mp;
    traverse(root,0,0,mp);
    for(auto p:mp){
        vector<int>cols;
        for(auto q:p.second){
            cols.insert(cols.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(cols);
    }
    return ans;
    }
};