class Solution {
public:
    // memoization
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n=matrix.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for (int i = 0; i <n; i++) dp[0][i]=matrix[0][i];

    for (int i = 1; i <n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int down=matrix[i][j]+dp[i-1][j];
            int left=matrix[i][j];
            if(j>=1)left+=dp[i-1][j-1];
            else left+=1e9;
            int right = matrix[i][j];
            if(j<n-1)right+=dp[i-1][j+1];
            else right+=1e9;

            dp[i][j]=min(min(down,left),right);
        }
    }
    int ans=INT_MAX;
    for (int j = 0; j< n; j++)
    {
        ans=min(ans,dp[n-1][j]);
    }
    return ans;
}
};