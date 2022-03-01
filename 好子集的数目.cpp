class Solution {
public:
#define mod 1000000007
    int SubMask(int num){ // 同时检验是否包含平方数
        int ret = 0;
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
        for(int i = 0; i < 10; i++){
            if(num % primes[i] == 0){
                ret |= (1 << i);
                num /= primes[i];
            }
            if(num % primes[i] == 0){ // 如果还能整除, 说明包含平方数
                return -1;
            }
        }
        return ret;
    }

    int numberOfGoodSubsets(vector<int>& nums) {
        /* 把1到30分成3类：
        1: 包含1和不包含1可以作为两个子集, 且1可以出现不止一次
        4, 8, 9, 12, 16, 18, 20, 24, 25, 27, 28包含平方数, 一定不会出现
        其余数只会出现一次
        难点1: 2,3,5,7,11,13,17,19,23,29十个质数, 每个乘积中每个只会出现一次, 可以用一个10bit数mask表示
        难点2: 动态规划，dp[i][mask]表示子集中包含2到i个数, 且乘积中质数出现是mask时有多少种子集 
        边界dp[1][0] = 2^numCnt[1];
        如果i是平方数, dp[i][mask] = dp[i-1][mask]
        如果i不是平方数, dp[i][mask] = dp[i-1][mask] + dp[i-1][mask/submask] + numCnt[i]
        难点3: 可以看到, 每次更新i的mask的时候都是根据i-1的更小的mask来更新, 所以用一维数组就行, mask逆序遍历
        */

        // preprocess
        vector<int> numCnt(31, 0);
        for(int i = 0; i < nums.size(); i++)
            numCnt[nums[i]]++;
        vector<long long> dp(1024, 0);

        // 创建边界条件
        dp[0] = 1;
        for(int i = 1; i <= numCnt[1]; i++)
            dp[0] = dp[0] * 2 % mod;

        // 动态规划
        for(int i = 2; i <= 30; i++){
            int submask = SubMask(i);
            if(submask != -1){ // 不包含平方数
                for(int j = 1023; j >= submask; j--){
                    if((j & submask) == submask) // 一定要做这个判断！
                        dp[j] = (dp[j] + dp[j-submask] * numCnt[i]) % mod;
                }
            }
        }

        int ans = dp[1];
        cout << dp[1] << endl;
        for(int i = 2; i <= 1023; i++){
            cout << dp[i] << endl;
            ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
};