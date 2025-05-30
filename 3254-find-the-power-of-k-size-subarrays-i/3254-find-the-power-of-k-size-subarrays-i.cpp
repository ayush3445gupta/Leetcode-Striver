class Solution {
public:
vector<int> resultsArray(vector<int>& nums, int k) {
    if(k==1)return nums;
     int n=nums.size();
     vector<int>arr(n-k+1,-1);
     int count=1;
     for (int i = 1; i < k; i++)
     {
       if(nums[i]==nums[i-1]+1)count++;
       else count=1;
     }
     if(count==k)arr[0]=nums[k-1];
     int i=1,j=k;
     while (j<n)
     {
        if(nums[j]==nums[j-1]+1)count++;
        else count=1;
        if(count>=k)arr[i]=(nums[j]);
        i++;
        j++;
     }
        return arr;
    }
};