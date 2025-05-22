class Solution {
public:
int longestOnes(vector<int>& nums, int k) {
    int n=nums.size();
    int left=0,right=0;
    vector<int>vec(2,0);
    int mx=INT_MIN;
    while (right<n)
    {
        vec[nums[right]]++;
        while (vec[0]>k)
        {
            vec[nums[left]]--;
            left++;
        }
        mx=max(mx,right-left+1);
        right++;
    }
      return mx;  
    }
};