class Solution {
public:
int repeatedNTimes(vector<int>& nums) {
    sort(begin(nums),end(nums));
    int n=nums.size()/2;
    int ans=-1;
    for (int i = 0; i <=n; i++)
    {
        if(nums[i]==nums[i+n-1]){
            ans=nums[i];
            break;
        }
    }
    return ans;
    }
};