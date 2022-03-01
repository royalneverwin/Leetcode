class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp, int m, int n){
        if(dp[r][c] != -2)
            return dp[r][c];

        if(grid[r][c] == -1){
            if(c == 0) // 到边界
                dp[r][c] =  -1;
            else if(grid[r][c-1] == 1) // 形成V字形
                dp[r][c] = -1;
            else if(r == m-1)
                dp[r][c] = c-1;
            else
                dp[r][c] = dfs(r+1, c-1, grid, dp, m, n);
        }
        else{
            if(c == n-1) // 到边界
                dp[r][c] = -1;
            else if(grid[r][c+1] == -1) // 形成V字形
                dp[r][c] = -1;
            else if(r == m-1)
                dp[r][c] = c+1;
            else
                dp[r][c] = dfs(r+1, c+1, grid, dp, m, n);
        }
        return dp[r][c];
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -2)); // -2 表示还没计算, -1表示卡住, i表示从第i列出
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            ans[i] = dfs(0, i, grid, dp, m, n);
        }
        return ans;
    }
};