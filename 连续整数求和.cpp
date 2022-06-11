class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(i % 2 != 0) {
                if(n % i == 0) {
                    if((n / i) - (i / 2) >= 1)
                        ans++;
                    else
                        return ans;
                }
            }
            else {
                if(n % i == (i / 2)) {
                    if((n / i) - (i / 2) + 1 >= 1)
                        ans++;
                    else
                        return ans;
                }
            }
        }
        return ans;
    }
};