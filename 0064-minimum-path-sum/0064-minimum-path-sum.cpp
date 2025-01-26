class Solution {
public:
//     int solve(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&dp){
//     // basecase
//     if(row<0 || col<0) return 1e9;
//     if(row==0 && col==0) return grid[0][0];

//     if(dp[row][col]!=-1)return dp[row][col];

//     int up=grid[row][col]+solve(row-1,col,grid,dp);
//     int left=grid[row][col]+solve(row,col-1,grid,dp);

//     return dp[row][col]=min(up,left);

// }
// int minPathSum(vector<vector<int>>& grid) {
//      int n=grid.size();
//      int m=grid[0].size();
//      vector<vector<int>>dp(n,vector<int>(m,-1));
//      return solve(n-1,m-1,grid,dp);   
//     }

// int minPathSum(vector<vector<int>>& grid) {
//      int n=grid.size();
//      int m=grid[0].size();
//      vector<vector<int>>dp(n,vector<int>(m,0));
//       for (int row= 0; row<n; row++)
//       {
//         for (int col = 0; col<m; col++)
//         {
//            if(row==0 && col==0)dp[0][0]=grid[0][0];
//            else{
//             int up=grid[row][col];
//             if(row>0) up+=dp[row-1][col];
//             else up+=1e9;
//             int left=grid[row][col];
//             if(col>0) left+=dp[row][col-1];
//             else left+=1e9;
//             dp[row][col]=min(up,left);
//            }
//         }  
//       }
//       return dp[n-1][m-1];
//     }

int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size(),n=grid[0].size();
    vector<int>prev(n,0);
    // basecase
   
    for (int i = 0; i < m; i++)
    {
        vector<int>temp(n,0);
        for (int j = 0; j < n; j++)
        {
            if(i==0 && j==0)temp[j]=grid[i][j];
            else{
            int down=grid[i][j];
            int right=grid[i][j];
            if(i>0)down+=prev[j];
            else down+=1e9;

            if(j>0)right+=temp[j-1];
            else right+=1e9;

            temp[j]=min(down,right);
        }
        }
        prev=temp;
    }
    return prev[n-1];
}
};