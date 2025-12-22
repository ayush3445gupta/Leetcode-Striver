class Solution {
public:
int n,k;
int dp[101][101];
int solve(int prev,int idx,vector<string>& strs){
    // basecase
    if(idx>=k)return 0;

    if(prev!=-1 && dp[prev][idx]!=-1)return dp[prev][idx];

    int skip=solve(prev,idx+1,strs);
    int take=0;
    if(prev==-1)take=1+solve(idx,idx+1,strs);
    else{
        bool f=0;
        for (int i = 0; i < n; i++)
            {
                if(strs[i][prev]>strs[i][idx]){
                f=1;
                break;}
            }
        if(f==0)take=1+solve(idx,idx+1,strs);
        }
    if(prev!=-1)return dp[prev][idx]=max(skip,take);
    return  max(skip,take);
}
int minDeletionSize(vector<string>& strs) {
    n=strs.size();  
    k=strs[0].length();
    memset(dp,-1,sizeof(dp));
    return k-solve(-1,0,strs);
    }
};