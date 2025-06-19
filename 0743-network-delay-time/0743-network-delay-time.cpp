class Solution {
public:
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
     vector<int>dist(n+1,1e5);
     vector<vector<pair<int,int>>>adj(n+1);

     for(auto it:times){
        adj[it[0]].push_back({it[1],it[2]});
     }

     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minhp;

     minhp.push({0,k});
     dist[k]=0;

     while (!minhp.empty())
     {
        auto it=minhp.top();
        minhp.pop();
        int t=it.first;
        int node=it.second;

        for(auto it:adj[node]){
            int adjNode=it.first;
            int edgeW = it.second;

            if(dist[adjNode]>t+edgeW){
                minhp.push({t+edgeW,adjNode});
                dist[adjNode]=t+edgeW;
            }
        }
     }
     int ans=0;
     for (int i = 1; i <=n; i++)
     {
        if(dist[i]==1e5)return -1;
        ans=max(ans,dist[i]);
     }
     return ans;
    }
};