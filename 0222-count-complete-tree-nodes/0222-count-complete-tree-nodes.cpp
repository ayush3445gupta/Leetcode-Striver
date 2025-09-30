
class Solution {
public:
//    int solve(TreeNode* node,int &cnt){
//     if(!node) return 0;
//     cnt++;
//     solve(node->left,cnt);
//     solve(node->right,cnt);
//     return cnt;
// }
// int countNodes(TreeNode* root) {
//      if(!root) return 0;
//      int cnt=0;
//      return solve(root,cnt);   
//     } 
int countNodes(TreeNode* root) {
    if(!root)return 0;
    queue<TreeNode*>q;
    q.push(root);
    int cnt=0;
    while (!q.empty())
    {
        int size=q.size();
        cnt+=q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* node=q.front();
            q.pop();
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
    }
    return cnt;
}
};