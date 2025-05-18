class Solution {
public:
typedef long long ll;
bool div(ll mid,vector<int>&nums,int t){
    ll sum=0;
    for (ll i = 0; i < nums.size(); i++)
    {
        sum+=(nums[i]/mid);
        if(nums[i]%mid)sum+=1;
    }
    if(sum<=t)return 1;
    return 0;
}
int smallestDivisor(vector<int>& nums, int threshold) {
    ll n=nums.size();
    ll left=1;
    ll right=*max_element(begin(nums),end(nums));

    while (left<=right)
    {
        ll mid=(left+right)/2;
        if(div(mid,nums,threshold)==1)right=mid-1;
        else if (div(mid,nums,threshold)==0)left=mid+1;
    }
    return left;
    }
};