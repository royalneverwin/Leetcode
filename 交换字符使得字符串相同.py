class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        # 一样的 不用管
        # 不一样的 根据示例1和示例2进行交换
        # 都不行return -1
        cnt = [0, 0] # 第一个表示x, y的个数，第二个表示y, x的个数
        n = len(s1)
        for i in range(n):
            if s1[i] == 'x' and s2[i] == 'y':
                cnt[0] += 1

            elif s1[i] == 'y' and s2[i] == 'x':
                cnt[1] += 1

        res = 0
        res += cnt[0] // 2
        cnt[0] = cnt[0] % 2
        res += cnt[1] // 2
        cnt[1] = cnt[1] % 2
        if cnt[0] == cnt[1]:
            return res + 2*cnt[0]
        else:
            return -1