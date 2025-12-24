class Solution {
public:
//     int f(int row,int col,vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp){
//     if(obstacleGrid[row][col]==1)return 0;
//     // basecase
//     if(row==0 && col==0)return 1;
//     if(row<0 || col<0)return 0;

//     if(dp[row][col]!=-1)return dp[row][col];
//     int up=0,left=0;
//     if(row>0)up=f(row-1,col,obstacleGrid,dp);
//     if(col>0)left=f(row,col-1,obstacleGrid,dp);
//     return dp[row][col]=up+left;
// }
// int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
//     int n=obstacleGrid.size(),m=obstacleGrid[0].size();
//     vector<vector<int>>dp(m,vector<int>(n,-1));
//     return f(n-1,m-1,obstacleGrid,dp);
// }


// 18-07-25
// space optimised
// int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
//     int row=obstacleGrid.size(),col=obstacleGrid[0].size();
//     vector<int>prev(col,0);
//     if(obstacleGrid[0][0]==1 || obstacleGrid[row-1][col-1]==1)return 0;

//     for (int i = 0; i < row; i++)
//     {
//         vector<int>temp(col,0);
//         for (int j = 0; j < col; j++)
//         {
//             if(i==0 && j==0){
//             temp[j]=1;
//             continue;
//           }
//           if(obstacleGrid[i][j]==1){
//             temp[j]=0;
//             continue;
//           }
         
//           int down=0,right=0;
//           if(i>0)down=prev[j];
//           if(j>0)right=temp[j-1];

//           temp[j]=down+right;
//         }
//         prev=temp;
//         }
//     return prev[col-1];
// }


int m,n;
int dp[101][101];
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
    m=obstacleGrid.size();
    n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)return 0;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j && j==0){
                dp[i][j]=1;
                continue;
            }
           if(obstacleGrid[i][j]==1){
            dp[i][j]=0;continue;
           }
           int up=0,left=0;
           if(i>0)up=dp[i-1][j];
           if(j>0)left=dp[i][j-1];
            dp[i][j]=up+left;
        }
    }
    return dp[m-1][n-1];
}
};