#define MOD 1000000007;
class Solution {
public:
    // 动归：若s[i] = s[j] = a, 则s[a, i, j] = sum(s[i+1, j-1]) + 2
    // 若s[i] = a && s[j] != a, 则s[a, i, j] = s[a, i, j-1];
    // 若s[i] != a && s[j] = a, 则s[a, i, j] = s[a, i+1, j];
    // 若s[i] != a && s[j] != a, 则s[a, i, j] = s[a, i+1, j-1];

    // 若i = j, s[a, i, j] = (s[i] == a)
    // 若i > j, s[a, i, j] = 0
    int countPalindromicSubsequences(string s) { // s只有a b c d
        size_t l = s.length();
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(l, vector<int>(l, 0)));
        for(size_t i = 0; i < l; i++) { // 边界
            dp[s[i] - 'a'][i][i] = 1;
        }

        for(size_t len = 2; len <= l; len++) {
            for(size_t i = 0, j = len - 1; j < l; i++, j++) {
                for(char c = 'a'; c <= 'd'; c++) {
                    if(s[i] == c && s[j] == c) {
                        dp[c-'a'][i][j] = (2L + dp[0][i+1][j-1] + dp[1][i+1][j-1] + dp[2][i+1][j-1] + dp[3][i+1][j-1]) % MOD;
                    }
                    else if(s[i] == c) {
                        dp[c-'a'][i][j] = dp[c-'a'][i][j-1];
                    }
                    else if(s[j] == c) {
                        dp[c-'a'][i][j] = dp[c-'a'][i+1][j];
                    }
                    else {
                        dp[c-'a'][i][j] = dp[c-'a'][i+1][j-1];
                    }

                }
            }
        }
        return (0L + dp[0][0][l-1] + dp[1][0][l-1] + dp[2][0][l-1] + dp[3][0][l-1]) % MOD;

    }
};