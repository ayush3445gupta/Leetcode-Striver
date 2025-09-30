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
typedef long long ll;
int widthOfBinaryTree(TreeNode* root) {
     if(!root)return 0;
     queue<pair<TreeNode*,ll>>q;
     q.push({root,1});
     int maxwidth=0;
     while (!q.empty())
     {
        int size=q.size();
        ll mmin=q.front().second;
        int mnx,mxx;
        for (int i = 0; i < size; i++)
        {
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            ll x=it.second-mmin;
            if(i==0)mnx=x;
            if(i==size-1)mxx=x;
            if(node->left)q.push({node->left,2*x+1});
            if(node->right)q.push({node->right,2*x+2});
        }
        maxwidth=max(maxwidth,mxx-mnx+1);
     }
     return maxwidth;
    } 
};