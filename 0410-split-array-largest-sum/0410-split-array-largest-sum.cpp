class Solution {
public:
typedef long long ll;
int check(ll mid,vector<int>&nums,int n,int k){
    int cnt=1;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        if(sum+nums[i]>mid){
            sum=nums[i];
            cnt++;
        }
        else sum+=nums[i];
    }
    return cnt;
}
int splitArray(vector<int>& nums, int k) {
    int n=nums.size();
    // sort(begin(nums),end(nums));
    ll left=*max_element(begin(nums),end(nums));
    ll right=accumulate(begin(nums),end(nums),0);
    
    while (left<=right)
    {
        ll mid=(left+right)/2;
        if(check(mid,nums,n,k)>k)left=mid+1;
        else right=mid-1;
    }
return left;
    }
};