class Solution:
    def numDupDigitsAtMostN(self, n: int) -> int:
        # 算都不相同的数字的个数即可
        n = str(n)
        l = len(n)
        # 长度<=l-1的都不相同的数的个数为
        def Count(l): # 计算长度为l的都不相同的数的个数
            ret = 9
            l -= 1
            left = 9
            while l > 0:
                ret *= left
                l -= 1
                left -= 1
            return ret

        cnt = 0
        for i in range(1, l):
            cnt += Count(i)

        # 再计算长度 = l 且 <= n的都不相同的数的个数
        idx = 0
        flag = [0 for i in range(10)]
        while idx < l:
            # 计算第idx位小于n[idx]的数
            if idx == 0:
                cur_cnt = int(n[idx]) - 1
            else:
                cur_cnt = 0
                for i in range(int(n[idx])): # 计算可以使用的剩下的数的个数
                    if flag[i] == 0:
                        cur_cnt += 1

            cur_l = l - idx
            cur_l -= 1
            left = 9 - idx
            if cur_cnt > 0:
                while cur_l > 0:
                    cur_cnt *= left
                    cur_l -= 1
                    left -= 1
            cnt += cur_cnt
            # 接下来计算idx位 = n[idx]的数
            if flag[int(n[idx])] == 1: # 接下来就不用算了 肯定都不是的
                break
            else:
                flag[int(n[idx])] = 1
            idx += 1
            # 最后计算n
        if  len(set(n)) == len(n):
            cnt += 1
        return int(n) - cnt