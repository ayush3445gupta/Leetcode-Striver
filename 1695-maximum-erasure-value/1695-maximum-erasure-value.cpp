class Solution {
public:
int maximumUniqueSubarray(vector<int>& nums) {
     unordered_map<int,int>mp;
     int sum=0;
     int ans=INT_MIN;
     int n=nums.size();
     
     int left=0,right=0;
     while (right<n)
     {

           
            while (mp.find(nums[right])!=mp.end())
            {
                sum-=nums[left];
                mp[nums[left]]--;
                if(mp[nums[left]]==0)mp.erase(nums[left]);
                left++;
            }  

            mp[nums[right]]++;
            sum+=nums[right];
            right++;
            ans=max(ans,sum);
    }
return ans;
}
};