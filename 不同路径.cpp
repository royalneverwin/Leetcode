class Solution {
public:
    //直接计算组合数会无法存储大整数
    // 动归
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 2; i <= m; i++){
            dp[i][1] = 1;
        }
        for(int j = 2; j <= n; j++){
            dp[1][j] = 1;
        }
        dp[1][1] = 1;
        for(int i = 2; i <= m; i++){
            for(int j = 2; j <= n; j++){
                // 分解成两条小路径
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];

    }
};