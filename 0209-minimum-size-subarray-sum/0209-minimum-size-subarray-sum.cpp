class Solution {
public:
// int minSubArrayLen(int target, vector<int>& nums) {
//       int n=nums.size();
//       int left=0,right=0;
//       int ans=INT_MAX;
//       while (right<n)
//       {
//         target-=nums[right];
//             while (target<0)
//             {
//                 ans=min(ans,right-left+1);
//                 target+=nums[left];
//                 left++;
//             }
//        if(target==0){
//         ans=min(ans,right-left+1);
//        }
//         right++;
//       }
//       if(ans==INT_MAX)return 0;
//       return ans;  
//     }

// 15-07-25
int minSubArrayLen(int target, vector<int>& nums){
    // if sum less than target expand to right ,else shrink from
    // left

    int n=nums.size();
    int left=0,right=0;
    int minWindow=INT_MAX;
    int sum=0;
    while (right<n)
    {
        sum+=nums[right];
            while (sum>target)
            {
                minWindow=min(right-left+1,minWindow);
                sum-=nums[left];
                left++;
            }
            if(sum==target)minWindow=min(right-left+1,minWindow);
        right++;
    }
    
    return (minWindow==INT_MAX?0:minWindow);
}
};