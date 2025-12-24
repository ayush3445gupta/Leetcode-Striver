class Solution {
public:
int m,n,total_free_space;
int count_obstacles(vector<vector<int>>&grid){
    int obs=0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
           if(grid[i][j]==-1)obs++;
        }
    }
    return obs;
}
pair<int,int>hover_to_starting_point(vector<vector<int>>& grid){
    for (int i = 0; i < m; i++)
    {
       for (int j = 0; j < n; j++)
       {
        if(grid[i][j]==1)return {i,j};
       }
    }
    return {-1,-1};
} 
int solve(int row,int col,vector<vector<bool>>&vis,vector<vector<int>>&grid,int curr_free_space){
    if(grid[row][col]==2)
        return curr_free_space==total_free_space;
    if(grid[row][col]==-1)return 0;

    vis[row][col]=1;
    curr_free_space++;
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};

    int ans=0;
    for (int i = 0; i < 4; i++)
    {
        int nr=row+dr[i],nc=col+dc[i];
        if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc])ans+=solve(nr,nc,vis,grid,curr_free_space);
    }
    vis[row][col]=0;
    curr_free_space--;
    return ans;
}
int uniquePathsIII(vector<vector<int>>& grid) {
    m=grid.size(),n=grid[0].size();
    // hover to the starting point
    auto p=hover_to_starting_point(grid);
    int start_row=p.first,start_col=p.second;
    total_free_space=n*m-(count_obstacles(grid)+1);
    vector<vector<bool>>vis(m,vector<bool>(n,0));
    return solve(start_row,start_col,vis,grid,0);
    }
};