class Solution {
public:
    int dfs(int n, vector<int>& dp){
        if(dp[n] != 0)
            return dp[n];
        dp[n] = dfs(n-1, dp) + dfs(n-2, dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        if(n >= 2)
            dp[2] = 2;
        return dfs(n, dp);
    }
};