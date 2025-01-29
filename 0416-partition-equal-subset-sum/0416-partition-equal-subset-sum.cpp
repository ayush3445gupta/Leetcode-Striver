class Solution {
public:
//     bool f(int ind,int sum,vector<int>& nums,vector<vector<int>>&dp){
//     // basecase
//     if(sum==0)return true;
//     if(ind==0)return sum=nums[0];

//     if(dp[ind][sum]!=-1)return dp[ind][sum];
//     bool notTake=f(ind-1,sum,nums,dp);
//     bool Take=false;
//     if(nums[ind]<=sum)Take=f(ind-1,sum-nums[ind],nums,dp);

//     return dp[ind][sum]=notTake || Take;
// }
// bool canPartition(vector<int>& nums) {
//      int n=nums.size();
//      int sum=accumulate(nums.begin(),nums.end(),0);
//      if(!sum&1)return false;
//      vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
//      return f(n-1,sum/2,nums,dp);   
//     }
bool canPartition(vector<int>& nums) {
     int n=nums.size();
     int sum=accumulate(nums.begin(),nums.end(),0);
     if(sum&1)return false;
     int k=sum/2;
     vector<vector<bool>>dp(n,vector<bool>(k+1,false));
    //  basecase
      for (int i = 0; i <n; i++)dp[i][0]=true;
     if(nums[0]<=k) dp[0][nums[0]]=true;
      
      for (int ind = 1; ind <n; ind++)
      {
        for (int target = 1; target <=k; target++)
        {
            bool notTake=dp[ind-1][target];
            bool Take=false;
            if(nums[ind]<=target)Take=dp[ind-1][target-nums[ind]];

            dp[ind][target]=Take || notTake;
        }
        
      }
 return dp[n-1][k];     
    }
};