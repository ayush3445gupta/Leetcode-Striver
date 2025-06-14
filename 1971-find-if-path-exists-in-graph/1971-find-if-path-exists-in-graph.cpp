class Solution {
public:
bool dfs(vector<vector<int>>& edges, int node, int destination,vector<int>&vis,int n,vector<vector<int>>&adj){
    vis[node]=1;

    if(node==destination)return true;
    for(auto it:adj[node]){
        if(!vis[it])if(dfs(edges,it,destination,vis,n,adj))return true;
    }
    return false;
}
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
 // using dfs
//  create adjacency list
    vector<vector<int>>adj(n);
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int>vis(n,0);
    return dfs(edges,source,destination,vis,n,adj);
    }
};