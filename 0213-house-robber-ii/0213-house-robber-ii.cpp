class Solution {
public:
// int dp[101];
// int solve(vector<int>&nums,int idx,int n){
//     if(idx>=n)return 0;
//     if(dp[idx]!=-1)return dp[idx];

//     int take=nums[idx]+solve(nums,idx+2,n);
//     int skip=solve(nums,idx+1,n);

//     return dp[idx]=max(take,skip);
// }
// int rob(vector<int>& nums) {
     
//      int n=nums.size();
//      if(n==1)return nums[0];
//      if(n==2)return max(nums[0],nums[1]);
     
//      memset(dp,-1,sizeof(dp));
//     //  case 1 - Take first house 0th index
//     int take0 = solve(nums,0,n-1);
//     memset(dp,-1,sizeof(dp));
//     int take1=solve(nums,1,n);

//     return max(take0,take1);
//     }

int rob(vector<int>& nums) {
     
     int n=nums.size();
     if(n==1)return nums[0];
     if(n==2)return max(nums[0],nums[1]);
     
     vector<int>dp(n+1,0);
     int res1=0,res2=0;
    //  case 1 - Take first house 0th index
    dp[0]=0;
    dp[1]=nums[0];
    for (int i = 2; i <=n-1; i++)
    {
        dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);
    }
    res1=dp[n-1];

    // skip first house
    dp.clear();
    dp[0]=0;
    dp[1]=0;
    for (int i = 2; i <=n; i++)
    {
        dp[i]=max(dp[i-1],nums[i-1]+dp[i-2]);
    }
    res2=dp[n];
    return max(res1,res2);
    }
};