class Solution {
public:
typedef long long ll;
ll countSubarrays(vector<int>& nums, int k) {
     ll ans=0;
     int n=nums.size();
     ll cnt_mx=0;
     ll mx=*max_element(begin(nums),end(nums));
     int i=0,j=0;
     while (j<n)
     {
        if(nums[j]==mx)cnt_mx++;
        while (cnt_mx>=k && i<j)
        {
            ans+=(n-j);
            if(nums[i]==mx)cnt_mx--;
            i++;
        }
        j++;
     }
     return ans;
    }
};