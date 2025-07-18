class Solution {
public:
// int f(int row,int prevcol,int n,vector<vector<int>>& dp,vector<vector<int>>& grid){
//     // basecase
//     if(row==0){
//         int mx=INT_MAX;
//         for (int i = 0; i < n; i++)
//         {
//            if(i!=prevcol)mx=min(mx,grid[0][i]);
//         }
//         return mx;
//     }
//     if (dp[row][prevcol] != -1) return dp[row][prevcol];
//     int mx=INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         if(i!=prevcol){
//             int score=grid[row][i]+f(row-1,i,n,dp,grid);
//             mx=min(mx,score);
//         }
//     }
//     return dp[row][prevcol]=mx;
// }
// int minFallingPathSum(vector<vector<int>>& grid) {
//     int n=grid.size();
//     vector<vector<int>>dp(n,vector<int>(n+1,-1));
//     int ans=INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//        ans=min(ans,f(n-1,n,n,dp,grid));
//     }
//     return ans;
//     }

int minFallingPathSum(vector<vector<int>>& grid) {
    int n=grid.size();
    vector<vector<int>>dp(n,vector<int>(n+1,0));
    for (int i = 0; i < n; i++)
    dp[0][i]=grid[0][i];

    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        int temp=INT_MAX;
        for (int k = 0; k < n; k++)
        {
           if(k!=j)temp=min(temp,grid[i][j]+dp[i-1][k]);
        }
        dp[i][j]=temp;
      }
    }
    int ans=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans=min(ans,dp[n-1][i]);
    }
    return ans;
    }
};