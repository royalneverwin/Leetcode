class Solution {
public:
    // dp[i][j][k]指[i,j]跳k步留在棋盘上的概率
    double dfs(int n, int k, int r, int c, vector<vector<vector<double>>>& dp){
        if(dp[r][c][k] != 0)
            return dp[r][c][k];
        if(k == 0){
            dp[r][c][k] = 1;
            return 1.0;
        }
        double ret = 0;
        if(r-1 >= 0 && c-2 >= 0){
            ret += 0.125 * dfs(n, k-1, r-1, c-2, dp);
        }
        if(r-2 >= 0 && c-1 >= 0){
            ret += 0.125 * dfs(n, k-1, r-2, c-1, dp);
        }
        if(r+1 < n && c-2 >= 0){
            ret += 0.125 * dfs(n, k-1, r+1, c-2, dp);
        }
        if(r+2 < n && c-1 >= 0){
            ret += 0.125 * dfs(n, k-1, r+2, c-1, dp);
        }
        if(r+1 < n && c+2 < n){
            ret += 0.125 * dfs(n, k-1, r+1, c+2, dp);
        }
        if(r+2 < n && c+1 < n){
            ret += 0.125 * dfs(n, k-1, r+2, c+1, dp);
        }
        if(r-1 >= 0 && c+2 < n){
            ret += 0.125 * dfs(n, k-1, r-1, c+2, dp);
        }
        if(r-2 >= 0 && c+1 < n){
            ret += 0.125 * dfs(n, k-1, r-2, c+1, dp);
        }
        dp[r][c][k] = ret;
        return ret;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k+1, 0)));
        return dfs(n, k, row, column, dp);
    }
};