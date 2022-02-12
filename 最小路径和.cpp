class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n]; // 用long
        memset(dp, 0, sizeof(dp));
        dp[m-1][n-1] = grid[m-1][n-1]; // 从终点到终点就一种解法
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1){
                    continue;
                }
                if(i == m-1){
                    dp[i][j] = dp[i][j+1] + grid[i][j]; // 向下
                }
                else if(j == n-1){
                    dp[i][j] = dp[i+1][j] + grid[i][j]; // 向右
                }
                else{
                    dp[i][j] = min(dp[i][j+1], dp[i+1][j]) + grid[i][j];
                }
            }
        }
        return dp[0][0];
    }
};