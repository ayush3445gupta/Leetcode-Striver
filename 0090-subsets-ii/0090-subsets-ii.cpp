class Solution {
public:
void solve(int i,vector<int>& nums,vector<int>& res,vector<vector<int>>&ans,int n){
    if(i>=n){
        ans.push_back(res);
        return;
    }
    res.push_back(nums[i]);
    solve(i+1,nums,res,ans,n);
    res.pop_back();

    while (i+1<n && nums[i]==nums[i+1])
    {
        i++;
    }
    solve(i+1,nums,res,ans,n);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    sort(begin(nums),end(nums));
    vector<vector<int>>ans;
    vector<int>res={};
    solve(0,nums,res,ans,n);
    return ans;
}
};