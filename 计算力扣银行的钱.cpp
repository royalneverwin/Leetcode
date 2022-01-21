class Solution {
public:
    // 数学问题
    int totalMoney(int n) {
        int ans = 0;
        int week = n / 7;
        ans += (1 + week) * week / 2 * 7 + 21 * week; // 算整周的钱
        n = n % 7;
        ans += (week + 1) * n + (n - 1) * n / 2; // 算最后一个（非）整周的钱
        return ans;
    }
};