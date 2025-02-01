class Solution {
public:
    int countPartitions(vector<int>& nums) {
    int cnt=0;
    int sum=accumulate(nums.begin(),nums.end(),0);
    int s1=0;
    for (int i = 0; i <nums.size()-1; i++)
    {
        s1+=nums[i];
        if(abs(s1-(sum-s1))%2==0)cnt++;
    }
       return cnt;
    }
};