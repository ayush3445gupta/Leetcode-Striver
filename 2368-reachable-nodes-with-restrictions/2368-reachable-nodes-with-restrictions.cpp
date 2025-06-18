class Solution {
public:
void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,int& count){
    vis[node]=1;
    count++;
    for(auto it:adj[node]){
        if(!vis[it])
        dfs(it,adj,vis,count);
    }
    return;
}
int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
  // we will apply BFS
  vector<vector<int>>adj(n);

  for(auto it:edges){
    adj[it[1]].push_back(it[0]);
    adj[it[0]].push_back(it[1]);
  }

    vector<int>vis(n,0);
    vis[0]=1;
    for(auto it:restricted)vis[it]=1;
    int count=0;

                            // queue<int>que;
                            // que.push(0);
                            // while (!que.empty())
                            // {
                            //     int node=que.front();
                            //     que.pop();
                            //     count++;
                            //     for(auto it:adj[node]){
                            //         if(!vis[it] && st.find(it)==st.end()){
                            //             vis[it]=1;
                            //             que.push(it);
                            //         }
                            //     }
                            // }

    // DFS
     dfs(0,adj,vis,count);
return count;
}
};