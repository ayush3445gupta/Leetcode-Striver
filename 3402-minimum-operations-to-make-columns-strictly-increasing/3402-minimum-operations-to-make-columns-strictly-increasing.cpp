class Solution {
public:
typedef long long ll;
int minimumOperations(vector<vector<int>>& grid) {
    int n = grid.size(),m=grid[0].size();
    ll ans=0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
           if(grid[j][i]<=grid[j-1][i]){
            ans+=(grid[j-1][i]-grid[j][i]+1);
            grid[j][i]=grid[j-1][i]+1;
           }
        }
    }
        return ans;
    }
};