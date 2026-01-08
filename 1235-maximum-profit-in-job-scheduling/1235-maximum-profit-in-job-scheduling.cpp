class Solution {
public:
// int n;
// int find(int start,int idx,vector<int>&a){
//     int left=start,right=n-1,ans=n;
//     while (left<=right)
//     {
//         int mid=left+(right-left)/2;

//         if(a[mid]<idx)left=mid+1;
//         else{
//             ans=mid;
//             right=mid-1;
//         }
//     }
//     return ans;
// }
// int solve(int i,vector<int>& startTime, vector<int>& endTime, vector<int>& profit,vector<int>&dp){
//     // basecase
//     if(i==n)return 0;

//      if( dp[i]!=-1)return dp[i];

//     int skip=solve(i+1,startTime,endTime,profit,dp);
//     int next_id = find(i,endTime[i],startTime);
//     int take=profit[i] + solve(next_id,startTime,endTime,profit,dp);
//     return dp[i]=max(take,skip);
// }
// int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//     n=startTime.size();
//     vector<int>idx(n);
//     iota(idx.begin(),idx.end(),0);
//     sort(idx.begin(),idx.end(),[&](int a,int b){
//         return startTime[a]<startTime[b];
//     });
//     vector<int>st(n),et(n),pf(n);
//     for (int i = 0; i < n; i++)
//     {
//         st[i]=startTime[idx[i]];
//         et[i]=endTime[idx[i]];
//         pf[i]=profit[idx[i]];
//     }
//     vector<int>dp(n,-1);
//    return solve(0,st,et,pf,dp);  
//     }
int find(int start, int endTime, vector<int>& st) {
    int l = start, r = st.size() - 1, ans = st.size();
    while (l <= r) {
        int mid = (l + r) / 2;
        if (st[mid] < endTime) l = mid + 1;
        else {
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}
int n;
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    n=startTime.size();
    vector<int>idx(n);
    iota(idx.begin(),idx.end(),0);
    sort(idx.begin(),idx.end(),[&](int a,int b){
        return startTime[a]<startTime[b];
    });
    vector<int>st(n),et(n),pf(n);
    for (int i = 0; i < n; i++)
    {
        st[i]=startTime[idx[i]];
        et[i]=endTime[idx[i]];
        pf[i]=profit[idx[i]];
    }
    vector<int>dp(n+1,0);

    for (int i = n-1; i>=0; i--)
    {
        int skip=dp[i+1];
        int next_id=find(i+1,et[i],st);
        int take=take=profit[i]+dp[next_id];

        dp[i]=max(take,skip);
    }
    return dp[0];
    }
};