class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
     int n=nums.size();
     /*
     steps = expand the window untill the freq doesnt exceed k
     when it exceeds ,stops and calculate the length and starts shrinking till the count decreases to k and then further expand
     */   
    unordered_map<int,int>mp;
    int mxlen=INT_MIN;
    int i=0,j=0;
    while (j<n)
    {
        mp[nums[j]]++;
        while (mp[nums[j]]>k)
        {
            mp[nums[i]]--;
            i++;
        }
        mxlen=max(mxlen,j-i+1);
        j++;
    }
    return mxlen;
    }
};