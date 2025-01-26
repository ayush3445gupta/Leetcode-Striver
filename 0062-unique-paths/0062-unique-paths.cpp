class Solution {
public:
//     int f(int row,int col,vector<vector<int>>&dp){
//     // basecase
//     if(row==0 || col==0)return 1;
//     if(dp[row][col]!=-1)return dp[row][col];
//     int up=f(row-1,col,dp);
//     int left=f(row,col-1,dp);
//     return dp[row][col]=up+left;
// }
// // memoization
// // either up or left
// int uniquePaths(int m, int n) {
//     vector<vector<int>>dp(m,vector<int>(n,-1));
//     return f(m-1,n-1,dp);
// }.
// int uniquePaths(int m, int n) {
//     vector<vector<int>>dp(m,vector<int>(n,-1));
//     for (int row= 0; row < m; row++)dp[row][0]=1;
//     for (int col= 0; col < n; col++)dp[0][col]=1;

//     for (int i = 1; i <m; i++)
//     {
//         for (int j = 1; j < n; j++)
//         {
//            int down=dp[i-1][j];
//            int right=dp[i][j-1];

//            dp[i][j]=down+right;
//         }    
//     }
//     return dp[m-1][n-1];    
// }
int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n,-1));
    vector<int>prev(n,1);
    // for (int row= 0; row < m; row++)dp[row][0]=1;
    // for (int col= 0; col < n; col++)dp[0][col]=1;

    for (int i = 1; i <m; i++)
    {
        vector<int>temp(n,1);
        for (int j = 1; j < n; j++)
        {
           int down=prev[j];
           int right=temp[j-1];

           temp[j]=down+right;
        }  
        prev=temp;  
    }
    return prev[n-1];    
}
};