class Solution {
public:
int minSubArrayLen(int target, vector<int>& nums) {
      int n=nums.size();
      int left=0,right=0;
      int ans=INT_MAX;
      while (right<n)
      {
        target-=nums[right];
            while (target<0)
            {
                ans=min(ans,right-left+1);
                target+=nums[left];
                left++;
            }
       if(target==0){
        ans=min(ans,right-left+1);
       }
        right++;
      }
      if(ans==INT_MAX)return 0;
      return ans;  
    }
};