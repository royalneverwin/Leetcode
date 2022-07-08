class Solution {
public:
    int dp[20];
    int numSubTrees(int l) {
        if(dp[l] != 0)
            return dp[l];
        int ret = 0;
        for(int i = 1; i <= l; i++) {
            ret += numSubTrees(i-1) * numSubTrees(l-i);
        }
        dp[l] = ret;
        return ret;
    }

    int numTrees(int n) {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        return numSubTrees(n);
    }
};