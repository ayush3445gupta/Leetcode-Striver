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
// void dfs(TreeNode* node,vector<string>&ans,string s){
//     if(!node) return;
//     s+=to_string(node->val);
//     if(!node->left && !node->right){
//        ans.push_back(s);
//     }
//     else{
//     dfs(node->left,ans,s+"->");
//     dfs(node->right,ans,s+"->");
//     }
// }
// vector<string> binaryTreePaths(TreeNode* root) {
//         if(!root) return {};
//         vector<string>ans;
//         dfs(root,ans,"");
//         return ans;
        
//     }
void fetch_paths(TreeNode* node,string &s,vector<string>&paths){
    int len=s.size();
    s+=to_string(node->val);
    if(!node->left && !node->right){
        paths.push_back(s);
    }
    else{
        s+="->";
    if(node->left)fetch_paths(node->left,s,paths);
    if(node->right)fetch_paths(node->right,s,paths);
}
s.resize(len);
}
vector<string> binaryTreePaths(TreeNode* root) {
    if(!root)return {};
    vector<string>paths;
    string path;
    fetch_paths(root,path,paths);
    return paths;
}
};