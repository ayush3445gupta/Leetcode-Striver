class Solution {
public:
    class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
int makeConnected(int n, vector<vector<int>>& connections) {      
    DisjointSet ds(n);

    int components=0;
    int extra=0;
    for (int i = 0; i < connections.size(); i++)
    {
        if(ds.findUPar(connections[i][0])==ds.findUPar(connections[i][1]))extra++;
        ds.unionByRank(connections[i][0],connections[i][1]);
    }
    
    for (int i = 0; i < n; i++)
    {
        if(ds.findUPar(i)==i)components++;
    }
    if(extra>=components-1)return components-1;
    return -1;
}
};