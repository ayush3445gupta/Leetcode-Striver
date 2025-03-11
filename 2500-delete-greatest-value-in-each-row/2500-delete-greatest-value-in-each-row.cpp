class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    for (int i = 0; i < n; i++)
    {
        sort(grid[i].begin(),grid[i].end());
    }
    int ans=0;
    for (int col = 0; col < m; col++)
    {
        int maxi=INT_MIN;
        for (int row = 0; row < n; row++)
        {
           maxi=max(maxi,grid[row][col]);
        }
        ans+=maxi;
    }
    return ans;  
}
};