class Solution {
public:
// int coinChange(vector<int>& coins, int amount) {
    //    int n=coins.size();
    //    vector<int>prev(amount+1,0),curr(amount+1,0);
    //    for (int i = 0; i<=amount; i++)
    //    {
    //     if(i%coins[0]==0) prev[i]=i/coins[0];
    //     else prev[i]=1e9;
    //    }
       
    //    for (int i = 1; i <n; i++)
    //    {
    //     for (int t = 0; t <=amount; t++)
    //     {
    //         int npick=prev[t];
    //         int pick=1e9;
    //         if(coins[i]<=amount) pick=1+curr[t-coins[i]];

    //        curr[amount]=min(pick,npick);
    //     }
    //    prev=curr; 
    //    }
    //    int ans=prev[amount];
    //    if(ans>=1e9) return -1;
    //    return ans; 
    // }

// int solve(int ind,vector<int>& coins, int amount,vector<vector<int>>&dp){
//     // basecase
//     if(ind==0){
//         if(amount%coins[0]==0) return amount/coins[0];
//         else return 1e9;
//     }
//     if(dp[ind][amount]!=-1) return dp[ind][amount];
//     int npick=solve(ind-1,coins,amount,dp);
//     int pick=1e9;
//     if(amount>=coins[ind]) pick=1+solve(ind,coins,amount-coins[ind],dp);

//     return dp[ind][amount]=min(pick,npick);
// }
// int coinChange(vector<int>& coins, int amount) {
//     int n=coins.size();
//     vector<vector<int>>dp(n,vector<int>(amount+1,-1));
//    int ans=solve(n-1,coins,amount,dp);
//    if(ans>=1e9) return -1;
//    return ans;
// }

// int f(int idx,int amount,int cnt,vector<vector<int>>&dp,vector<int>&coins){
//     // basecase
//     if(idx==0){
//         if(amount%coins[0]!=0)return INT_MAX;
//         return cnt+amount/coins[0];
//     }
//     if(amount==0)return cnt;

//     if(dp[idx][amount]!=-1)return dp[idx][amount];
//     int npick=f(idx-1,amount,cnt,dp,coins);
//     int pick=INT_MAX;
//     if(amount>=coins[idx])
//     {
//         int k=amount/coins[idx];
//         pick = f(idx-1,amount-(k*coins[idx]),cnt+k,dp,coins);
//     }

//     return dp[idx][amount]=min(pick,npick);
// }
// int coinChange(vector<int>& coins, int amount) {
//     int n=coins.size();
//     sort(begin(coins),end(coins));
//     vector<vector<int>>dp(n,vector<int>(amount+1,-1));
//     int ans=f(n-1,amount,0,dp,coins);
//     if(ans==INT_MAX)return -1;
//     return ans;
// }

int coinChange(vector<int>&coins,int amount){
    int n=coins.size();
    vector<vector<int>>dp(n,vector<int>(amount+1,0));

    for (int i = 0; i <=amount; i++)
    {
       if(i%coins[0]==0)dp[0][i]=i/coins[0];
       else dp[0][i]=1e9;
    }
    
     for (int i = 1; i < n; i++)
     {
       for (int j=0; j<=amount; j++)
       {
         int npick=dp[i-1][j];
         int pick=1e9;
         if(j>=coins[i])pick=1+dp[i][j-coins[i]];
         dp[i][j]=min(pick,npick);
       }
     }
     int ans= dp[n-1][amount];
     return ans==1e9?-1:ans;
}
};