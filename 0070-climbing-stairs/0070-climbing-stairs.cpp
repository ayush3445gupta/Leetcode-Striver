class Solution {
public:
// int find(int n,vector<int>&dp){
//     if(n==0)return 1;
//     if(n<0)return 0;
    
//     if(dp[n]!=-1)return dp[n];

//     int step1=find(n-1,dp);
//     int step2=find(n-2,dp);

//     return dp[n]=step1+step2;
// }
// int climbStairs(int n) {
//       vector<int>dp(n+1,-1);
//       return find(n,dp);  
//     }
int climbStairs(int n) {
    vector<int>dp(n+1,-1);
    dp[0]=1,dp[1]=1;
    for (int i = 2; i <=n; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
    }
};