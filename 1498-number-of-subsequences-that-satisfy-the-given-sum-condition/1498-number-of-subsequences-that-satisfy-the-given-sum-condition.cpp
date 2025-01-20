class Solution {
public:
const int mod = 1e9+7;
int numSubseq(vector<int>& nums, int target) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int cnt=0;
    vector<int>pow2(n);
    pow2[0]=1;
    for (int i = 1; i <n; i++)
    {
        pow2[i]=2*pow2[i-1];
    }

    int i=0,j=n-1;
    while (i<=j)
    {
        if(nums[i]+nums[j]<=target){
            cnt=(int(cnt)%mod + int(pow(2,j-i))%mod)%mod;
            i++;
        }
        else j--;
    }
    return cnt;
    }
};