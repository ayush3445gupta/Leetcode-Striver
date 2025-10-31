class Solution {
public:
// int solve(int ind,int prev_ind,vector<int>& nums,vector<vector<int>>&dp){
//     // basecase
//     if(ind==nums.size()) return 0;
//     if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
//     int len=0+solve(ind+1,prev_ind,nums,dp);
//     if(prev_ind==-1 || nums[ind]>nums[prev_ind])
//     len=max(1+solve(ind+1,ind,nums,dp),len);

//     return dp[ind][prev_ind+1]=len;
// }
// int lengthOfLIS(vector<int>& nums) {
//        int n=nums.size();
//        vector<vector<int>>dp(n,vector<int>(n,-1));
//       return  solve(0,-1,nums,dp); 
//     }

// int lengthOfLIS(vector<int>& nums) {
//     int n=nums.size();
//     vector<int>curr(n+1,0);
//     vector<int>next(n+1,0);
//     for (int ind =n-1; ind>=0; ind--)
//     {
//         for (int prev=ind-1;prev>=-1; prev--)
//         {
//             int len=0+next[prev+1];
//             if(prev==-1 || nums[ind]>nums[prev]){
//             len=max(len,1+next[ind+1]);
//             }
//             curr[prev+1]=len;
//         }    
//         next=curr;       
//         }
//     return curr[0];
// }

// int lengthOfLIS(vector<int>& nums) {
//     int n=nums.size();
//     vector<int>dp(n,1);
//     for (int ind = 1; ind <n; ind++)
//     {
//         for (int prev = 0; prev<ind; prev++)
//         {
//             if(nums[prev]<nums[ind]){
//                 dp[ind]=max(dp[ind],1+dp[prev]);
//             }
//         } 
//     }
//     return *max_element(dp.begin(),dp.end());
// }




// ###########################################################


int f(int idx,int n, int prev_id,vector<int>&nums,vector<vector<int>>&dp){
    // basecase
    if(idx==n)return 0;

    if(prev_id!=-1 &&  dp[idx][prev_id]!=-1)return dp[idx][prev_id];
    // skip it
    int skip=f(idx+1,n,prev_id,nums,dp);
    int take=0;
    if(prev_id==-1 ||  nums[idx]>nums[prev_id])take=1+f(idx+1,n,idx,nums,dp);
    if(prev_id!=-1) dp[idx][prev_id]=max(take,skip);
    return max(take,skip);
}
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    // i have 2 options either skip it or take it and while taking i also have a constraint of prev_id
    int prev_id_id=-1;
    int len=0;
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return f(0,n,prev_id_id,nums,dp);
}
};