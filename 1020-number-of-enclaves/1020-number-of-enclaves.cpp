class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<int>>& grid, int delR[], int delC[]) {
        vis[row][col] = 1;
 int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < 4; i++) {
            int rrow = row + delR[i];

            int ccol = col + delC[i];

            if (rrow >= 0 && rrow < n && ccol >= 0 && ccol < m &&
                vis[rrow][ccol] == 0 && grid[rrow][ccol] == 1) {
                dfs(rrow, ccol, vis, grid, delR, delC);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delR[] = {-1, 0, 1, 0};
        int delC[] = {0, 1, 0, -1};

        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && vis[0][i] == 0) {
                dfs(0, i, vis, grid, delR, delC);
            }

            if (grid[n - 1][i] == 1 && vis[n - 1][i] == 0) {
                dfs(n - 1, i, vis, grid, delR, delC);
            }
        }

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && vis[i][0] == 0) {
                dfs(i, 0, vis, grid, delR, delC);
            }

            if (grid[i][m - 1] == 1 && vis[i][m - 1] == 0) {
                dfs(i, m - 1, vis, grid, delR, delC);
            }
        }

        int cnt = 0;
        for (int i = 0;i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};