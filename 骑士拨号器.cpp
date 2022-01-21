class Solution {
public:
#define mod 1000000007
    int knightDialer(int n) {
        long cnt[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        long tmp[10];
        for(int i = 2; i <= n; i++){
            tmp[0] = (cnt[4] + cnt[6]) % mod;
            tmp[1] = (cnt[6] + cnt[8]) % mod;;
            tmp[2] = (cnt[7] + cnt[9]) % mod;
            tmp[3] = (cnt[4] + cnt[8]) % mod;
            tmp[4] = (cnt[3] + cnt[9] + cnt[0]) % mod;
            tmp[5] = 0;
            tmp[6] = (cnt[1] + cnt[7] + cnt[0]) % mod;
            tmp[7] = (cnt[2] + cnt[6]) % mod;
            tmp[8] = (cnt[1] + cnt[3]) % mod;
            tmp[9] = (cnt[2] + cnt[4]) % mod;
            for(int i = 0; i < 10; i++)
                cnt[i] = tmp[i];
        }
        return (cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9]) % mod;
    }
};