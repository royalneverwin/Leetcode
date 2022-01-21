class Solution {
public:
#define mod 1000000007
    int countVowelPermutation(int n) {
        long left[5] = {1,1,1,1,1}; // 分别存放以a, e, i, o, u结尾的字符串的个数
        int tmp[5];
        for(int i = 2; i <= n; i++){
            // a
            tmp[0] = (left[4] + left[2] + left[1]) % mod;
            // e
            tmp[1] = (left[0] + left[2]) % mod;
            // i
            tmp[2] = (left[1] + left[3]) % mod;
            // o
            tmp[3] = left[2] % mod;
            // u
            tmp[4] = (left[2] + left[3]) % mod;
            left[0] = tmp[0];
            left[1] = tmp[1];
            left[2] = tmp[2];
            left[3] = tmp[3];
            left[4] = tmp[4];
        }
        return (left[0] + left[1] + left[2] + left[3] + left[4]) % mod;
    }
};