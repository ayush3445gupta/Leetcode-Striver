class Solution {
public:
int m,n;
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    m=dungeon.size(),n=dungeon[0].size();
    vector<vector<int>>dp(m,vector<int>(n,0));

    for (int i = m-1; i>=0; i--)
    {
        for (int j =n-1; j>=0;j--)
        {
            if(i==m-1 && j==n-1){
                dp[i][j]=(dungeon[i][j]<0?1+abs(dungeon[i][j]):1);
            }
            else{
                int down=(i+1>=m)?INT_MAX:dp[i+1][j];
                int right=(j+1>=n)?INT_MAX:dp[i][j+1];

                int res=min(down,right)-dungeon[i][j];

                dp[i][j]=(res>0?res:1);
            }
        } 
    }
    return dp[0][0];
}
};