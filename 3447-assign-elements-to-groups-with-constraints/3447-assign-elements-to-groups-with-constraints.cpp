class Solution {
public:
vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
    int n=groups.size(),m=elements.size();
    vector<int>vis(n,0);
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
           if(groups[j]%elements[i]==0 && !vis[j]){
            groups[j]=i;
            vis[j]=1;
           }
        }
    }
    for (int i = 0; i < n; i++)
    {
       if(!vis[i])groups[i]=-1;
    }
    return groups;
    }
};