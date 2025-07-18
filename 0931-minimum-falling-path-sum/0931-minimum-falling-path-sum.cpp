class Solution {
public:
    // memoization
// int minFallingPathSum(vector<vector<int>>& matrix) {
//     int n=matrix.size();
//     vector<vector<int>>dp(n,vector<int>(n,0));
//     for (int i = 0; i <n; i++) dp[0][i]=matrix[0][i];

//     for (int i = 1; i <n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             int down=matrix[i][j]+dp[i-1][j];
//             int left=matrix[i][j];
//             if(j>=1)left+=dp[i-1][j-1];
//             else left+=1e9;
//             int right = matrix[i][j];
//             if(j<n-1)right+=dp[i-1][j+1];
//             else right+=1e9;

//             dp[i][j]=min(min(down,left),right);
//         }
//     }
//     int ans=INT_MAX;
//     for (int j = 0; j< n; j++)
//     {
//         ans=min(ans,dp[n-1][j]);
//     }
//     return ans;
// }
// int minFallingPathSum(vector<vector<int>>& matrix) {
//     int n=matrix.size();
//     vector<int>prev(n,0);
//     for (int i = 0; i <n; i++) prev[i]=matrix[0][i];

//     for (int i = 1; i <n; i++)
//     {
//         vector<int>temp(n,0);
//         for (int j = 0; j < n; j++)
//         {
//             int down=matrix[i][j]+prev[j];
//             int left=matrix[i][j];
//             if(j>=1)left+=prev[j-1];
//             else left+=1e9;
//             int right = matrix[i][j];
//             if(j<n-1)right+=prev[j+1];
//             else right+=1e9;

//             temp[j]=min(min(down,left),right);
//         }
//         prev=temp;
//     }
//     int ans=INT_MAX;
//     for (int j = 0; j< n; j++)
//     {
//         ans=min(ans,prev[j]);
//     }
//     return ans;
// }

// int f(int row,int col,int n,vector<vector<int>>& dp,vector<vector<int>>& matrix){
//     // basecase
//     if(row<0 || col<0 ||col>=n) return 1e9;
//     if(row==0 && col>=0 && col<n)  return matrix[row][col];
    
//     if(dp[row][col]!=-1)return dp[row][col];

//     int up=matrix[row][col]+f(row-1,col,n,dp,matrix);
//     int left=matrix[row][col]+f(row-1,col-1,n,dp,matrix);
//     int right=matrix[row][col]+f(row-1,col+1,n,dp,matrix);

//     return dp[row][col]=min(min(up,left),right);
// }
// int minFallingPathSum(vector<vector<int>>& matrix) {
//     int n=matrix.size();
//     vector<vector<int>>dp(n,vector<int>(n,-1));
//     int mx=INT_MAX;

//     for (int i = 0; i < n; i++)
//     {
//        mx=min(mx,f(n-1,i,n,dp,matrix));
//     }
//     return mx;
// }



// int minFallingPathSum(vector<vector<int>>& matrix) {
//     int n=matrix.size();
//     vector<vector<int>>dp(n,vector<int>(n,0));
//     for (int i = 0; i < n; i++)
//     dp[0][i]=matrix[0][i];

//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             int down=matrix[i][j]+dp[i-1][j];
//             int left=INT_MAX,right=INT_MAX;
//             if(j>0)left=matrix[i][j]+dp[i-1][j-1];
//             if(j<n-1)right=matrix[i][j]+dp[i-1][j+1];

//             dp[i][j]=min(min(down,right),left);
//         }   
//     }
//     int ans=INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         ans=min(ans,dp[n-1][i]);
//     }
//     return ans;
// }





int minFallingPathSum(vector<vector<int>>& matrix) {
    int n=matrix.size();
    vector<int>prev(n,0);
    for (int i = 0; i < n; i++)
    prev[i]=matrix[0][i];

    for (int i = 1; i < n; i++)
    {
        vector<int>temp(n,0);
        for (int j = 0; j < n; j++)
        {
            int down=matrix[i][j]+prev[j];
            int left=INT_MAX,right=INT_MAX;
            if(j>0)left=matrix[i][j]+prev[j-1];
            if(j<n-1)right=matrix[i][j]+prev[j+1];

            temp[j]=min(min(down,right),left);
        }  
        prev=temp; 
    }
    int ans=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans=min(ans,prev[i]);
    }
    return ans;
}
};