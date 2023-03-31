class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        // 枚举就完事了
        // 先枚举轮转可能 再枚举每个位置数字+a的可能
        // 轮转最多有 n-1 次
        // +a 最多有9次
        // 如果直接动s 太麻烦了 所以选择将s = s+s 便于直接截取rotation后的部分 (很妙的方法！)
        // 快速判断rotate是否重复，直接算s[0]的下标变化就行
        // 注意每次a是同时加到所有下标为奇数的元素上
        int n = s.length();
        int addTimes = 9;
        vector<bool> visited = vector<bool>(n, true);
        string res = s;
        s = s+s;
        for(int i = 0; visited[i]; i=(i+b)%n) {
            visited[i] = false;
            for(int j = 0; j <= addTimes; j++) {
                int addTimesForEven = b%2==0?0:9;
                for(int k = 0; k <= addTimesForEven; k++) {
                    string cur_s = s.substr(i, n);
                    for(int idx1=0; idx1 < n; idx1 += 2) {
                        cur_s[idx1] = '0' + (cur_s[idx1]-'0'+k*a) % 10;
                    }
                    for(int idx2=1; idx2 < n; idx2 += 2) {
                        cur_s[idx2] = '0' + (cur_s[idx2]-'0'+j*a) % 10;
                    }
                    res = min(res, cur_s);
                }
            }
        }
        return res;
    }
};