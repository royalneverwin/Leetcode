class Solution {
public:
    // 动态规划
    bool isScramble(string s1, string s2) {
        if(s1 == s2) {
            return true;
        }

        if(s1.length() != s2.length()) {
            return false;
        }

        int n = s1.length();
        int memo[26] = {0};

        for(int i = 0; i < n; i++) {
            memo[s1[i] - 'a']++;
            memo[s2[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++)
            if(memo[i] != 0) {
                return false;
            }

        bool dp[n][n][n+1]; // s1.begin, s2.begin, length
        memset(dp, 0, sizeof(dp));

        // 初始化dp
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(s1[i] == s2[j])
                    dp[i][j][1] = true;
                else
                    dp[i][j][1] = false;
            }
        }

        // dp
        for(int i=2; i<=n; i++) { // length
            for(int j=0; j <= n-i; j++) { // s1.begin()
                for(int k=0; k <= n-i; k++) { // s2.begin()
                    for(int l = 1; l < i; l++) { // subLength
                        if((dp[j][k][l] && dp[j+l][k+l][i-l]) || (dp[j][k+i-l][l] && dp[j+l][k][i-l])) {
                            dp[j][k][i] = true;
                            break;
                        }
                    }
                }
            }
        }

        return dp[0][0][n];
    }
};