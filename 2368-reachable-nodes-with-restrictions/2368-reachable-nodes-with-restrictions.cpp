class Solution {
public:
int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
  // we will apply BFS
  unordered_set<int>st(restricted.begin(),restricted.end());
  vector<vector<int>>adj(n);

  for(auto it:edges){
    adj[it[1]].push_back(it[0]);
    adj[it[0]].push_back(it[1]);
  }

    vector<int>vis(n,0);
    vis[0]=1;
    int count=0;
    queue<int>que;
    que.push(0);
    while (!que.empty())
    {
        int node=que.front();
        que.pop();
        count++;
        for(auto it:adj[node]){
            if(!vis[it] && st.find(it)==st.end()){
                vis[it]=1;
                que.push(it);
            }
        }
    }
return count;
}
};