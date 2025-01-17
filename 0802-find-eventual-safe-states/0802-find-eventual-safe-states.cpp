class Solution {
public:
bool dfs(int node,vector<vector<int>>& graph,vector<int>& vis, vector<int>& pathvis, vector<int>& check){
    vis[node]=1,pathvis[node]=1;

    for(auto it:graph[node]){
        if(!vis[it]){
            if(dfs(it,graph,vis,pathvis,check)==true)
            return true;
        }
        else if(pathvis[it])return true;
    }
    check[node]=1;
    pathvis[node]=0;
    return false;

}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();
        vector<int> vis(V, 0), pathvis(V, 0), check(V, 0);
        vector<int> safenodes;
      for (int i = 0; i < V; i++)
      {
        if(!vis[i])dfs(i,graph,vis,pathvis,check);
      }
      for (int i = 0; i < V; i++)
      {
        if(check[i]==1)safenodes.push_back(i);
      }

      return safenodes;
    }   
};