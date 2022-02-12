class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        long long dp[m][n]; // 用long
        memset(dp, 0, sizeof(dp));
        dp[m-1][n-1] = 1; // 从终点到终点就一种解法
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(obstacleGrid[i][j] == 1){ // 是障碍物
                    dp[i][j] = 0; // 不存在解法
                }
                else{
                    if(i != m-1){
                        dp[i][j] += dp[i+1][j]; // 向下
                    }
                    if(j != n-1){
                        dp[i][j] += dp[i][j+1]; // 向右
                    }
                }
            }
        }
        return dp[0][0];
    }
};