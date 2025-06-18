class Solution {
public:
void bfs(int node,vector<vector<int>>&adj,vector<int>&vis){
    queue<int>que;
    que.push(node);
    vis[node]=1;

    while (!que.empty())
    {
        int curr=que.front();
        que.pop();

        for(auto it:adj[node]){
            if(!vis[it]){
                que.push(it);
                vis[it]=1;
            }
        }
    } 
}
int findCircleNum(vector<vector<int>>& isConnected) {
    // first solve using bfs
    int n=isConnected.size();
    vector<vector<int>>adj(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           if(isConnected[i][j]==1 && i!=j){
            adj[i].push_back(j);
           }
        }
    }
    vector<int>vis(n,0);
    int count=0;
    for (int i = 0; i <n; i++)
    {
      if(!vis[i]){
        bfs(i,adj,vis);
        count++;
      }
    }
    return count;
}
};