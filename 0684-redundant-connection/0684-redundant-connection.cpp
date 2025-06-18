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

    int findUlPar(int node){
        if(node==parent[node])return node;

        return parent[node]=findUlPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int uu=findUlPar(u),uv=findUlPar(v);

        if(uu==uv)return;

        if(rank[uu]>rank[uv])parent[uv]=uu;
        else if (rank[uu]<rank[uv])parent[uu]=uv;
        else{
            rank[uu]++;
            parent[uv]=uu;
        }
    }
};
class Solution {
public:
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
     int n=edges.size();   
     DisjointSet ds(n+1);
     vector<int>ans{-1,-1};
     for(auto it:edges){
        int u=it[0],v=it[1];

        if(ds.findUlPar(u)==ds.findUlPar(v)){
            ans[0]=u,ans[1]=v;
        }
        else ds.unionByRank(u,v);
     }
     return ans;
    }
};