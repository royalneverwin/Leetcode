class Solution {
public:
    int numDistinct(string s, string t) {
        int ls = s.length();
        int lt = t.length();
        unsigned long long dp[ls][lt]; // dp[i][j]是指从s[i]开始的string的子序列中t[j]出现的个数
        memset(dp, 0, sizeof(dp));
        if (s[ls-1] == t[lt-1])
            dp[s.length()-1][t.length()-1] = 1;

        for(int i = 2; i <= ls; i++) {
            for(int j = 1; j <= min(i, lt); j++) {
                if(s[ls-i] == t[lt-j]) {
                    if(j == 1) {
                        dp[ls-i][lt-j] = 1 + dp[ls-i+1][lt-j];
                    }
                    else {
                        dp[ls-i][lt-j] = dp[ls-i+1][lt-j+1] + dp[ls-i+1][lt-j];
                    }
                }
                else {
                    dp[ls-i][lt-j] = dp[ls-i+1][lt-j];
                }
            }
        }

        return dp[0][0];
    }
};