class Solution {
public:
// int solve(int ind,vector<int>&range,int n,vector<vector<int>>&dp){
//     // basecase
//     if(n==0) return 0;
//     if(ind>=range.size()) return 1e9;

//     if(dp[n][ind]!=-1) return dp[n][ind];
//     int npick=0+solve(ind+1,range,n,dp);
//     int pick=INT_MAX;
//     if(n>=range[ind])pick=1+solve(ind,range,n-range[ind],dp);
//     return dp[n][ind]= min(pick,npick);
// }
// int numSquares(int n) {
//     int k=ceil(sqrt(n));
//     vector<int>range;
//     vector<vector<int>>dp(n+1,vector<int>(k,-1));
//     for (int i = 1; i <=k; i++) range.push_back(i*i);
//     return solve(0,range,n,dp);
//     }
// int numSquares(int n) {
//     int k=ceil(sqrt(n));
//     vector<int>range;
//     vector<int>dp(n+1,INT_MAX);
//     for (int i = 1; i <=k; i++) range.push_back(i*i);
//     // tabulation
//     // basecase
//         dp[0]=0;
    
//     for (int i = 1; i <=n; i++)
//     {
//         for(int j:range){
//             if(i>=j)
//             dp[i]=min(dp[i],dp[i-j]+1);
//         } 
//     }
//     return dp[n]; 
//     }

int m;
// unordered_map<string,int>dp;
// int solve(int i,int n,vector<int>&res){
//     // basecase
//     if(n==0)return 0;
//     if(i==m || n<0)return INT_MAX;

//     string key = to_string(i)+"-"+to_string(n);

//     if(dp.count(key))return dp[key];

//     int skip=solve(i+1,n,res);
//     int take=INT_MAX;
//     if(n>=res[i]){
//         int temp=solve(i,n-res[i],res);
//         if(temp!=INT_MAX)take=1+temp;
//     }

//     return dp[key]=min(take,skip);
// }
// int numSquares(int n) {
//    vector<int>res;
//    for (int i = 1; i*i<=n; i++)res.push_back(i*i);
//    m=res.size();
//    return solve(0,n,res);
// }
int numSquares(int n) {
   vector<int>res;
   for (int i = 1; i*i<=n; i++)res.push_back(i*i);
   m=res.size();

   vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
   for (int i = 0; i <=m; i++)dp[i][0]=0;
   for (int i = 1; i <=n; i++)dp[m][i]=INT_MAX;
   
   for (int i = m-1; i>=0; i--)
   {
    for (int j = 1; j<=n; j++)
    {
       int skip=dp[i+1][j];
       int take=INT_MAX;
       if(j>=res[i]){
        int next=dp[i][j-res[i]];
        if(next!=INT_MAX)take=1+next;
       }
       dp[i][j]=min(take,skip);
    }
   }
   return dp[0][n];
}
};