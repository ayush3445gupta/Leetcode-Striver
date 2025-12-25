class Solution {
public:
int n;
int dp[1001][1001];
int solve2(int row,int col,int moves,vector<vector<int>>& fruits){
    if(moves==n-1){
        if(row==n-1 && col==n-1)return 0;
        return INT_MIN;
    }
    if(row>=col)return INT_MIN;
    if(dp[row][col]!=-1) return dp[row][col];
    int left=0,right=0,down=0;
    left=fruits[row][col]+solve2(row+1,col-1,1+moves,fruits);

    if(row+1<n && col+1<n)right=fruits[row][col]+solve2(row+1,col+1,1+moves,fruits);
    down=fruits[row][col]+solve2(row+1,col,1+moves,fruits);
    return dp[row][col]=max({down,left,right});  
}
int solve1(int row,int col,int moves,vector<vector<int>>& fruits){
    if(moves==n-1){
        if(row==n-1 && col==n-1)return 0;
        return INT_MIN;
    }
    if(row<=col)return INT_MIN;
    if(dp[row][col]!=-1) return dp[row][col];
    int up=0,right=0,down=0;
    up=fruits[row][col]+solve1(row-1,col+1,1+moves,fruits);
    if(row+1<n && col+1<n)
        down=fruits[row][col]+solve1(row+1,col+1,1+moves,fruits);
    right=fruits[row][col]+solve1(row,col+1,1+moves,fruits);

    return dp[row][col]=max({down,up,right});
    }
int maxCollectedFruits(vector<vector<int>>& fruits) {
    n=fruits.size();
    int ans=0;
    for (int i = 0; i < n; i++)
        ans+=fruits[i][i],fruits[i][i]=0;
    
    // dp[i][j] will store max fruits that can be collected from (i,j) to last cell
    memset(dp,-1,sizeof(dp));
    // for the cell present in (n-1,0);
    ans+=solve1(n-1,0,0,fruits);
    // memset(dp,-1,sizeof(dp));
    ans+=solve2(0,n-1,0,fruits);
    return ans;
    }
};