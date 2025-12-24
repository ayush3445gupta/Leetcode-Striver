class Solution {
public:
typedef long long ll;
const int MOD=1e9+7;
int m,n;
vector<vector<pair<ll,ll>>>dp;

int maxProductPath(vector<vector<int>>& grid) {
    m=grid.size(),n=grid[0].size();

    dp = vector<vector<pair<ll,ll>>>(m,vector<pair<ll,ll>>(n));

    dp[0][0]={grid[0][0],grid[0][0]};

    // first row
    for (int i = 1; i < n; i++)
    {
        dp[0][i].first = dp[0][i-1].first * grid[0][i]; // maxval
        dp[0][i].second = dp[0][i-1].second*grid[0][i];
        // ṃinval
    }

    // first col
    for (int i = 1; i < m; i++)
    {
        dp[i][0].first = dp[i-1][0].first * grid[i][0]; // maxval
        dp[i][0].second = dp[i-1][0].second*grid[i][0];
        // ṃinval
    }
    
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            // up 
            ll upmax=dp[i-1][j].first;
            ll upmin=dp[i-1][j].second;
            // left
            ll leftmax=dp[i][j-1].first;
            ll leftmin=dp[i][j-1].second;

            dp[i][j].first=max({upmax*grid[i][j],
            upmin*grid[i][j],leftmax*grid[i][j],leftmax*grid[i][j]});

            dp[i][j].second=min({upmax*grid[i][j],
            upmin*grid[i][j],leftmax*grid[i][j],leftmax*grid[i][j]});
        }
        
    }
    return (dp[m-1][n-1].first<0?-1:dp[m-1][n-1].first%MOD);
}
};