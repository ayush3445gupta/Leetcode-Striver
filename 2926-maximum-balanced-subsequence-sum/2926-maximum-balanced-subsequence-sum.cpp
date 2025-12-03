class Solution {
public:
typedef long long ll;
ll n;
// ll max_sum=LLONG_MIN;
// unordered_map<string,ll>mp;
// int solve(int prev_idx,int curr_idx,vector<int>&nums){
//     // basecase
//     if(curr_idx>=n)return 0;

//     string key=to_string(curr_idx)+"_"+to_string(prev_idx);

//     if(mp.find(key)!=mp.end())return mp[key];

//     ll skip=solve(prev_idx,curr_idx+1,nums);

//     ll take=LLONG_MIN;

//     if(prev_idx==-1 || nums[curr_idx]-nums[prev_idx]>=curr_idx-prev_idx)take=nums[curr_idx]+solve(curr_idx,curr_idx+1,nums);
    
//     return mp[key]=max(take,skip);
// }
// long long maxBalancedSubsequenceSum(vector<int>& nums) {
//     n=nums.size();
//     int maxi=*max_element(begin(nums),end(nums));
//     if(maxi<0)return maxi;
//     int prev_val=INT_MIN;
//     return solve(-1,0,nums);  
//     }
long long maxBalancedSubsequenceSum(vector<int>& nums) {
    n=nums.size();
    ll maxi=*max_element(begin(nums),end(nums));
    if(maxi<0)return maxi;
    vector<ll>dp(n);
    for (int i = 0; i < n; i++)dp[i]=nums[i];

    ll mx_sum=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(nums[i]-nums[j]>=i-j){
                dp[i]=max(dp[j]+nums[i],dp[i]);
                mx_sum=max(mx_sum,dp[i]);
            }
        }
    }
    return max(mx_sum,maxi);
    }
};