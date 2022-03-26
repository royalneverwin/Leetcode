class Solution {
public:
    int trailingZeroes(int n) {
        int ans = n / 5;
        int for25 = n / 25;
        int for125 = n / 125;
        int for625 = n / 625;
        int for3125 = n / 3125;
        ans = ans + for25 + for125 + for625 + for3125;
        return ans;
    }
};