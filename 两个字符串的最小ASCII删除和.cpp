class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // 动态规划
        int l1 = s1.length(), l2 = s2.length();
        int res = 0;

        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0)); //dp[i][j]是s1从后往前i个和s2从后往前j个
        // 边界
        dp[0][0] = 0;
        for(int i = 1; i <= l1; i++) dp[i][0] = dp[i-1][0] + s1[l1-i];
        for(int j = 1; j <= l2; j++) dp[0][j] = dp[0][j-1] + s2[l2-j];

        for(int i = 1; i <= l1; i++) // i是s1长度
            for(int j = 1; j <= l2; j++) // j是s2长度
                if(s1[l1-i] == s2[l2-j]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j-1]+s1[l1-i]+s2[l2-j], min(dp[i-1][j]+s1[l1-i], dp[i][j-1]+s2[l2-j]));
        return dp[l1][l2];
    }
};