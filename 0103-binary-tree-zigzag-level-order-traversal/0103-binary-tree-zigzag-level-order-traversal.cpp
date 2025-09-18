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
// vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//      vector<vector<int>>ans;
//      if(root==NULL)return ans;
//      queue<TreeNode*>q;
//      q.push(root);
//      bool LtoR=true;
//      while (!q.empty())
//      {
//         int size=q.size();
//         vector<int>levels(size);
//         for(int i=0;i<size;i++){
//             TreeNode* node=q.front();
//             q.pop();
//             int index=LtoR?i:size-i-1;
//             levels[index]=node->val;
//             if(node->left){
//                 q.push(node->left);
//             }
//             if(node->right) q.push(node->right);
//         }
//         LtoR=!LtoR;
//         ans.push_back(levels);
//      }
//     return ans;
//     }
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    if(root==nullptr)return ans;
    queue<TreeNode*>q;
    bool left=true;
    q.push(root);
    
    while (!q.empty())
    {
        int size=q.size();
        vector<int>level;
        for (int i = 0; i < size; i++)
        {
           TreeNode* curr=q.front();
           q.pop();
           level.push_back(curr->val);
           if(curr->left!=nullptr)q.push(curr->left);
           if(curr->right!=nullptr)q.push(curr->right);
        }
        if(left)ans.push_back(level);
        else{
            reverse(begin(level),end(level));
            ans.push_back(level);
        }
        left=!left;
    }
    return ans;
}
};