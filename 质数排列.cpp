class Solution {
#define MOD 1000000007
public:
    bool isPrime (int n) {
        if(n == 1)
            return false;
        for(int i = 2; i <= sqrt(n); i++)
            if(n % i == 0)
                return false;

        return true;
    }

    long long f(int n) {
        long long ret = 1;
        for(int i = 1; i <= n; i++)
            ret *= n;
        return ret;
    }

    int numPrimeArrangements(int n) {
        long long ans = 1;
        int primeCnt = 0;
        for(int i = 2; i <= n; i++) {
            if(isPrime(i)) {
                primeCnt++;
                ans *= primeCnt;
                ans %= MOD;
            }
            else {
                ans *= i - primeCnt;
                ans %= MOD;
            }
        }

        return ans % MOD;
    }
};