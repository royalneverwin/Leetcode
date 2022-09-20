// O(n^2)的时间复杂度，会超时！
// 不可以这么写（遍历每个子字符串，得到res）
class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        int res = 0;
        for(int i = 0; i < n; i++) {
            dp[i] = 1 << (s[i] - 'A');
            int prev = 1;
            int flag = 0;
            int prevAdd = 1;
            res += 1;
            for(int l = 2; l <= n-i; l++) {
                if (flag == 0x3ffffff) { // 26个英文字母都遍历完了
                    break;
                }

                else {
                    if ((dp[i] >> (s[i+l-1]-'A')) & 1) { // 已经有了
                        prevAdd = 0;
                        if (prev != 0 && !((flag >> (s[i+l-1]-'A')) & 1)) { // 还没计算过
                            flag |= (1 << (s[i+l-1]-'A'));
                            prev -= 1;// 要删掉
                        }
                    }
                    else {
                        prevAdd = 1;
                        dp[i] = dp[i] | (1 << (s[i+l-1] - 'A'));
                        prev += 1;
                    }
                }

                res += prev;
            }
        }
        return res;
    }
};


// 计算每个s[i]对res的贡献度 可以缩减到O（n)的时间复杂度
class Solution {
public:
    int uniqueLetterString(string s) {
        // 我们找到每个字符s[i]，前面与s[i]相同的idx1和后面与s[i]相同的idx2
        // 则这个字符s[i]会给左侧在idx1和i, 右侧在i和idx2的所有子字符串贡献1的uniqueCharsCnt
        // 所以贡献的所有结果即为(i - idx1) * (idx2 - i)
        // 对每个s[i]如此计算即可
        // 时间复杂度是O(n)的
        int prevIdx[26];
        int prevPrevIdx[26];
        memset(prevIdx, 0xff, sizeof(prevIdx));
        memset(prevPrevIdx, 0xff, sizeof(prevIdx));

        int n = s.length();
        int res = 0;
        for(int i = 0; i < n; i++) { // 每次计算的是prevIdx
            if(prevIdx[s[i]-'A'] == -1) { // 第一次遇到s[i]
                prevIdx[s[i]-'A'] = i;
            }
            else {
                res += (prevIdx[s[i]-'A'] - prevPrevIdx[s[i]-'A']) * (i - prevIdx[s[i]-'A']);
                prevPrevIdx[s[i]-'A'] = prevIdx[s[i]-'A'];
                prevIdx[s[i]-'A'] = i;
            }
        }
        // 最后计算所有的prevIdx
        for(int i = 0; i < 26; i++) {
            if(prevIdx[i] == -1) {
                continue;
            }
            else {
                res += (prevIdx[i] - prevPrevIdx[i]) * (n - prevIdx[i]);
            }
        }

        return res;
    }
};
