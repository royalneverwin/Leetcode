class Solution:
    def balancedString(self, s: str) -> int:
        cnt = {'Q': 0, 'W': 0, 'E': 0, 'R': 0}
        n = len(s)
        idx1, idx2 = 0, 0
        for i in range(n):
            cnt[s[i]] += 1
        res = n+1
        while True:
            while (cnt['Q'] > n//4 or cnt['W'] > n//4 \
                   or cnt['E'] > n//4 or cnt['R'] > n//4) and idx2 < n:
                cnt[s[idx2]] -= 1
                idx2 += 1
            if cnt['Q'] <= n//4 and cnt['W'] <= n//4 \
                    and cnt['E'] <= n//4 and cnt['R'] <= n//4:
                res = min(res, idx2-idx1)
            else:
                break
            if res == 0:
                break
            cnt[s[idx1]] += 1
            idx1 += 1

        return res

