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
void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parents){
    queue<TreeNode*>pq;
    pq.push(root);
    while (!pq.empty())
    {
        TreeNode* curr=pq.front();
        pq.pop();
        if(curr->left){
            parents[curr->left]=curr;
            pq.push(curr->left);
        }
        if(curr->right){
            parents[curr->right]=curr;
            pq.push(curr->right);
        }
    } 
}
TreeNode* findNode(TreeNode* root,int start){
    if(!root || root->val==start)return root;
    TreeNode* left=findNode(root->left,start);
    if(left)return left;
    return findNode(root->right,start);
}
// int amountOfTime(TreeNode* root, int start) {
//       unordered_map<TreeNode*,TreeNode*>parents;
//       markParents(root,parents);  
//       TreeNode*temp= findNode(root,start);
//       int dist=0;
//       queue<TreeNode*>q;
//       q.push(temp);
//       unordered_map<TreeNode*,bool>visited;
//       visited[temp]=true;
//       while (!q.empty())
//       {
//         int size=q.size();
//         int fl=0;
//         for (int i = 0; i < size; i++)
//         {
//         TreeNode* curr=q.front();q.pop();
//         if(curr->left && !visited[curr->left]){
//             fl=1;
//             q.push(curr->left);
//             visited[curr->left]=true;
//         }
//         if(curr->right && !visited[curr->right]){
//             fl=1;
//             q.push(curr->right);
//             visited[curr->right]=true;
//         }
//         if(parents[curr] && !visited[parents[curr]]){
//             q.push(parents[curr]);
//             fl=1;
//             visited[parents[curr]]=true;
//         }
//       }
//       if(fl)dist++;
//       }
//       return dist;
//     }

void assignParent(TreeNode* parent,TreeNode*node,unordered_map<TreeNode*,TreeNode*>&mp){
    if(!node)return;
    if(parent!=node){
        mp[node]=parent;
    }
    assignParent(node,node->left,mp);
    assignParent(node,node->right,mp);
}
TreeNode* track(TreeNode*node,int start){
    if(!node || node->val==start)return node;
    TreeNode* left=track(node->left,start);
    if(left)return left;
    return track(node->right,start);
}
int amountOfTime(TreeNode* root, int start) {
    unordered_map<TreeNode*,TreeNode*>parent;
    unordered_map<TreeNode*,bool>visited;
    assignParent(root,root,parent);
    TreeNode* target=track(root,start);
    int maxTime=0,curr_time=0;
    queue<TreeNode*>q;
    q.push(target);
    visited[target]=true;
    while (!q.empty())
    {
        int size=q.size();
        int fl=0;
        for (int i = 0; i < size; i++)
        {
            TreeNode* curr_node = q.front();
            q.pop();
            if(curr_node->left && !visited[curr_node->left]){
                q.push(curr_node->left);
                fl=1;
                visited[curr_node->left]=true;
            }
            if(curr_node->right && !visited[curr_node->right]){
                q.push(curr_node->right);
                fl=1;
                visited[curr_node->right]=true;
            }
            if(parent[curr_node] && !visited[parent[curr_node]]){
                q.push(parent[curr_node]);
                fl=1;
                visited[parent[curr_node]]=true;
            }
        }
        if(fl)curr_time++;
        maxTime=max(maxTime,curr_time);
    }
    return maxTime;
}
};