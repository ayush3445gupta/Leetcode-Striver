class Solution {
public:
//    vector<int>largestDivisibleSubset(vector<int> &nums) {
//        int n=nums.size();
//        sort(nums.begin(),nums.end());
//        int maxi=1;
//        int lastIndex=0;
//        vector<int>dp(n,1),hash(n,1);
//        for (int i =0; i<n; i++)
//        {
//         hash[i]=i;
//         for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            
//             if(nums[i]%nums[prev_index]==0 && 1 + dp[prev_index] > dp[i]){
//                 dp[i] = 1 + dp[prev_index];
//                 hash[i] = prev_index;
//             }
//         }
//         if(dp[i]>maxi){
//             maxi=dp[i];
//             lastIndex=i;
//         }
//        }
//        vector<int>ans;
//        ans.push_back(nums[lastIndex]);
//       while (hash[lastIndex]!=lastIndex)
//       {
//         lastIndex=hash[lastIndex];
//         ans.push_back(nums[lastIndex]);
//       }
//       reverse(ans.begin(),ans.end());
//       return ans;
//     }

int n;
int max_size=0;
vector<int>ans;
void solve(int prev,int curr_idx,vector<int>&nums,vector<int>&res){
    // basecase
    if(curr_idx>=n){
        if(res.size()>ans.size())ans=res;
        return;
    }


    solve(prev,curr_idx+1,nums,res);
    if(prev==-1 || nums[curr_idx]%nums[prev]==0){
        res.push_back(nums[curr_idx]);
        solve(curr_idx,curr_idx+1,nums,res);
        res.pop_back();
    }
    return;
}
vector<int>largestDivisibleSubset(vector<int> &nums) {
    n=nums.size();
    max_size=0,ans.clear();
    sort(begin(nums),end(nums));
    vector<int>res;
    solve(-1,0,nums,res);
    return ans;
}
};