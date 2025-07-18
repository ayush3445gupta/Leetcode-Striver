class Solution {
public:
int f(int row,int prevcol,int n,vector<vector<int>>& dp,vector<vector<int>>& grid){
    // basecase
    if(row==0){
        int mx=INT_MAX;
        for (int i = 0; i < n; i++)
        {
           if(i!=prevcol)mx=min(mx,grid[0][i]);
        }
        return mx;
    }

    int mx=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(i!=prevcol){
            int score=grid[row][i]+f(row-1,i,n,dp,grid);
            mx=min(mx,score);
        }
    }
    return dp[row][prevcol]=mx;
}
int minFallingPathSum(vector<vector<int>>& grid) {
    int n=grid.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    int ans=INT_MAX;
    for (int i = 0; i < n; i++)
    {
       ans=min(ans,f(n-1,n,n,dp,grid));
    }
    return ans;
    }
};