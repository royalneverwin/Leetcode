class Solution {
public:
    int minCost(vector<vector<int>>& costs) { // 0: red, 1: blue, 2: green
        int l = costs.size();
        vector<vector<int>> dp(l, vector<int>(3, 0));
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];

        for(int i = 1; i < l; i++) {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i][2];
        }

        return min(dp[l-1][0], min(dp[l-1][1], dp[l-1][2]));
    }
};