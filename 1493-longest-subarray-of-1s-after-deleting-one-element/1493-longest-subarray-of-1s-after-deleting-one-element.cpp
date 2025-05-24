class Solution {
public:
int longestSubarray(vector<int>& nums) {
    int n=nums.size();
    int i=0,j=0;
    int cnt=0;
    int ans=INT_MIN;
    while (j<n)
    {
        if(nums[j]==0)cnt++;
            while (cnt>1)
            {
                ans=max(ans,j-i+1-cnt);
                if(nums[i]==0)cnt--;
                i++;
            }
        j++;
    }
     if(cnt!=0)ans=max(ans,j-i-cnt);
      return (ans==INT_MIN?n-1:ans);
    }
};