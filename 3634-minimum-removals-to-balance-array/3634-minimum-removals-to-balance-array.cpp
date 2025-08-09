class Solution {
public:
typedef long long ll;
int minRemoval(vector<int>& nums, int k) {
    sort(begin(nums),end(nums));
    int n=nums.size();
    int left=0,right=1;
    int mx_len=1;
    while (right<n)
    {
        while ((ll)nums[right]>(ll)nums[left]*(ll)k)
        {
            left++;
        }
        mx_len=max(mx_len,right-left+1);
        right++;
    }
    return n-mx_len;
    }
};