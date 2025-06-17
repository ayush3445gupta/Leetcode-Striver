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
    int findUltimateParent(int node){
        if(node==parent[node])return node;

        return findUltimateParent(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u = findUltimateParent(u),ulp_v=findUltimateParent(v);

        if(ulp_u==ulp_v)return;
        if(ulp_u>ulp_v)parent[ulp_u]=ulp_v;
        else  parent[ulp_v]=ulp_u;
    }
};
class Solution {
public:
string smallestEquivalentString(string s1, string s2, string baseStr) {
    DisjointSet ds(26);
    
    for (int i = 0; i < s1.length(); i++)
    {
       int c1=s1[i]-'a',c2=s2[i]-'a';
       if(c1>c2)ds.unionByRank(c2,c1);
       else ds.unionByRank(c1,c2);
    }
    string ans;
    for (int i = 0; i < baseStr.length(); i++)
    {
        char ch=baseStr[i];
        ans+=(ds.findUltimateParent(ch-'a')+'a');
    }
    return ans;
    }
};