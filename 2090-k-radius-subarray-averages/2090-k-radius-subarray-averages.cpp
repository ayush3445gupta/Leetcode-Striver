class Solution {
public:
    typedef long long ll;
vector<int> getAverages(vector<int>& nums, int k) {
     int n=nums.size(); 
    vector<int>ans(n,-1);
    int left=0,right=0;
    ll sum=0;
    while (right<n)
    {
        sum+=nums[right];
        if(right-left==(2*k)){
            ans[left+k]=sum/(2*k+1);
            sum-=nums[left];
            left++;
        }
        right++;
    }
      return ans;
    }
};