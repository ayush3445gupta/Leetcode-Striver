class Solution {
public:

int m,n;
int dp[51][51];
int solve(int row,int col,vector<vector<int>>& grid, vector<vector<int>>& moveCost){
    // basecase
    if(row==m-1)return grid[row][col];
    if(dp[row][col]!=-1)return dp[row][col];

    int ans=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans=min(ans,grid[row][col]+moveCost[grid[row][col]][i]+solve(row+1,i,grid,moveCost));
    }
    return dp[row][col]=ans;
}
int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    m=grid.size(),n=grid[0].size();
    // traverse from every cell in first row
    int res=INT_MAX;
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < n; i++){ 
        res=min(res,solve(0,i,grid,moveCost));
        }
    return res;
    }
};