class Solution {
public:
// int minDistance(string &word1, string &word2) {
//       int n=word1.length();
//       int m=word2.length();
//       vector<vector<int>>dp(n+1,vector<int>(m+1,0));
//       for (int i = 0; i <=m; i++)dp[0][i]=i;
//       for (int i = 0; i <=n; i++)dp[i][0]=i;

//       for (int ind1 = 1; ind1 <=n; ind1++)
//       {
//         for (int ind2 = 1; ind2<=m; ind2++)
//         {
//            if(word1[ind1-1]==word2[ind2-1])
//              dp[ind1][ind2]=dp[ind1-1][ind2-1];
//             else{
//                 dp[ind1][ind2]=1+min(dp[ind1][ind2-1],min(
//                     dp[ind1-1][ind2-1],
//                     dp[ind1-1][ind2]
//                 )); 
//         }
//       }
//       }
// return dp[n][m];  
//    }

// 20-12-25

int  n,m;
// int solve(int i,int j,string& s,string& t,vector<vector<int>>&dp){
//     // basecase
//     if(i==n && j==m)return 0;
//     if(i==n || j==m)  return n+m-i-j;
    
//     if(dp[i][j]!=-1)return dp[i][j];
//     int op1=0;
//     if(s[i]==t[j]) return dp[i][j]=solve(i+1,j+1,s,t,dp);
//     else{
//         return dp[i][j]=1+min(
//             {solve(i+1,j,s,t,dp), // delete
//             solve(i+1,j+1,s,t,dp), // replace
//             solve(i,j+1,s,t,dp)}   // insert
//         );
//     }
// }
// // memoization code

// int minDistance(string &word1, string &word2) {
//     n=word1.length(),m=word2.length();
//     // we have 3 options insert, delete or replace at each index
//     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//     return solve(0,0,word1,word2,dp);
// }

int solve(int i,int j,string& s,string& t,vector<vector<int>>&dp){
    // basecase
    if(i==0 || j==0)  return i+j;
    
    if(dp[i][j]!=-1)return dp[i][j];
    int op1=0;
    if(s[i-1]==t[j-1]) return dp[i][j]=solve(i-1,j-1,s,t,dp);
    else{
        return dp[i][j]=1+min(
            {solve(i-1,j,s,t,dp), // delete
            solve(i-1,j-1,s,t,dp), // replace
            solve(i,j-1,s,t,dp)}   // insert
        );
    }
}
// bottom up memoization
int minDistance(string &word1, string &word2) {
    n=word1.length(),m=word2.length();
    // we have 3 options insert, delete or replace at each index
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return solve(n,m,word1,word2,dp);
}
};
