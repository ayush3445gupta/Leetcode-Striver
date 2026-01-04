class Solution {
public:
int n;
int factorize(int k){
    int sum=0,cnt=0;
    for (int i = 1; i*i<=k; i++)
    {
        if(k%i==0){
            sum+=(i);
            cnt++;
            if(k==(i*i))continue;
            sum+=(k/i);
            cnt++;   
        }
    }
    return (cnt==4?sum:0);
}
int sumFourDivisors(vector<int>& nums) {
     n=nums.size();
     int ans=0;
     for (int i = 0; i < n; i++)
     {
        ans+=(factorize(nums[i]));
     }
     return ans;
    }
};