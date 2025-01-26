class Solution {
public:
// int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp){
//     // basecase
//     if(i==triangle.size()-1)return triangle[i][j];
//     if(dp[i][j]!=-1) return dp[i][j];
//     int next1=triangle[i][j]+solve(i+1,j,triangle,dp);
//     int next2=triangle[i][j]+solve(i+1,j+1,triangle,dp);
//     return dp[i][j]=min(next1,next2);
// }
// int minimumTotal(vector<vector<int>>& triangle) {
//      int n=triangle.size();
//      vector<vector<int>>dp(n,vector<int>(n,-1));
//      return solve(0,0,triangle,dp);  
//     }

// int minimumTotal(vector<vector<int>>& triangle) {
//      int n=triangle.size();
//      vector<vector<int>>dp(n,vector<int>(n,0));
//     for (int j = 0; j < n; j++) {
//         dp[n - 1][j] = triangle[n - 1][j];
//     }
//     for (int i =n-2; i >=0; i--)
//     {
//         for (int j =i; j>=0; j--)
//         {
//                 int next1=triangle[i][j]+dp[i+1][j];
//                 int next2=triangle[i][j]+dp[i+1][j+1];
//             dp[i][j]=min(next1,next2);
// // }
//         }
        
//     }
//     return dp[0][0];
//     }

int minimumTotal(vector<vector<int>>& triangle) {
    int n=triangle.size();
   vector<int>front(n,0);
    // basecase
    for (int j = 0; j <n; j++)
    {
        front[j]=triangle[n-1][j];
    }
    for (int i = n-2; i>=0; i--)
    {
        vector<int>curr(n,0);
       for (int j = i; j>=0; j--)
       {
        int up=triangle[i][j]+front[j];
        int left=triangle[i][j]+front[j+1];

        curr[j]=min(up,left);
       } 
       front=curr;
    }
    return front[0];
}
};
