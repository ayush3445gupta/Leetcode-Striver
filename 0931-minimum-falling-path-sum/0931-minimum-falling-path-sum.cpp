class Solution {
public:
    // memoization
int f(int row,int col,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp){
    // basecase
    if(row==0 && col<n && col>=0)return matrix[row][col];
    if(row<0 || col<0 || col>=n)return 1e9;

    if(dp[row][col]!=-1)return dp[row][col];
    int up=matrix[row][col]+f(row-1,col,n,matrix,dp);
    int left=matrix[row][col]+f(row-1,col-1,n,matrix,dp);;
    int right=matrix[row][col]+f(row-1,col+1,n,matrix,dp);

    return dp[row][col]=min(min(up,left),right);
}
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n=matrix.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    int ans=INT_MAX;
    for (int j = 0; j < n; j++)
    {
        ans=min(ans,f(n-1,j,n,matrix,dp));
    }
    return ans;
}
};