class Solution {
public:
int n;
string longestPalindrome(string s) {
    n=s.length();
    int max_id=0;
    int max_len=1;
    vector<vector<bool>>dp(n,vector<bool>(n,0));
    for (int L = 1; L <=n; L++)
    {
        for (int i = 0; i+L<=n; i++)
        {
            int j=i+L-1;
            if(i==j)  dp[i][i]=1;
            else if (i+1==j && s[i]==s[j])dp[i][j]=1;
            else if (s[i]==s[j] && dp[i+1][j-1])
             dp[i][j]=1;
            
            if(dp[i][j] && L>max_len) {
                max_len = L;
                max_id = i;
            }
        }
    }
    return s.substr(max_id,max_len);
   }
};