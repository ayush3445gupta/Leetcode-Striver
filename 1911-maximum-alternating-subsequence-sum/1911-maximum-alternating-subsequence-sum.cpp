class Solution {
public:
typedef long long ll;
ll f(int idx,int n,bool choice,vector<int>&nums,vector<vector<ll>>&dp){
    // basecase
    if(idx==n)return 0;

    if(dp[idx][choice]!=LLONG_MIN)return dp[idx][choice];

    ll pick=(choice==1?(ll)nums[idx]:-(ll)nums[idx])+f(idx+1,n,!choice,nums,dp);
    ll not_pick=f(idx+1,n,choice,nums,dp);

    return dp[idx][choice]=max(pick,not_pick);
}
ll maxAlternatingSum(vector<int>& nums) {
       int n=nums.size();
       vector<vector<ll>>dp(n+1,vector<ll>(2,LLONG_MIN));
       return f(0,n,1,nums,dp);
    }
};