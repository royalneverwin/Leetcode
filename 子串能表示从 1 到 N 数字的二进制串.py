class Solution:
    def queryString(self, s: str, n: int) -> bool:
        cnt = 0
        flag = set()
        ls = len(s)
        for l in range(1, min(31, ls+1)): # 最多30位
            if (1 << (l-1)) > n: # 最小的都比n大 不可能成立 不用再找了
                break
            cur = 0
            for i in range(l):
                cur *= 2
                cur += int(s[i])
            if cur > 0 and cur <= n and cur not in flag: # 记录 找到了一个数
                flag.add(cur)
                cnt += 1
            for i in range(l, ls):
                cur = ((cur * 2) % (1 << l)) + int(s[i])
                if cur > 0 and cur <= n and cur not in flag: # 记录 找到了一个数
                    flag.add(cur)
                    cnt += 1
        if cnt == n:
            return True
        else:
            return False



