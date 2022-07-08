class Solution {
public:
    // aa ab aaba 
    // 动态规划
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length())
            return false;
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        int dp[l1+1][l2+1]; //dp[i][j]表示s1的倒数i个开始和s2的倒数j个开始可以组成s3的倒数i+j个
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int l = 1; l <= l3; l++) {
            for(int i = max(0, l - l2); i <= min(l, l1); i++) { // s1中的几个
                if(i == 0) {
                    if(s2[l2-l] == s3[l3-l]) {
                        dp[0][l] = dp[0][l-1];
                    }
                    else {
                        dp[0][l] = 0;
                    }
                }
                else if(i == l) {
                    if(s1[l1-l] == s3[l3-l]) {
                        dp[l][0] = dp[l-1][0];
                    }
                    else {
                        dp[l][0] = 0;
                    }
                }
                else {
                    if(s1[l1-i] == s3[l3-l] && s2[l2-l+i] == s3[l3-l]) {
                        dp[i][l-i] = dp[i-1][l-i] | dp[i][l-i-1];
                    }
                    else if(s1[l1-i] == s3[l3-l]) {
                        dp[i][l-i] = dp[i-1][l-i];
                    }
                    else if(s2[l2-l+i] == s3[l3-l]) {
                        dp[i][l-i] = dp[i][l-i-1];
                    }
                    else {
                        dp[i][l-i] = 0;
                    }
                }
            }
        }

        return dp[l1][l2];
    }
};