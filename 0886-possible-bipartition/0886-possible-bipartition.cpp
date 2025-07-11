class Solution {
public:
bool check(int start,vector<vector<int>>& dislikes,vector<vector<int>>&adj,vector<int>&color){

        queue<int>q;
        q.push(start);
        color[start]=1;
        while (!q.empty())
            {
                int node=q.front();
                q.pop();
                
                for(auto it:adj[node]){
                    if(color[it]==-1){
                        color[it]=!color[node];
                        q.push(it);
                    }
                    else if (color[it]==color[node])
                return false;
                }
            }
            return true;
}
bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    //  check bipartite graph
    vector<vector<int>>adj(n+1);
    for(auto it:dislikes){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int>color(n+1,-1);
    for (int i = 1; i <=n; i++)
    {
        if(color[i]==-1){
            if(check(i,dislikes,adj,color)==false)return false;
        }
    }
    return true;
}
};