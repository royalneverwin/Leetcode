class Solution {
public:
    // 动归
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        // dp[i][j]表示从word1前i个变换到word2前i个最少操作数
        //dp[i][j]取决于：dp[i][j-1], dp[i-1][j], dp[i-1][j-1]
        dp[0][0] = 0;
        for(int i = 1; i <= l1; i++){
            dp[i][0] = i;
        }
        for(int j = 1; j <= l2; j++){
            dp[0][j] = j;
        }

        for(int i = 1; i <= l1; i++){
            for(int j = 1; j <= l2; j++){
                int cnt = min(dp[i][j-1] + 1, dp[i-1][j] + 1);
                if(word1[i-1] == word2[j-1]){
                    cnt = min(cnt, dp[i-1][j-1]);
                }
                else{
                    cnt = min(cnt, dp[i-1][j-1] + 1);
                }
                dp[i][j] = cnt;
            }
        }
        return dp[l1][l2];
    }
};