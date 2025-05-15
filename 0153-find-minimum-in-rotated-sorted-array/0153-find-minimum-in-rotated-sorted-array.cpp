class Solution {
public:
int findMin(vector<int>& nums) {
     int n=nums.size();
     int ans=INT_MAX;
     int l=0,r=n-1;
     while (l<=r)
     {
        int m=l+(r-l)/2;

        // check for left half sorted
        if(nums[m]>=nums[l]){
            ans=min(ans,nums[l]);
            l=m+1;
        }
        else{
            ans=min(ans,nums[m]);
            r=m-1;
        }
     }
      return ans;  
    }
};