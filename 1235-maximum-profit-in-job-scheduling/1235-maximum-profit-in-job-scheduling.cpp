class Solution {
public:
int n;
int find(int start,int idx,vector<int>&a){
    int left=start,right=n-1,ans=n;
    while (left<=right)
    {
        int mid=left+(right-left)/2;

        if(a[mid]<idx)left=mid+1;
        else{
            ans=mid;
            right=mid-1;
        }
    }
    return ans;
}
int solve(int i,vector<int>& startTime, vector<int>& endTime, vector<int>& profit,vector<int>&dp){
    // basecase
    if(i==n)return 0;

     if( dp[i]!=-1)return dp[i];

    int skip=solve(i+1,startTime,endTime,profit,dp);
    int next_id = find(startTime[i],endTime[i],startTime);
    int take=profit[i] + solve(next_id,startTime,endTime,profit,dp);
    return dp[i]=max(take,skip);
}
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
    vector<int>dp(n,-1);
   return solve(0,st,et,pf,dp);  
    }
};