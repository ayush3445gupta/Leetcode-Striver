class Solution {
public:
int n;
int minDifficulty(vector<int>& jobDifficulty, int D) {
    n=jobDifficulty.size();
    if(n<D)return -1;
    vector<vector<int>>dp(n,vector<int>(D+1,INT_MAX));

    for (int i = 0; i < n; i++)
    {
       dp[i][1]=*max_element(jobDifficulty.begin()+i,jobDifficulty.end());
    }

    for (int d = 2; d <=D; d++)
    {
        for (int i = 0; i <=n-d; i++)
        {
            int mx=0;
            dp[i][d]=INT_MAX;
            for (int j = i; j <=n-d; j++)
            {
                mx=max(mx,jobDifficulty[j]);
                dp[i][d]=min(dp[i][d],mx+dp[j+1][d-1]);
            }
        }
    }
    return dp[0][D];
    }
};