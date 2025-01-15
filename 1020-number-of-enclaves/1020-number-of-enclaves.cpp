class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&vis,int delrow[],int delcol[]){
    vis[row][col]=1;
    int n=grid.size(),m=grid[0].size();
    for (int i = 0; i <4; i++)
    {
        int nrow=row+delrow[i],ncol=col+delcol[i];
        if(nrow>=0 && row<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
            dfs(nrow,ncol,grid,vis,delrow,delcol);
        } 
    }   
}
int numEnclaves(vector<vector<int>>& grid) {
    /*
    LOGIC = Traverse all boundary and mark all 1s including their neighbours present as visited using dfs, then traverse whole grid and count all unvisited 1s and return.
    */
    int n=grid.size(),m=grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    int delrow[]={-1,0,1,0},delcol[]={0,1,0,-1};

    // traverse first and last row
    for (int j = 0; j < m; j++)
    {
        if(vis[0][j]==0 && grid[0][j]==1){
            dfs(0,j,grid,vis,delrow,delcol);
        }
        if(vis[n-1][j]==0 && grid[n-1][j]==1){
            dfs(n-1,j,grid,vis,delrow,delcol);
        }
    }
    // traverse first and last col
    for (int i = 0; i < n; i++)
    {
        if(vis[i][0]==0 && grid[i][0]==1){
            dfs(i,0,grid,vis,delrow,delcol);
        }

        if(vis[i][m-1]==0 && grid[i][m-1]==1){
            dfs(i,m-1,grid,vis,delrow,delcol);
        }
    }
    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j< m; j++)
        {
            if(vis[i][j]==0 && grid[i][j]==1)cnt++;
        }
        
    }
    return cnt;
}
};