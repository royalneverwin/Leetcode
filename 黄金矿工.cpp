class Solution {
public:
    int ans;
    void bfs(vector<vector<int>>& grid, int cnt, int x, int y, int m, int n){
        int tmp = grid[x][y];
        cnt += tmp;
        grid[x][y] = 0;

        // 更新ans
        if(cnt > ans)
            ans = cnt;

        // 向四个方向移动
        if(x != 0 && grid[x-1][y] != 0){
            bfs(grid, cnt, x-1, y, m, n);
        }
        if(x != m-1 && grid[x+1][y] != 0){
            bfs(grid, cnt, x+1, y, m, n);
        }
        if(y != 0 && grid[x][y-1] != 0){
            bfs(grid, cnt, x, y-1, m, n);
        }
        if(y != n-1 && grid[x][y+1] != 0){
            bfs(grid, cnt, x, y+1, m, n);
        }

        // 回溯
        grid[x][y] = tmp;

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        ans = 0;

        // bfs
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0){
                    bfs(grid, 0, i, j, m, n);
                }
            }
        }

        return ans;
    }
};