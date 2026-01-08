class Solution {
public:
int n,m;
// int solve(int i,int j,bool taken,vector<int>& nums1, vector<int>& nums2,vector<vector<vector<int>>>&dp){
//     // basecase
//     if(i==n || j==m)
//         return (taken?0:INT_MIN);
    

//      if(dp[i][j][taken]!=INT_MIN)return dp[i][j][taken];

//     int take=nums1[i]*nums2[j]+solve(i+1,j+1,1,nums1,nums2,dp);
//     int a=solve(i+1,j,taken,nums1,nums2,dp);
//     int b=solve(i,j+1,taken,nums1,nums2,dp);

//     int skip=max(a,b);

//     return dp[i][j][taken]=max(skip,take);
// }
// int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
//     n=nums1.size(),m=nums2.size();
//     vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(2)));
//     for (int i = 0; i <=n; i++)
//         for (int j = 0; j <=m; j++)
//          for (int k = 0; k <=1; k++)dp[i][j][k]=INT_MIN;
         
//    return solve(0,0,0,nums1,nums2,dp);
//     }
int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    n=nums1.size(),m=nums2.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(2,INT_MIN)));
    
    for (int i = 0; i <=n; i++){
        for (int j = 0; j <=m; j++)
        {
            dp[i][j][1]=0;
            dp[i][j][0]=INT_MIN;
        }
    }

    for (int i =n-1; i>=0; i--)
    {
        for (int j = m-1; j>=0; j--)
        {
            for (int taken = 0; taken <=1; taken++)
            {
                int skip=max(dp[i+1][j][taken],dp[i][j+1][taken]);
                int take=INT_MIN;
                int next=dp[i+1][j+1][1];
                if(next!=INT_MIN)take=nums1[i]*nums2[j]+next;

                dp[i][j][taken]=max(skip,take);
            }
        }
    }
    return dp[0][0][0];
    }
};