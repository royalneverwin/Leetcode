class Solution {
public:
    // 数学方法, 计算每一位1的个数
    // 若left < pow(10, i-1), 0个
    // 若left >= pow(10, i-1) && left < pow(10, i-1) * 2 left - pow(10, i-1) + 1个
    // 若left >= pow(10, i-1) * 2, pow(10, i-1)个
    int countDigitOne(int n) {
        int ans = 0;
        for(int i = 1; i <= 9; i++){
            int base = (int)pow(10, i-1);
            int perCnt = base;
            int num = n / (base * 10);
            int left = n % (base * 10);
            ans += (perCnt * num +  min(max(left - base + 1, 0), base));
        }
        if(n == 1000000000)
            ans += 1;
        return ans;
    }
};