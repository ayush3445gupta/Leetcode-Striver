class Solution {
public:
typedef long long ll;
ll bs(vector<int>& nums,vector<ll>&ps,int target_idx, long long k){
    int n=nums.size();
    int l=0,r=target_idx;
    int best_idxl=target_idx;
    while (l<=r) // search on left
    {
        int mid=l+(r-l)/2;
        ll windowsum=(target_idx-mid+1)*nums[target_idx];
        ll currsum=ps[target_idx]-ps[mid]+nums[mid];

        if(windowsum-currsum>k){
            l=mid+1;
        }
        else{
            best_idxl=mid;
            r=mid-1;
        }
    }

    k=k-((target_idx-best_idxl+1)*nums[target_idx]-ps[target_idx]-ps[best_idxl]+nums[best_idxl]);
    
    int l2=target_idx,r2=n-1;
    int best_idxr=target_idx;
    while (l2<=r2)  // search on right
    {
        int mid=l2+(r2-l2)/2;
        ll ws=(mid-target_idx+1)*nums[target_idx];
        ll cs=ps[mid]-ps[target_idx]+nums[target_idx];

        if(cs-ws>k){
            r2=mid-1;
        }
        else{
            best_idxr=mid;
            l2=mid+1;
        }
    }
    return best_idxr-best_idxl+1;
}
int maxFrequencyScore(vector<int>& nums, long long k) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    ll ans=LLONG_MIN;
    vector<ll>ps(n,0);
    ps[0]=nums[0];
    for (int i = 1; i < n; i++)ps[i]=nums[i]+ps[i-1];
    
    for (int i = 0; i < n; i++)ans=max(ans,bs(nums,ps,i,k));
    return ans;    
    }  
};