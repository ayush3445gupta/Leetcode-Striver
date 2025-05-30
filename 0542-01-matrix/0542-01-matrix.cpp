class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>res(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <m; j++)
            {
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                vis[i][j]=1;
                }
            }
            
        }
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
    while (!q.empty())
    {
        int row=q.front().first.first;
        int col = q.front().first.second;
        int steps=q.front().second;
        q.pop();
        res[row][col]=steps;
        
        bool isZero=false;
        for (int i = 0; i < 4; i++)
        {
            int nrow=row+delRow[i],ncol=col+delCol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]==1 && !vis[nrow][ncol]){
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol},steps+1});
            }
        }
    }
    return res;
    }
};