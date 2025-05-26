class Solution {
public:
    typedef long long ll;
int bin_Search(vector<int>nums,vector<int>ps,int k,int idx){
    int left=0,right=idx;
    int best_idx=idx;
    while (left<=right)
    {
        int mid=left+(right-left)/2;
        ll windowSum=(idx-mid+1)*nums[idx];
        ll currSum=ps[idx]-ps[mid]+nums[mid];

        int ops=windowSum-currSum;
        if(k>=ops){
            best_idx=mid;
            right=mid-1;
        }
        else left=mid+1;
    }
    return idx-best_idx+1;
}
int maxFrequency(vector<int>& nums, int k) {
     int n=nums.size();
     sort(nums.begin(),nums.end());
     vector<int>prefixSum(n,0);
     prefixSum[0]=nums[0];
     for (int i = 1; i < n; i++) prefixSum[i]=nums[i]+prefixSum[i-1];
     
     int ans=INT_MIN;
     for (int i = 1; i < n; i++)
     {
        ans=max(ans,bin_Search(nums,prefixSum,k,i));
     }
     
     return ans;
    }
};