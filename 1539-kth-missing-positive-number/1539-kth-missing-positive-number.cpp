class Solution {
public:
typedef long long ll;
int findKthPositive(vector<int>& arr, int k) {
    int n=arr.size();
    int cnt=0;
    int l=0,r=n-1;
    while (l<=r && l<n)
    {
        int mid=l+(r-l)/2;
        if(arr[mid]-(mid+1)<=k)l=mid+1;
        else r=mid-1;
    }
    if(l>=n)return arr[n-1]+k;
    int needed=arr[r]-(r+1);
    return arr[r]+k-needed;  
    }
};