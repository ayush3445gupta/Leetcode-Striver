class Solution {
public:
// vector<int>solve(vector<vector<int>>&adj,int node,string labels,int parent,vector<int>&ans){

//     char mylabel=labels[node];

//     vector<int>count_nodes(26,0);
//     count_nodes[mylabel-'a']=1;

//     for(int &it:adj[node]){
//         if(it==parent)continue;
//         vector<int>temp(26,0);
//         temp=solve(adj,it,labels,node,ans);
//         for (int i = 0; i < 26; i++)
//         count_nodes[i]+=temp[i];
        
//     }
//     ans[node]=count_nodes[mylabel-'a'];
//     return count_nodes;
// }
// vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
//      vector<vector<int>>adj(n);
//      for(auto it:edges){
//         adj[it[0]].push_back(it[1]);
//         adj[it[1]].push_back(it[0]);
//      }  
//      vector<int>ans(n);
//      solve(adj,0,labels,-1,ans);
//      return ans;
//     }

void solve(vector<vector<int>>&adj,int node,string& labels,int parent,vector<int>&ans,vector<int>&count){

    char mylabel = labels[node];
    int count_before_visitin_curr_children=count[mylabel-'a'];

    count[mylabel-'a']+=1;
    for(int &it:adj[node]){
        if(it==parent)continue;

        solve(adj,it,labels,node,ans,count);
    }

    int count_after_visiting_curr_children = count[mylabel-'a'];

    ans[node]=count_after_visiting_curr_children-count_before_visitin_curr_children;
    return;
}
vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
     vector<vector<int>>adj(n);
     for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
     }  
     vector<int>ans(n);
     vector<int>count(26,0);
     solve(adj,0,labels,-1,ans,count);
     return ans;
    }
};