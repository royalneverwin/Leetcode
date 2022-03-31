class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> dp(k+1, 0); // 前i个取j次硬币最大和
        vector<int> cur(k+1, 0);

        int n = piles[0].size();
        int maxN = min(k, n);
        // 初始化dp
        dp[0] = 0;
        for(int i = 0; i < maxN; i++){
            dp[i+1] = piles[0][i] + dp[i];
        }

        for(int i = 1; i < piles.size(); i++){
            // 构造cur
            cur[0] = 0;
            n = piles[i].size();
            for(int j = 0; j < min(k, n); j++){
                cur[j+1] = piles[i][j] + cur[j];
            }

            maxN = min(k, maxN + n);
            // 构造new dp
            for(int j = maxN; j >= 0; j--){
                int tmp = 0;
                for(int l = 0; l <= min(j, n); l++){
                    tmp = max(tmp, cur[l] + dp[j-l]);
                }
                dp[j] = tmp;
            }
        }

        return dp[k];
    }
};