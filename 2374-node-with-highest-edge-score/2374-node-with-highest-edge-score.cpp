class Solution {
public:
typedef long long ll;
int edgeScore(vector<int>& edges) {
    int n = edges.size();
    
    vector<ll>indegree(n,0);
    for (int i = 0; i < n; i++)
    {
        indegree[edges[i]]+=i;
    }
    
    int maxNode=-1;
    int maxScore=LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
      if(indegree[i]>maxScore){
        maxScore=indegree[i];
        maxNode=i;
      }
    }
    return maxNode;
    }
};