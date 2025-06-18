class Solution {
public:
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
        if(vis[i])continue;

        queue<int>que;
        que.push(i);
        vis[i]=1;

        while (!que.empty())
        {
            int u=que.front();
            que.pop();

            for(int v:adj[u]){
                if(!vis[v]){
                    que.push(v);
                    vis[v]=1;
                }
            }
        }
        count++;
    }
    return count;
}
};