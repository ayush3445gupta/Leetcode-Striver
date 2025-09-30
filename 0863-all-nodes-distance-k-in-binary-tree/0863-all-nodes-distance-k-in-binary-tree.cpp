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
//     void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent,TreeNode* target){
//     queue<TreeNode*>pq;
//     pq.push(root);
//     while (!pq.empty())
//     {
//         TreeNode* curr=pq.front();
//         pq.pop();
//         if(curr->left){
//             parent[curr->left]=curr;
//             pq.push(curr->left);
//         }
//         if(curr->right){
//             parent[curr->right]=curr;
//             pq.push(curr->right);
//         }
//     } 
// }
// vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//        unordered_map<TreeNode*,TreeNode*>parent;
//        markParent(root,parent,target);

//        unordered_map<TreeNode*,bool>visited;
//        int dist=0;
//        queue<TreeNode*>pq;
//        pq.push(target);
//        visited[target]=true;
//        while (!pq.empty())
//        {
//         int size=pq.size();
//         if(dist==k) break;
//         for (int i = 0; i <size; i++)
//         {
//             TreeNode* curr=pq.front();
//             pq.pop();
//             if(curr->left && !visited[curr->left]){
//                 pq.push(curr->left);
//                 visited[curr->left]=true;
//             }
//             if(curr->right && !visited[curr->right]){
//                 pq.push(curr->right);
//                 visited[curr->right]=true;
//             }
//             if(parent[curr] && !visited[parent[curr]]){
//                 pq.push(parent[curr]);
//                 visited[parent[curr]]=true;
//             }
//         }
//         dist++;
//        }
//     vector<int>ans;
//     while (!pq.empty())
//     {
//         ans.push_back(pq.front()->val);
//         pq.pop();
//     }
//      return ans; 
//     }

void assignParent(TreeNode* parent,TreeNode*node,unordered_map<TreeNode*,TreeNode*>&mp){
    if(!node)return;
    if(parent!=node){
        mp[node]=parent;
    }
    assignParent(node,node->left,mp);
    assignParent(node,node->right,mp);
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    // first traverse from root to target and count step

    vector<int>arr;
    unordered_map<TreeNode*,TreeNode*>parent;
    assignParent(root,root,parent);
    unordered_map<TreeNode*,bool>visited;
    int dist=0;
    queue<TreeNode*>q;
    q.push(target);
    visited[target]=true;
    while (!q.empty())
    {
        if(dist==k)break;
        int size=q.size();

        for (int i = 0; i < size; i++)
        {
           TreeNode* curr=q.front();
           q.pop();
           if(curr->left && !visited[curr->left]){
            q.push(curr->left);
            visited[curr->left]=true;
           }
           if(curr->right && !visited[curr->right]){
            q.push(curr->right);
            visited[curr->right]=true;
           }
           if(parent[curr] && !visited[parent[curr]]){
            q.push(parent[curr]);
            visited[parent[curr]]=true;
           }
        }
        dist++;
    }
    while (!q.empty())
    {
        arr.push_back(q.front()->val);
        q.pop();
    }
    return arr;
}
};