class Solution {
public:
    // 数学方法
    // 约瑟夫问题
    int findTheWinner(int n, int k) {
        vector<int> f(n, 0);
        f[0] = 0;
        for(int i = 1; i < n; i++){
            f[i] = (f[i-1] + k % (i+1)) % (i+1);
        }

        return f[n-1] + 1;
    }
};