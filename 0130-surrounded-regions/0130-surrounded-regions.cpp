class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& board,int delRow[],int delCol[]){
    int n=board.size(),m=board[0].size();
    vis[row][col]=1;
    for (int i = 0; i < 4; i++)
    {
        int nrow=row+delRow[i],ncol = col+delCol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
            dfs(nrow,ncol,vis,board,delRow,delCol);
        }
    }
}
void solve(vector<vector<char>>& board) {
     int n=board.size(),m=board[0].size();
     vector<vector<int>>vis(n,vector<int>(m,0));
    /*
    LOGIC
    traverse all the boundary and whenever 0 is found mark them as visited alongwith all their neighbouring connected 0s.
    After that, all the remaining 0 left must be in surrounded region so convert them to X
    */ 
//    first row and last row
int delRow[]={-1,0,1,0},delCol[]={0,1,0,-1};
for (int i = 0; i <m; i++){
    if(board[0][i]=='O' && !vis[0][i]){
        dfs(0,i,vis,board,delRow,delCol);
    }

    if(board[n-1][i]=='O' && !vis[n-1][i]){
        dfs(n-1,i,vis,board,delRow,delCol);
    }
}
// first and last col
for (int i = 0; i <m; i++){
    if(board[i][0]=='O' && !vis[i][0]){
        dfs(i,0,vis,board,delRow,delCol);
    }

    if(board[i][m-1]=='O' && !vis[i][m-1]){
        dfs(i,m-1,vis,board,delRow,delCol);
    }
}
for (int i = 0; i < n; i++)
{
   for (int j = 0; j < m; j++)
   {
    if(!vis[i][j] && board[i][j]=='O') board[i][j]='X';
   }
}
return;
    }
};