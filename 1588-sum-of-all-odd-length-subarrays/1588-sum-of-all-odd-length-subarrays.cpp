class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
     int n=arr.size();
     int ans=accumulate(arr.begin(),arr.end(),0);
     if(n<3)return ans;
     vector<int>store;
     for (int i = 0; i < n; i++)
     {
        int sum=arr[i];
        int cnt=1;
        store.push_back(sum);
        for (int j = i+1; j<n; j++)
        {
            sum+=arr[j];
            cnt++;
            if(cnt%2!=0)store.push_back(sum);
        }
     }
     int res=accumulate(store.begin(),store.end(),0);
     return res;   
    }
};