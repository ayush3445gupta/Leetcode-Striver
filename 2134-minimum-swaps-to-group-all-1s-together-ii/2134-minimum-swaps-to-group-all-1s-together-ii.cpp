class Solution {
public:
int minSwaps(vector<int>& nums) {
      int n=nums.size();
      int ones=0;
      int ans=INT_MAX;
      for(int i:nums)if(i==1)ones++;
      vector<int>arr=nums;
      for(int i:nums)arr.push_back(i);
      int i=0,j=0;
      int cnt=0;
      while (j<2*n)
      {
        if(arr[j]==0)cnt++;
        if(j-i+1==ones){
            ans=min(ans,cnt);
            if(arr[i]==0)cnt--;
            i++;
        }
        j++;
      }
       return (ans==INT_MAX?0:ans);
    }
};