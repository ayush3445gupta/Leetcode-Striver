class DisjointSet{
    vector<int>rank,parent;
public:
     DisjointSet(int n){
        rank.resize(n,0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
          parent[i]=i;
        }
     }
    
    int findUltimateParent(int node){
        if(node==parent[node])return node;

        return findUltimateParent(parent[node]);
    }
    void UnionByRank(int u,int v){
        int ulp_u = findUltimateParent(u) , ulp_v = findUltimateParent(v);

        if(ulp_u==ulp_v)return;
        
        if(rank[ulp_u]>rank[ulp_v])parent[ulp_v]=ulp_u;
        else if (rank[ulp_u]<rank[ulp_v]) parent[ulp_u]=ulp_v;
        else{
            rank[ulp_u]++;
            parent[ulp_v]=ulp_u;
        }    
    }
};
class Solution {
public:
// void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,int& count){
//     vis[node]=1;
//     count++;
//     for(auto it:adj[node]){
//         if(!vis[it])
//         dfs(it,adj,vis,count);
//     }
//     return;
// }
// int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
//   // we will apply BFS
//   vector<vector<int>>adj(n);

//   for(auto it:edges){
//     adj[it[1]].push_back(it[0]);
//     adj[it[0]].push_back(it[1]);
//   }

//     vector<int>vis(n,0);
//     vis[0]=1;
//     for(auto it:restricted)vis[it]=1;
//     int count=0;

//                             // queue<int>que;
//                             // que.push(0);
//                             // while (!que.empty())
//                             // {
//                             //     int node=que.front();
//                             //     que.pop();
//                             //     count++;
//                             //     for(auto it:adj[node]){
//                             //         if(!vis[it] && st.find(it)==st.end()){
//                             //             vis[it]=1;
//                             //             que.push(it);
//                             //         }
//                             //     }
//                             // }

//     // DFS
//      dfs(0,adj,vis,count);
// return count;
// }


// DSU
int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
    unordered_set<int>st(restricted.begin(),restricted.end());

    DisjointSet ds(n);
    for(auto it:edges){
        if(st.find(it[0])==st.end() && st.find(it[1])==st.end()){
            ds.UnionByRank(it[0],it[1]);
        } 
    }
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if(ds.findUltimateParent(i)==ds.findUltimateParent(0))count++;
    }
    return count;
}
};