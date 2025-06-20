class Solution {
public:
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
   /*
   store in min heap (stops,dist,node)
   (0,0,0) -> 
   (1,500,2) -> (1,100,1)
   (1,100,1) X ->
   */

    vector<vector<pair<int,int>>>adj(n);
    for(auto it:flights){
        adj[it[0]].push_back({it[1],it[2]});
    }

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

    pq.push({0,{0,src}});

    vector<int>dist(n,1e5);
    dist[src]=0;

    int ans=INT_MAX;
    while (!pq.empty())
    {
        auto it = pq.top();
        int steps = it.first;
        int d = it.second.first;
        int node=it.second.second;

        pq.pop();
        if(node==dst && steps<=k+1){
            ans=min(ans,d);
            continue;
        }

        for(auto it:adj[node]){
            int adjNode = it.first;
            int adjDis = it.second;

            if(dist[adjNode]>d+adjDis){
                dist[adjNode] = d + adjDis;
                pq.push({steps+1,{d+adjDis,adjNode}});
            }
        }
    }
    if(ans==INT_MAX)return -1;
    return ans;
    }
};