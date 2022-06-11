class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int l = s.length();

        if(l == 1)
            return 0;

        int dp1, dp0;

        dp0 = s[0] - '0';
        dp1 = !dp0;

        for(int i = 1; i < l; i++) {
            int new0 = dp0, new1 = min(dp0, dp1);
            if(s[i] == '0') {
                new1++;
            }
            else {
                new0++;
            }
            dp0 = new0;
            dp1 = new1;
        }

        return min(dp0, dp1);

    }
};



class Solution {
public:
    int minFlipsMonoIncr(string s) {

        if(s.length() == 1)
            return 0;

        int cntFor1 = s[0] - '0';
        vector<int> dp(s.length(), 0);

        int preAns = 0;
        for(size_t i = 1; i < s.length(); i++) {
            if(s[i] == '0'){
                if(cntFor1 != 0) {
                    if(dp[i-1] + 1 >= cntFor1 + preAns) { // 0变1代价太大了 全变成0
                        dp[i] = cntFor1 + preAns;
                        preAns += cntFor1;
                        cntFor1 = 0;
                    }
                    else {
                        dp[i] = dp[i-1] + 1;
                    }
                }
                else {
                    dp[i] = dp[i-1];
                }
            }
            else {
                dp[i] = dp[i-1];
                cntFor1++;
            }
        }

        return dp[s.length()-1];

    }
};