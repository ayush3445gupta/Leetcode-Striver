class Solution {
public:
    // vector<vector<int>> subsets(vector<int>& nums) {
    // int n=nums.size();
    //   vector<vector<int>>ans;
    //   int subsets=(1<<n);
    //   for (int i = 0; i <subsets; i++)
    //   {
    //     vector<int>list;
    //     for (int j = 0; j < n; j++)
    //     {
    //         if(i&(1<<j)) list.push_back(nums[j]);
    //     }
    //     ans.push_back(list);
    //   }
    //   return ans;  
    // }
    void solve(int i,vector<int>& nums,vector<int>& res,vector<vector<int>>&ans,int n){
    if(i>=n){
        ans.push_back(res);
        return;
    }
    solve(i+1,nums,res,ans,n);
    res.push_back(nums[i]);
    solve(i+1,nums,res,ans,n);
    res.pop_back();
}
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>>ans;
    vector<int>res={};
    solve(0,nums,res,ans,n);
    return ans;
}
};