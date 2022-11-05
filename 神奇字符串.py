class Solution:
    def magicalString(self, n: int) -> int:
        s = [0 for i in range(n)]
        s[0] = 1
        idx1, idx2, cur, res, cnt =0, 1, 1, 1, 1
        while idx2 < n:
            if cnt == s[idx1]:
                idx1 += 1
                if cur == 1:
                    s[idx2] = 2
                    cur = 2
                else:
                    s[idx2] = 1
                    res += 1
                    cur = 1
                cnt = 1
                idx2 += 1
            else:
                cnt += 1
                if cur == 1:
                    s[idx2] = 1
                    res += 1
                else:
                    s[idx2] = 2
                idx2 += 1
        return res



