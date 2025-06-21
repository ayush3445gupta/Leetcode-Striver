class Solution {
public:
typedef long long ll;
long long maximumProduct(vector<int>& nums, int m) {
     if (m==1){
        int mx = *max_element(begin(nums),end(nums));
        int mn = *min_element(begin(nums),end(nums));

        ll a1 = 1LL*mx*mx;
        ll a2 = 1LL*mn*mn;
        ll ans = max(a1,a2);
        return ans;
     }   

     int n = nums.size();
    ll ans = LLONG_MIN;

    // for (int i = 0; i < n; i++)
    // {
    //   int j = i + m-1;
    //   while (j<n)
    //   {
    //     ll temp = nums[i]*nums[j];
    //     ans = max(ans,temp);
    //     j++;
    //   }
    // }

    int mx = nums[0],mn=nums[0];

    int left=0,right=m-1;

    while (right<n)
    {
      mx = max(mx,nums[left]);
      mn = min(mn,nums[left]);
      
      ll a1 = 1LL*nums[right]*mx,a2 = 1LL*nums[right]*mn;
      ans=max(ans,max(a1,a2));
      right++;
      left++;
    }
    return ans;
    }
};