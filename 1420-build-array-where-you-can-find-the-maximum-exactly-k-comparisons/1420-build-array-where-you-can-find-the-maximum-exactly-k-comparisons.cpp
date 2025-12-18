class Solution {
public:
int MOD = 1e9+7;
int M,N,K;
int dp[51][51][101];
int solve(int idx,int len,int curr_max){

    if (idx == N)
    return (len == K);

    if(dp[idx][len][curr_max]!=-1)return dp[idx][len][curr_max];

    int ans=0;
    for (int i = 1; i <=M; i++)
    {
        if(i>curr_max)ans=(ans+solve(idx+1,len+1,i))%MOD;
        else ans=(ans+solve(idx+1,len,curr_max))%MOD;
    }
    return dp[idx][len][curr_max]=ans%MOD;
}
int numOfArrays(int n, int m, int k) {
    M=m,N=n,K=k;
    memset(dp,-1,sizeof(dp));
   return solve(0,0,0);
}
};