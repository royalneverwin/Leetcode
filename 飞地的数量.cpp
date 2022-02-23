class Solution {
public:
    void bfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& flag, int m, int n){
        flag[x][y] = true;
        if(x != 0 && grid[x-1][y] && !flag[x-1][y]){
            bfs(x-1, y, grid, flag, m, n);
        }
        if(x != m-1 && grid[x+1][y] && !flag[x+1][y]){
            bfs(x+1, y, grid, flag, m, n);
        }
        if(y != 0 && grid[x][y-1] && !flag[x][y-1]){
            bfs(x, y-1, grid, flag, m, n);
        }
        if(y != n-1 && grid[x][y+1] && !flag[x][y+1]){
            bfs(x, y+1, grid, flag, m, n);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> flag(m, vector<bool>(n, false));
        // 对所有边界的1标记并bfs
        for(int j = 0; j < n; j++){
            if(grid[0][j] && !flag[0][j]){
                bfs(0, j, grid, flag, m, n);
            }
            if(grid[m-1][j] && !flag[m-1][j]){
                bfs(m-1, j, grid, flag, m, n);
            }
        }
        for(int i = 0; i < m; i++){
            if(grid[i][0] && !flag[i][0]){
                bfs(i, 0, grid, flag, m, n);
            }
            if(grid[i][n-1] && !flag[i][n-1]){
                bfs(i, n-1, grid, flag, m, n);
            }
        }
        // 所有没被标记的就是所求点
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] && !flag[i][j])
                    ans++;
            }
        }
        return ans;
    }
};