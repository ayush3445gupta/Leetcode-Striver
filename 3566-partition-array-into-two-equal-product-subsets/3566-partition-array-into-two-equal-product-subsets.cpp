class Solution {
public:

typedef long long ll;
bool solve(int i,ll target,vector<int>&nums,vector<bool>&used,ll prod){
    if(prod==target){
        ll prod2=1;
        bool f=0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(!used[i]){
                f=1;
                prod2*=nums[i];
            }
        }
        return f && prod2==target;
    }

    if(i==nums.size() || prod>target)return false;

    // pick
    used[i]=true;
    if(solve(i+1,target,nums,used,prod*nums[i]))return true;
    used[i]=false;

    if(solve(i+1,target,nums,used,prod))return true;
    
    return false;
}
bool checkEqualPartitions(vector<int>& nums, long long target) {
    for(int i:nums){
        if(target%i)return false;
    }
    vector<bool>used(nums.size(),false);
    return solve(0,target,nums,used,1);
    }
};