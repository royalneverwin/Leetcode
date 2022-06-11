class Solution {
public:
    int findSubstringInWraproundString(string p) {
        // 动态规划
        // 计算以字母i为结尾的公共子串的最大值
        // 因为长度小于最大值的公共子串一定被最长的公共子串的子串包含
        vector<int> dp(26, 0);
        char curC = p[0];
        int cnt = 1;
        dp[curC - 'a'] = max(dp[curC - 'a'], cnt);

        for(int i = 1; i < p.length(); i++){
            if((curC == 'z' && p[i] == 'a') || p[i] == curC + 1){
                cnt++;
                curC = p[i];
                dp[curC - 'a'] = max(dp[curC - 'a'], cnt);
            }
            else{
                curC = p[i];
                cnt = 1;
                dp[curC - 'a'] = max(dp[curC - 'a'], cnt);
            }
        }


        int ans = 0;
        for(int i = 0; i < 26; i++)
            ans += dp[i];

        return ans;
    }
};